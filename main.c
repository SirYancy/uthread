#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include "uthread.h"


int f (int j)
{
       for(int i = 0 ; i < 10; i++)
       {
           printf("working...%d\n", j);
       }
} 

int main()
{
    int i = 5;
    uthread_create((void *(*)(void *))f,&i);
    uthread_resume(i);
}
