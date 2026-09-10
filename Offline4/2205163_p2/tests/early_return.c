int f(int x) {
    if (x) return x;
    int a[30];
    a[0] = 8;
    return a[0];
}
int main() {
    int x;
    x = f(5) + f(0); println(x);
    return 0;
}
