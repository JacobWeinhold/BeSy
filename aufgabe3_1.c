#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *plusOne();
void *timesTwo();

int g_int = 10;

int main(void)
{
     pthread_t thread1, thread2;
   
   
     int  iret1, iret2;

    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, timesTwo, NULL);
     iret2 = pthread_create( &thread2, NULL, plusOne, NULL);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Thread 1 returns: %d\n",iret1);
     printf("Thread 2 returns: %d\n",iret2);
     printf("g_int: %d\n",g_int);
     exit(0);
	}

void *timesTwo()
{
//	sleep(1);
   	g_int *=2;
	printf("timesTWo: g_int: %d\n", g_int);
}
void *plusOne()
{
	sleep(1);
	g_int +=2;
printf("plusone g_int: %d\n", g_int);
}	
