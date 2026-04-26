/* Calculadora 23/4/26 */

#include "parser.h"

#define EOS '\0'
#define CMC '#'
#define JPL '\n'

#define MAXCAR 4

typedef signed char s1;
typedef char Word[MAXCAR];

static char equa(const Word a,const Word b) {
    /* dice si dos palabras son iguales */
    const char *pa=a;
    const char* pb=b;
    while(*pa!=EOS) {
        if(*pa!=*pb) return 0;
        pa++;
        pb++;
    }
    return (*pb==EOS);
}

static char issep(char c) {
    /* dice si un caracter es separador */
    char* SEP=" \t";
    char* ps=SEP;
    while(*ps!=EOS) {
        if(*ps==c) return 1;
        ps++;
    }
    return 0;
}

#define iscap(A) ((A)>='A' && (A)<='Z')
#define isnum(A) ((A)>='0' && (A)<='9')

static char chktype(Word a) {
    /* dice el tipo de palabra 1: instruccion 2: valor 0: desconocida */
    char* pa=a;
    char type=3;
    while(*pa!=EOS && type) {
        if(type==3) {
            if(iscap(*pa)) type=1;
            else if(isnum(*pa)) type=2;
            else type=0;
        } else if(type==1 && !iscap(*pa)) type=0;
        else if(type==2 && !isnum(*pa)) type=0;
        pa++;
    }
    return type;
}

#define el(I,V) (Element){I,(V)}

static s1 chkins(Word i) {
    /* mira todas las instrucciones y las compara con la entrada */
    const char* INS[]={"LDA","LDB","LDI","LDJ","LAI","LIA","MVA","MVB","MVI","MVJ","SWA","SWI","AND","OR","XOR","NOT","RGT","LFT","INC","DEC","OUV","OUC","IPV","IPC","CLR","JMP","IFZ","IFN","IFR","IFL","INZ","INN","INR","INL","CLL","RET","STP"};
    const u1 VAL[]={1,17,33,49,2,3,4,20,36,52,5,37,6,22,38,54,70,86,102,118,7,71,23,87,39,8,25,41,57,73,26,42,58,74,11,12,0};
    int n=0;
    u1 val=0;
    do {
        val=VAL[n];
        if(equa(INS[n++],i)) return val;
    }while(val!=0);
    return -1;
}

static u1 readfile(FILE* file,u1* prg) {
    Word w;
    u1* pp=prg+1;
ret:
    *w=EOS;
    char end=0;
    char endword=0;
    char comment=0;
    char error=0;
    char* pw=w;
    while(!end && !endword) {
        char c=getc(file);
        if(c==EOF) end=1;
        else if(c==JPL || (issep(c) && !comment)) endword=1;
        else if(c==CMC) comment=1;
        else if(comment==0) {
            if(pw!=w+MAXCAR-1) {
                *pw++=c;
            }
        }
    }
    *pw=EOS;
    if(*w!=EOS) {
        char type=chktype(w);
        if(type==1) {
            s1 cins=chkins(w);
            if(cins==-1) error=1;
            else *pp++=(u1)cins;
        } else if(type==2) {
            u1 val=0;
            sscanf(w,"%hhi",&val);
            *pp++=val;
        } else error=1;
    }
    if(error) {
        printf("ERROR: Word <%s> unrecognised\n",w);
        return 0;
    }
    if(pp!=prg+RAMD && !end) goto ret;
    else if(pp==prg+RAMD && !end) {
        printf("ERROR: Program too long\n");
        return 0;
    } else return 1;
}

void parse(char* filename) {
    FILE* file=fopen(filename,"r");
    if(file) {
        u1 prg[RAMD];
        if(readfile(file,prg)) {
            program(prg);
        }
        fclose(file);
    } else {
        printf("ERROR: File %s not found or can't open\n",filename);
    }
}

int main(int narg,char* arg[]) {
    if(narg>1) {
        parse(arg[1]);
    }
    return 0;
}






     
