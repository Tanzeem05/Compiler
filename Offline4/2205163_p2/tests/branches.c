int main() {
    int a,b,c,x,i;
    for (a=0; a<2; a++) for (b=0; b<2; b++) for (c=0; c<2; c++) {
        x=0;
        if(a) if(b) if(c) x=1; else x=2; else x=3;
        println(x);
        x=0;
        if(a) if(b) x=1; else if(c) x=2; else x=3; else x=4;
        println(x);
        x=0;
        if(a) { if(b) x=1; } else x=2;
        println(x);
        x=0;
        if(a) for(i=0;i<2;i++) if(b) x=x+1; else x=x+2;
        println(x);
        i=1; x=0;
        if(a) while(i--) if(b) x=1; else x=2;
        println(x);
    }
    return 0;
}
