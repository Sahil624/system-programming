#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

long long sum =0;
int flag[2];
int turn;
const int MAX = 10000;
int ans = 0;


void lock_init(){
    flag[0]=flag[1]=0;
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



void* sum_runner(void* arg){
    long long *limitptr = (long long*) arg;
    long long limit = *limitptr;
    long long i;
    
    for(i=0;i<=limit;i++){
        sum += i;
    }
}


int main(int argc, char **argv){
    
    if(argc<2){
        printf("Give args");
        exit(-1);
    }
    
   // long long limit = atoll(argv[1]);
   // long long limit2 = atoll(argv[2]);
    
    pthread_t tid,tid2;
    
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_create(&tid,&attr,sum_runner,&limit);
    pthread_create(&tid2,&attr,sum_runner,&limit2);
    
    pthread_join(tid,NULL);
     pthread_join(tid2,NULL);
    
    printf("%lld\n",sum);
    //fork();
    return 0;
}