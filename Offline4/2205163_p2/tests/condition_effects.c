int calls;
int bump() { calls++; return calls; }
int main() {
    int x,i;
    calls=0;
    if (!(0 && bump())) x=1; else x=2;
    println(x); println(calls);
    if (!(1 || bump())) x=3; else x=4;
    println(x); println(calls);
    if (!(!(bump() == 1))) x=5; else x=6;
    println(x); println(calls);
    x=!(bump() > 3); println(x); println(calls);
    i=0;
    while (!(i >= 3)) i++;
    println(i);
    for(i=0; !(i>=2); i++) calls++;
    println(calls);
    if ((x=7)) println(x);
    if ((0 || 1) + 2) x=8;
    println(x);
    return 0;
}
