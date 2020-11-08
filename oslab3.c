#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tmp1_thread,tmp2_thread;
void *process1(void *arg){
    int sum=0,i;
    printf("Enter marks of 5 subjects for thread %s:   ",(char *)arg);
    int marks[5];
    for (i=0;i<5;i++){     
        scanf(" %d",&marks[i]);
        sum=sum+marks[i];  
    }
     printf("%s thread  sum is: ",(char *)arg);
    pthread_exit(sum);}
    int main(int argc, char** argv){
    pthread_t t1,t2;
    void *exitstatus;
    pthread_create(&t1,NULL,process1,"t1");
    pthread_join(t1,&exitstatus);
    printf("%d\n",(int *)exitstatus);
    tmp1_thread=(int *)exitstatus;
    pthread_create(&t2,NULL,process1,"t2");
    pthread_join(t2,&exitstatus);
    printf("%d\n",(int *)exitstatus);
    tmp2_thread=(int *)exitstatus;

    if (tmp1_thread>tmp2_thread){
        printf("Thread t1 scored  more marks than t2 which is:  %d",tmp1_thread);}
    if (tmp1_thread==tmp2_thread){
        printf("Thread t1 and  t2 are equal which is:  %d",tmp1_thread);}
    else{
        printf("Thread t2 scored more marks than t1 which is:  %d",tmp2_thread);}
    return(EXIT_SUCCESS);
    
    }

