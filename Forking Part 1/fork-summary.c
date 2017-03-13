#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int c,char **v)
{
    pid_t id = fork();
    
    if(id < 0){
        perror("Fork() failed\n");
    }
    
    else if(id > 0){
        printf("I am parent process my ID is : %d and my child is %d\n",getpid(),id);
    }
    
    else{
        printf("I am child process my Id is : %d and my parent is %d\n",getpid(),getppid());
        execl("/bin/echo","echo","Hello World",NULL);
        //system("ls");
    }
    
    return 0;
}