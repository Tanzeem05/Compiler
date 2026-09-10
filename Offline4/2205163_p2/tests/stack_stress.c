int main() {
    int i, total;
    total = 0;
    for (i = 0; i < 100000; i++) {
        int block[64];
        block[0] = i;
        total = total + (block[0] % 7);
    }
    println(total);
    return 0;
}
