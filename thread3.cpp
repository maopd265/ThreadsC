#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<errno.h>
#include<unistd.h>

//valores long podem ser armazenados em ponteiros void porque eles tem o mesmo tamanho
 
void* do_stuff(void *param)
{
	 long thread_no=(long)param;
	 printf("Thread number %ld \n",thread_no);
	 
	return (void *) (thread_no + 1);
}
int main()
{
    pthread_t threads[20];
     long t;
     for(t=0;t<3;t++)
	 {
	 	pthread_create(&threads[t],NULL,do_stuff,(void*)t);
	 }
	 void *result;
	 for(t=0;t<3;t++)
	 {
	 	pthread_join(threads[t],&result);
	 	printf("Thread %ld returned %ld\n",t,(long)result);
	 }
	sleep(10);
	return 0;
}
