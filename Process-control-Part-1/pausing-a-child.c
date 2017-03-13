#include <unistd.h>
#include <stdio.h>
int main() {
  printf("My pid is %d\n", getpid() );
  int i = 60;
  while(--i) { 
    write(1, ".",1);
    sleep(1);
  }
  write(1, "Done!",5);
  return 0;
}

/*
We will first start the process in the background (notice the & at the end). Then send it a signal from the shell process by using the kill command.

Terminal
-------------
>./program &
My pid is 403
...
>kill -SIGSTOP 403
>kill -SIGCONT 403

*/