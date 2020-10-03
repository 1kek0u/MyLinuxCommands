#include <stdio.h>
#include <stdlib.h>

static int die(char*path);

int main(int argc,char*argv[]){
    int c;
    if (argc<2){
        for(;;){
            c = getchar();
            if(putchar(c)<0){
                exit(1);
            }
        }
    }else{
        FILE* file;
        for(int i=1;i<argc;i++){
            file = fopen(argv[i],"r");
            if(!file)die(argv[i]);
            if((c=fgetc(file)) == EOF)die(argv[i]);
            ungetc(c,file);
            while((c=fgetc(file)) != EOF){
                if(fputc(c,stdout)<0)die(argv[i]);
            }
        }
    exit(0);
    }
}        
            
static int die(char*path){
    perror(path);
    exit(1);
}
