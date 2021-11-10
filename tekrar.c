#include <stdio.h>
#include <stdlib.h>
int length(char* str){
    int counter = 0;
    while(*str != '\0'){
        str++;
        counter++;
    }
    return counter;
}

int wordsCount(char** str){
    int counter = 0;
    while(*(str+counter) != NULL){
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
char** split(char* str, char c){
    int i,j,index,wordLength;
    int start = 0;
    int len = length(str);//lenght of string
    int countOfStrings = charCount(str,c) + 1;
    char **words = (char**) malloc(countOfStrings * sizeof(char *));
    int indexOfWord = 0;
    char* temp;
    for(i=0;i<len;i++){
        
        if(*(str+i) == ' '){
            wordLength = (i-start);
            words[indexOfWord]=(char*) malloc(wordLength * sizeof(char));
            temp = words[indexOfWord++];
            index = 0;
            for(j=start;j<i;j++){
                *(temp+index++)=*(str+j);
            }
            *(temp+wordLength) = '\0';
            start = i+1;
        }
        
    }
        wordLength = (len-start);
        words[indexOfWord]=(char*) malloc(wordLength * sizeof(char));
        temp = words[indexOfWord];
        index = 0;
        for(j=start;j<len;j++){
            *(temp+index++)=*(str+j);
        }
        *(temp+wordLength) = '\0';
    
    return words;
}
int main()
{
    char* str = "00 111 2222 33333 444444 5555555";
    int i;
    
    char** words=split(str, ' ');
    int wc = wordsCount(words);
     for(i = 0; i < wc;i++){
            printf("words[%d] = %s\n", i,*(words+i));
        }
        
        printf("successful = %d\n",charCount("111 111 111 22 aaaaaa",'a'));
    
    
    

    return 0;
}