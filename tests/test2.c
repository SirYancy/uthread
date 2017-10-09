#include <stdio.h>

#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <ucontext.h>

#define STACK_SIZE 4096
typedef unsigned long address_t;

char stack[STACK_SIZE];

ucontext_t context;

void switchThreads();

void do_work()
{
    int i;
    for(i = 0; i < 10; i++){
        printf("working...\n");
    }
    switchThreads();
}

void setup()
{
    address_t sp, pc;

    sp = (address_t)stack + STACK_SIZE - sizeof(int);
    pc = (address_t)do_work;

    getcontext(&context);

    context.uc_mcontext.gregs[REG_RIP] = pc;
    context.uc_mcontext.gregs[REG_RSP] = sp;
    sigemptyset(&context.uc_sigmask);
}

void switchThreads()
{
    int retVal = getcontext(&context);
    printf("SWITCH\n");
    return;
}
int main()
{
    setup();
    setcontext(&context);
    printf("Exiting\n");
    return 0;
}
