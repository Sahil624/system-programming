#include <unistd.h> /*fork declared here*/
#include <stdio.h> /* printf declared here*/
int main() {
   int answer = 84 >> 1;
   printf("\nAnswer: %d", answer);
   fork();
   return 0;
}