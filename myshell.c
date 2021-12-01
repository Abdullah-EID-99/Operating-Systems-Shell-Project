#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int length(char* str){
    int counter = 0;
    while(*str != '\0'){
        str++;
        counter++;
    }
    return counter;
}
int charCount(char* str,char c){
    int i,counter,len;
    counter = 0;
    len = length(str);
    for(i=0;i<len;i++){
        if(*(str+i) == c){
            counter +=1;
        }
    }
    return counter;
}

void printWords(char** words, int size){
    int i;
    for(i=0;i<size;i++){
        printf("words[%d] = %s\n", i, words[i]);
    }
}
char** split(char* str){
    short wordCount=charCount(str, ' ')+1;
    char **words = (char**) malloc(wordCount* sizeof(char *));
    char *token = strtok(str, " ");// Returns first token
    // Keep printing tokens while one of the
    // delimiters present in str[].
    int counter =0;
    while (token != NULL){   
        *(words+counter++)=token;
        token = strtok(NULL, " ");
    }
    return words;
}
void tekrar(char** words){
    int i;
    int tekrarSayisi = atoi(*(words+2));
    for(i=0;i<tekrarSayisi;i++){
        printf("%s\n",*(words+1));
    }
    
}
int main(int argc, char *argv[], char** envp){
    char* newargv[3];
    char str[50];
     printf("myshell>> ");
    while(scanf("%[^\n]",str)==1){      
        short wordCount=charCount(str, ' ')+1;
        char **words=split(str);
        printf("word count: %d\n",wordCount);      
        printWords(words, wordCount);
        if(strcmp("exit",*(words)) == 0){
            break;
        }else if(strcmp("tekrar",*(words)) == 0){
            int i;
            int k, h, status;

            k = fork();

            if (k > 0) {
                h = wait(&status);
            } else {
                newargv[0]=*(words+2);
                newargv[1]=*(words+1);
                newargv[2]=NULL;
                i=execve("tekrar", newargv, envp);
                perror("error\n");
                exit(1);
            }
            //int tekrarSayisi = atoi(*(words+2));
            //for(i=0;i<tekrarSayisi;i++){
            //    printf("%s\n",*(words+1));
            //}
        }else{
            printf("yanlis bir komut girdiniz\n");
        }
        printf("myshell>> ");
        scanf("%[^\n]",str);
        getchar();
        
        
    }
    
    return 0;

}

