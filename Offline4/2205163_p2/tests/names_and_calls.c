int eax, EAX, print_number, mainValue[2];
void empty(void) {}
int next(int a) { a++; return a; }
int sum(int a, int b) { return a+b; }
int main() {
    int x;
    eax=10; EAX=20; print_number=30;
    mainValue[1]=eax+EAX+print_number;
    x=mainValue[1]; println(x);
    empty();
    x=sum(next(2),next(next(4))) + next(sum(8,9));
    println(x);
    { int sum; sum=5; println(sum); }
    x=sum(1,2); println(x);
}
