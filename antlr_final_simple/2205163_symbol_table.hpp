#ifndef SYMBOL_TABLE_2205163_HPP
#define SYMBOL_TABLE_2205163_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NUM_BUCKETS = 30;

inline int hashOf(const string& name) {
    unsigned long sum = 0;
    for (char c : name) {
        sum += (unsigned char)c;
    }
    return (int)(sum % NUM_BUCKETS);
}

class SymbolInfo {
private:
    string name;
    string type;
    SymbolInfo* next;

    // Extra information needed for Assignment 3.
    string dataType;                 // int / float / void
    bool arraySymbol;

    bool functionSymbol;
    bool definedFunction;
    string returnType;
    vector<string> parameterTypes;

public:
    SymbolInfo(string name = "", string type = "") {
        this->name = name;
        this->type = type;
        next = nullptr;

        dataType = "error";
        arraySymbol = false;

        functionSymbol = false;
        definedFunction = false;
        returnType = "error";
    }

    string getName() const { return name; }
    string getType() const { return type; }
    SymbolInfo* getNext() const { return next; }

    void setName(string value) { name = value; }
    void setType(string value) { type = value; }
    void setNext(SymbolInfo* value) { next = value; }

    string getDataType() const { return dataType; }
    void setDataType(string value) { dataType = value; }

    bool isArray() const { return arraySymbol; }
    void setArray(bool value) { arraySymbol = value; }

    bool isFunction() const { return functionSymbol; }
    void setFunction(bool value) { functionSymbol = value; }

    bool isDefinedFunction() const { return definedFunction; }
    void setDefinedFunction(bool value) { definedFunction = value; }

    string getReturnType() const { return returnType; }
    void setReturnType(string value) { returnType = value; }

    vector<string> getParameterTypes() const { return parameterTypes; }
    void setParameterTypes(vector<string> value) { parameterTypes = value; }
};

class ScopeTable {
private:
    SymbolInfo* table[NUM_BUCKETS];
    ScopeTable* parentScope;
    string id;
    int nextChild;

public:
    ScopeTable(string id, ScopeTable* parentScope) {
        this->id = id;
        this->parentScope = parentScope;
        nextChild = 1;

        for (int i = 0; i < NUM_BUCKETS; i++) {
            table[i] = nullptr;
        }
    }

    ~ScopeTable() {
        for (int i = 0; i < NUM_BUCKETS; i++) {
            SymbolInfo* current = table[i];
            while (current != nullptr) {
                SymbolInfo* temp = current;
                current = current->getNext();
                delete temp;
            }
        }
    }

    ScopeTable* getParentScope() const { return parentScope; }
    string getId() const { return id; }

    string nextChildId() {
        string childId = id + "." + to_string(nextChild);
        nextChild++;
        return childId;
    }

    bool insert(string name, string type) {
        int index = hashOf(name);

        SymbolInfo* current = table[index];
        SymbolInfo* previous = nullptr;

        while (current != nullptr) {
            if (current->getName() == name) {
                return false;
            }
            previous = current;
            current = current->getNext();
        }

        SymbolInfo* symbol = new SymbolInfo(name, type);

        if (previous == nullptr) {
            table[index] = symbol;
        } else {
            previous->setNext(symbol);
        }

        return true;
    }

    SymbolInfo* lookUp(string name) const {
        int index = hashOf(name);
        SymbolInfo* current = table[index];

        while (current != nullptr) {
            if (current->getName() == name) {
                return current;
            }
            current = current->getNext();
        }

        return nullptr;
    }

    void print(ostream& out) const {
        out << "ScopeTable # " << id << "\n";

        for (int i = 0; i < NUM_BUCKETS; i++) {
            if (table[i] == nullptr) {
                continue;
            }

            out << " " << i << " -->";

            SymbolInfo* current = table[i];
            SymbolInfo* last = nullptr;

            while (current != nullptr) {
                out << " < " << current->getName()
                    << " , " << current->getType() << " >";
                last = current;
                current = current->getNext();
            }

            // This small spacing detail is required by the supplied logs.
            if (last != nullptr && !last->isFunction()) {
                out << " ";
            }

            out << "\n";
        }

        out << "\n\n";
    }
};

class SymbolTable {
private:
    ScopeTable* currentScope;

public:
    SymbolTable() {
        currentScope = nullptr;
    }

    ~SymbolTable() {
        while (currentScope != nullptr) {
            ScopeTable* parent = currentScope->getParentScope();
            delete currentScope;
            currentScope = parent;
        }
    }

    void enterScope() {
        string id;

        if (currentScope == nullptr) {
            id = "1";
        } else {
            id = currentScope->nextChildId();
        }

        currentScope = new ScopeTable(id, currentScope);
    }

    void exitScope() {
        if (currentScope == nullptr || currentScope->getParentScope() == nullptr) {
            return;
        }

        ScopeTable* old = currentScope;
        currentScope = currentScope->getParentScope();
        delete old;
    }

    bool insert(string name, string type) {
        if (currentScope == nullptr) {
            return false;
        }
        return currentScope->insert(name, type);
    }

    SymbolInfo* lookUpCurrent(string name) const {
        if (currentScope == nullptr) {
            return nullptr;
        }
        return currentScope->lookUp(name);
    }

    SymbolInfo* lookUp(string name) const {
        ScopeTable* scope = currentScope;

        while (scope != nullptr) {
            SymbolInfo* found = scope->lookUp(name);
            if (found != nullptr) {
                return found;
            }
            scope = scope->getParentScope();
        }

        return nullptr;
    }

    SymbolInfo* insertAndGet(string name, string type) {
        if (!insert(name, type)) {
            return nullptr;
        }
        return lookUpCurrent(name);
    }

    void printAll(ostream& out) const {
        ScopeTable* scope = currentScope;

        while (scope != nullptr) {
            scope->print(out);
            scope = scope->getParentScope();

            // The reference logs have one extra blank line between scopes.
            if (scope != nullptr) {
                out << "\n";
            }
        }
    }
};

#endif
