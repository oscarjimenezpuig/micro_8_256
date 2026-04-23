/* Calculadora 23/4/26 */

#define EOS '\0'

#define MAXCAR 4

typedef signed char s1;

static char Instruction[MAXCAR];

static char equa(Instruction a,Instruction b) {
    char *pa=a;
    char* pb=b;
    while(*pa!=EOS) {
        if(*pa!=*pb) return 0;
        pa++;
        pb++;
    }
    return (*pb==EOS);
}

#define el(I,V) (Element){I,(V)}

static s1 chkins(Instruction i) {
    /* mira todas las instrucciones y las compara con la entrada */
    const char* INS[]={"LDA","LDB","LDI","LDJ","LAI","LIA","MVA","MVB","MVI","MVJ","SWA","SWI","AND","OR","XOR","NOT","RGT","LFT","INC","DEC","OUV","OUC","INV","INC","CLR","JMP","IFZ","IFN","IFR","IFL","INZ","INN","INR","INL","CLL","RET","STP"};
    const u1 VAL[]={1,17,33,49,2,3,4,20,36,52,5,37,6,22,38,54,70,86,102,118,7,71,23,87,39,8,25,41,57,73,26,42,58,74,11,12,0};
    int n=0;
    u1 val=0;
    do {
        val=VAL[n];
        if(equa(INS[n],i)) return val;
    }while(val!=0);
    return -1;
}
     
