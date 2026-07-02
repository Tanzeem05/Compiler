#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SymbolInfo {
private:
    string name;
    string type;
    SymbolInfo* next;

public:
    SymbolInfo() {
        name = "";
        type = "";
        next = 0;
    }

    SymbolInfo(string name, string type) {
        this->name = name;
        this->type = type;
        next = 0;
    }

    void setName(string name) {
        this->name = name;
    }

    void setType(string type) {
        this->type = type;
    }

    void setNext(SymbolInfo* next) {
        this->next = next;
    }

    string getName() const {
        return name;
    }

    string getType() const {
        return type;
    }

    SymbolInfo* getNext() const {
        return next;
    }
};

class ScopeTable {
private:
    int bucketCount;
    int scopeId;
    SymbolInfo** table;
    ScopeTable* parentScope;

    unsigned int SDBMHash(string str) const {
        unsigned int hash = 0;
        unsigned int len = (unsigned int)str.length();

        for (unsigned int i = 0; i < len; i++) {
            hash = ((str[i]) + (hash << 6) + (hash << 16) - hash) % bucketCount;
        }

        return hash;
    }

    void printTabs(ostream& out, int count) const {
        for (int i = 0; i < count; i++) {
            out << "\t";
        }
    }

public:
    ScopeTable(int bucketCount, int scopeId, ScopeTable* parentScope) {
        if (bucketCount <= 0) {
            bucketCount = 1;
        }

        this->bucketCount = bucketCount;
        this->scopeId = scopeId;
        this->parentScope = parentScope;

        table = new SymbolInfo*[bucketCount];

        for (int i = 0; i < bucketCount; i++) {
            table[i] = 0;
        }
    }

    ~ScopeTable() {
        for (int i = 0; i < bucketCount; i++) {
            SymbolInfo* current = table[i];

            while (current != 0) {
                SymbolInfo* temp = current;
                current = current->getNext();
                delete temp;
            }
        }

        delete[] table;
    }

    int getScopeId() const {
        return scopeId;
    }

    ScopeTable* getParentScope() const {
        return parentScope;
    }

    bool Insert(string name, string type, int& bucketNo, int& chainPos) {
        int index = (int)SDBMHash(name);
        bucketNo = index + 1;
        chainPos = 1;

        SymbolInfo* current = table[index];
        SymbolInfo* previous = 0;

        while (current != 0) {
            if (current->getName() == name) {
                return false;
            }

            previous = current;
            current = current->getNext();
            chainPos++;
        }

        SymbolInfo* newSymbol = new SymbolInfo(name, type);

        if (previous == 0) {
            table[index] = newSymbol;
        } else {
            previous->setNext(newSymbol);
        }

        return true;
    }

    SymbolInfo* LookUp(string name, int& bucketNo, int& chainPos) const {
        int index = (int)SDBMHash(name);
        bucketNo = index + 1;
        chainPos = 1;

        SymbolInfo* current = table[index];

        while (current != 0) {
            if (current->getName() == name) {
                return current;
            }

            current = current->getNext();
            chainPos++;
        }

        return 0;
    }

    bool Delete(string name, int& bucketNo, int& chainPos) {
        int index = (int)SDBMHash(name);
        bucketNo = index + 1;
        chainPos = 1;

        SymbolInfo* current = table[index];
        SymbolInfo* previous = 0;

        while (current != 0) {
            if (current->getName() == name) {
                if (previous == 0) {
                    table[index] = current->getNext();
                } else {
                    previous->setNext(current->getNext());
                }

                delete current;
                return true;
            }

            previous = current;
            current = current->getNext();
            chainPos++;
        }

        return false;
    }

    void Print(ostream& out, int indentLevel) const {
        printTabs(out, indentLevel);
        out << "ScopeTable# " << scopeId << "\n";

        for (int i = 0; i < bucketCount; i++) {
            printTabs(out, indentLevel);
            out << (i + 1) << "--> ";

            SymbolInfo* current = table[i];

            while (current != 0) {
                out << "<" << current->getName() << "," << current->getType() << "> ";
                current = current->getNext();
            }

            out << "\n";
        }
    }
};

class SymbolTable {
private:
    ScopeTable* currentScope;
    int bucketCount;
    int nextScopeId;

public:
    SymbolTable(int bucketCount) {
        if (bucketCount <= 0) {
            bucketCount = 1;
        }

        this->bucketCount = bucketCount;
        currentScope = 0;
        nextScopeId = 1;
    }

    ~SymbolTable() {
        while (currentScope != 0) {
            ScopeTable* parent = currentScope->getParentScope();
            delete currentScope;
            currentScope = parent;
        }
    }

    int EnterScope() {
        ScopeTable* newScope = new ScopeTable(bucketCount, nextScopeId, currentScope);
        currentScope = newScope;
        nextScopeId++;
        return currentScope->getScopeId();
    }

    bool canExitCurrentScope() const {
        if (currentScope == 0) {
            return false;
        }

        if (currentScope->getParentScope() == 0) {
            return false;
        }

        return true;
    }

    bool ExitScope(int& removedScopeId) {
        if (!canExitCurrentScope()) {
            return false;
        }

        ScopeTable* oldScope = currentScope;
        removedScopeId = oldScope->getScopeId();
        currentScope = currentScope->getParentScope();
        delete oldScope;

        return true;
    }

    bool Insert(string name, string type, int& scopeId, int& bucketNo, int& chainPos) {
        if (currentScope == 0) {
            return false;
        }

        scopeId = currentScope->getScopeId();
        return currentScope->Insert(name, type, bucketNo, chainPos);
    }

    bool Remove(string name, int& scopeId, int& bucketNo, int& chainPos) {
        if (currentScope == 0) {
            return false;
        }

        scopeId = currentScope->getScopeId();
        return currentScope->Delete(name, bucketNo, chainPos);
    }

    SymbolInfo* LookUp(string name, int& scopeId, int& bucketNo, int& chainPos) const {
        ScopeTable* scope = currentScope;

        while (scope != 0) {
            SymbolInfo* found = scope->LookUp(name, bucketNo, chainPos);

            if (found != 0) {
                scopeId = scope->getScopeId();
                return found;
            }

            scope = scope->getParentScope();
        }

        scopeId = -1;
        bucketNo = -1;
        chainPos = -1;
        return 0;
    }

    void PrintCurrentScopeTable(ostream& out) const {
        if (currentScope != 0) {
            currentScope->Print(out, 1);
        }
    }

    void PrintAllScopeTables(ostream& out) const {
        ScopeTable* scope = currentScope;
        int indentLevel = 1;

        while (scope != 0) {
            scope->Print(out, indentLevel);
            scope = scope->getParentScope();
            indentLevel++;
        }
    }

    void RemoveAllScopesWithMessage(ostream& out) {
        while (currentScope != 0) {
            int id = currentScope->getScopeId();
            ScopeTable* parent = currentScope->getParentScope();
            delete currentScope;
            currentScope = parent;
            out << "\tScopeTable# " << id << " removed\n";
        }
    }
};

bool isSpaceChar(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' ||
           ch == '\r' || ch == '\f' || ch == '\v';
}

void skipSpaces(const string& line, int& pos) {
    while (pos < (int)line.length() && isSpaceChar(line[pos])) {
        pos++;
    }
}

string readToken(const string& line, int& pos) {
    skipSpaces(line, pos);

    string token = "";

    while (pos < (int)line.length() && !isSpaceChar(line[pos])) {
        token += line[pos];
        pos++;
    }

    return token;
}

int tokenizeLine(const string& line, string tokens[]) {
    int pos = 0;
    int count = 0;

    while (pos < (int)line.length()) {
        string token = readToken(line, pos);

        if (token.length() == 0) {
            break;
        }

        tokens[count] = token;
        count++;
    }

    return count;
}

string makeCommandText(string tokens[], int tokenCount) {
    string text = "";

    for (int i = 0; i < tokenCount; i++) {
        if (i > 0) {
            text += " ";
        }

        text += tokens[i];
    }

    return text;
}

string makeFunctionType(string tokens[], int tokenCount) {
    string result = "FUNCTION,";

    result += tokens[3];
    result += "<==(";

    for (int i = 4; i < tokenCount; i++) {
        if (i > 4) {
            result += ",";
        }

        result += tokens[i];
    }

    result += ")";
    return result;
}

string makeStructOrUnionType(string tokens[], int tokenCount) {
    string result = tokens[2];
    result += ",{";

    bool firstPair = true;

    for (int i = 3; i + 1 < tokenCount; i += 2) {
        if (!firstPair) {
            result += ",";
        }

        result += "(";
        result += tokens[i];
        result += ",";
        result += tokens[i + 1];
        result += ")";

        firstPair = false;
    }

    result += "}";
    return result;
}

bool isKnownCommandWithOutput(string tokens[], int tokenCount, SymbolTable& symbolTable) {
    if (tokenCount == 0) {
        return false;
    }

    string command = tokens[0];

    if (command == "I" || command == "L" || command == "D" ||
        command == "S" || command == "Q") {
        return true;
    }

    if (command == "E") {
        return symbolTable.canExitCurrentScope();
    }

    if (command == "P") {
        if (tokenCount == 2 && (tokens[1] == "A" || tokens[1] == "C")) {
            return true;
        }

        return false;
    }

    return false;
}

int main(int argc, char* argv[]) {
    istream* in = &cin;
    ostream* out = &cout;

    ifstream inputFile;
    ofstream outputFile;

    if (argc >= 2) {
        inputFile.open(argv[1]);

        if (!inputFile) {
            cout << "Could not open input file.\n";
            return 1;
        }

        in = &inputFile;
    }

    if (argc >= 3) {
        outputFile.open(argv[2]);

        if (!outputFile) {
            cout << "Could not open output file.\n";
            return 1;
        }

        out = &outputFile;
    }

    int bucketCount;

    if (!(*in >> bucketCount)) {
        return 0;
    }

    string line;
    getline(*in, line);

    SymbolTable symbolTable(bucketCount);
    int rootId = symbolTable.EnterScope();
    *out << "\tScopeTable# " << rootId << " created\n";

    int commandNo = 1;

    while (getline(*in, line)) {
        int maxTokens = (int)line.length() + 1;
        string* tokens = new string[maxTokens];
        int tokenCount = tokenizeLine(line, tokens);

        if (tokenCount == 0) {
            delete[] tokens;
            continue;
        }

        if (!isKnownCommandWithOutput(tokens, tokenCount, symbolTable)) {
            delete[] tokens;
            continue;
        }

        string commandText = makeCommandText(tokens, tokenCount);
        *out << "Cmd " << commandNo << ": " << commandText << "\n";
        commandNo++;

        string command = tokens[0];

        if (command == "I") {
            if (tokenCount < 3) {
                *out << "\tNumber of parameters mismatch for the command I\n";
            } else {
                string name = tokens[1];
                string type;

                if (tokens[2] == "FUNCTION") {
                    if (tokenCount < 4) {
                        *out << "\tNumber of parameters mismatch for the command I\n";
                        delete[] tokens;
                        continue;
                    }

                    type = makeFunctionType(tokens, tokenCount);
                } else if (tokens[2] == "STRUCT" || tokens[2] == "UNION") {
                    type = makeStructOrUnionType(tokens, tokenCount);
                } else {
                    type = tokens[2];
                }

                int scopeId, bucketNo, chainPos;
                bool inserted = symbolTable.Insert(name, type, scopeId, bucketNo, chainPos);

                if (inserted) {
                    *out << "\tInserted in ScopeTable# " << scopeId
                         << " at position " << bucketNo << ", " << chainPos << "\n";
                } else {
                    *out << "\t'" << name << "' already exists in the current ScopeTable\n";
                }
            }
        } else if (command == "L") {
            if (tokenCount != 2) {
                *out << "\tNumber of parameters mismatch for the command L\n";
            } else {
                string name = tokens[1];
                int scopeId, bucketNo, chainPos;
                SymbolInfo* found = symbolTable.LookUp(name, scopeId, bucketNo, chainPos);

                if (found != 0) {
                    *out << "\t'" << name << "' found in ScopeTable# " << scopeId
                         << " at position " << bucketNo << ", " << chainPos << "\n";
                } else {
                    *out << "\t'" << name << "' not found in any of the ScopeTables\n";
                }
            }
        } else if (command == "D") {
            if (tokenCount != 2) {
                *out << "\tNumber of parameters mismatch for the command D\n";
            } else {
                string name = tokens[1];
                int scopeId, bucketNo, chainPos;
                bool deleted = symbolTable.Remove(name, scopeId, bucketNo, chainPos);

                if (deleted) {
                    *out << "\tDeleted '" << name << "' from ScopeTable# " << scopeId
                         << " at position " << bucketNo << ", " << chainPos << "\n";
                } else {
                    *out << "\tNot found in the current ScopeTable\n";
                }
            }
        } else if (command == "P") {
            if (tokens[1] == "A") {
                symbolTable.PrintAllScopeTables(*out);
            } else if (tokens[1] == "C") {
                symbolTable.PrintCurrentScopeTable(*out);
            }
        } else if (command == "S") {
            int id = symbolTable.EnterScope();
            *out << "\tScopeTable# " << id << " created\n";
        } else if (command == "E") {
            int removedId;
            bool removed = symbolTable.ExitScope(removedId);

            if (removed) {
                *out << "\tScopeTable# " << removedId << " removed\n";
            }
        } else if (command == "Q") {
            symbolTable.RemoveAllScopesWithMessage(*out);
            delete[] tokens;
            break;
        }

        delete[] tokens;
    }

    return 0;
}
