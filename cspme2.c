#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

long long sum =0;

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
    
    long long limit = atoll(argv[1]);
    
    pthread_t tid;
    
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_create(&tid,&attr,sum_runner,&limit);
    
    pthread_join(tid,NULL);
    
    printf("%lld\n",sum);
    //fork();
    return 0;
}