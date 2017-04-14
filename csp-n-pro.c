#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int flag[100],i;
int turn;
const int MAX = 1e9;
int ans = 0;
int num = 0;

void lock_init(){
    for(i=0;i<num;i++){
        flag[i]=0;
    printf("Flag %d initalised to %d\n",i,flag[i]); 
    }
    turn = 0;
}

void lock(int self){
    flag[self]=1;
    turn = 1-self;
    
    while(flag[1-self]==1 && turn == 1-self);
}

void unlock(int self){
    flag[self]=0;
}

void* func(void *s){
    int i=0;
    int *limitptr = (int*) s;
    int self = *limitptr;
    printf("Thread %d in queue for critical section\n",self);
    
    lock(self);
    
    printf("Thread %d in critical section\n",self);
    for(i=0;i<MAX;i++){
        
        ans++;
       
    }
     printf("Thread %d done counting\n",self);
    printf("Thread %d is exiting critical section\n",self);
    unlock(self);
}

int main(){
    
    pthread_t p[100];
    int id[100];
    //int a=0,b=1;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        id[i]=i;
    }
    lock_init();
    
    for(i=0;i<num;i++){
        printf("Process %d is going\n",id[i]);
        pthread_create(&p[i], NULL, func, &id[i]);
    }
    
    //pthread_create(&p1, NULL, func, &a);
    //pthread_create(&p2, NULL, func, &b);
    
    // pthread_join(p1, NULL);
    //pthread_join(p2, NULL);
    
    printf("Exiting Main\n");
    return 0;
}