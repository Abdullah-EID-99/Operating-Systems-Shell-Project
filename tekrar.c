#include <stdio.h>

int main(int argc, char *argv[], char** envp){
    int i;
    int tekrarSayisi = atoi(argv[0]);
    for(i=0;i<tekrarSayisi;i++){
        printf("%s\n",argv[1]);
    }
}
