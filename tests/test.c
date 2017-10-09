#include <stdio.h>
#include <setjmp.h>
#include <string.h>

sigjmp_buf abort_main;

void abort_prog(int status)
{
    siglongjmp(abort_main, status);
}

void do_work()
{
    int i;
    for(i = 0; i < 10; i++){
        printf("working...\n");
    }
    abort_prog(1);
}


int main()
{
    while(1){
        if(sigsetjmp(abort_main, 1))
        {
            printf("Switching to main...\n");
            return;
        }
        else
            do_work();
    }
}


