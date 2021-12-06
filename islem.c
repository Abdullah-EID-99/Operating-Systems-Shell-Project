#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char** envp){
    int pipefd[2];
    int pid;
    char s[10];
    int c;
    if (pipe(pipefd) < 0) {
       perror("pipe");
       exit(1);
    }

    char* oprationName = argv[0];
    //int a = atoi(argv[1]);
    //int b = atoi(argv[2]);
    if(strcmp("topla",oprationName) == 0){
        //printf("%d + %d = %d\n", a, b, a+b);
      pid = fork();

      if (pid == 0) {
        c = execve("topla", argv);
        perror("");
        close(pipefd[1]);
      } else {
        wait(&c);
        read(pipefd[0], s, 10);
        printf("%s + %s = ",argv[1],argv[2]);
        int x=0;
        while(s[x] != 'l'){
             printf("%c",s[x++]);
             
        }
        printf("\n");
      }
    }else if(strcmp("cikar",oprationName) == 0){
        //printf("%d - %d = %d\n", a, b, a-b);
      pid = fork();

      if (pid == 0) {
        c = execve("cikar", argv);
        perror("");
        close(pipefd[1]);
      } else {
        wait(&c);
        read(pipefd[0], s, 10);
        printf("%s - %s = ",argv[1],argv[2]);
        int x=0;
        while(s[x] != 'l'){
             printf("%c",s[x++]);
             
        }
        printf("\n");
      }
    }
    

      
      
    
}
