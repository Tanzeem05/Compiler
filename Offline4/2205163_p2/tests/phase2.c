int values[6], calls;
int odd(int);
int even(int n) {
    if (n == 0) return 1;
    return odd(n - 1);
}
int odd(int n) {
    if (n == 0) return 0;
    return even(n - 1);
}
int fact(int n) {
    int saved[2];
    saved[0] = n;
    if (n <= 1) return 1;
    return saved[0] * fact(n - 1);
}
int combine(int a, int b, int c) { return a * 100 + b * 10 + c; }
int touch(void) { calls++; return 5; }
void show(int x) { println(x); }
int main(void) {
    int a[6], i, j, x, sum, sentinel;
    sentinel = 12345;
    calls = 0;
    x = 0 && touch(); println(x);
    x = 1 || touch(); println(x);
    x = (0 || touch()) && (1 && touch()); println(x);
    println(calls);
    i = 0;
    while (i < 6) {
        int local[2];
        local[0] = i + 1;
        a[i] = local[0];
        values[i] = a[i] * 2;
        i++;
    }
    sum = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 2; j++) sum = sum + values[i];
    }
    println(sum);
    x = 17;
    if (0) { int skipped[50]; skipped[0] = 3; }
    { int x; x = 9; println(x); }
    { int x[3]; x[2] = 11; sum = x[2]; println(sum); }
    println(x);
    i = 0;
    a[i++] = fact(5) + combine(1, touch(), 3);
    println(i);
    x = a[0]++; println(x);
    x = a[0]--; println(x);
    x = a[0]; println(x);
    x = even(10) + odd(9); println(x);
    x = combine(fact(3), combine(0, 1, 2), fact(2)); println(x);
    x = -17 / 5; println(x);
    x = -17 % 5; println(x);
    x = 17 % -5; println(x);
    x = -2147483648; println(x);
    x = 2147483647; println(x);
    x = !0 + !2; println(x);
    x = (3 < 4) + (3 <= 3) + (4 > 3) + (4 >= 4) + (2 == 2) + (2 != 3);
    println(x);
    x = x + 0; x = x - 0; x = x * 1; println(x);
    if (1) if (0) x = 99; else x = 7;
    println(x);
    for (; ; i++) if (i == 4) { show(sentinel); return 23; }
}
