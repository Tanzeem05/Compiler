int depth;
int main() {
    int saved;
    depth++;
    saved=depth;
    if(depth<3) main();
    println(saved);
    return 0;
}
