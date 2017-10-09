#include <stdlib.h>
#include <stdio.h>
#include <ucontext.h>
#include "uthread.h"
#include "queue.h"

#ifndef __USE_GNU
#define __USE_GNU
#endif //__USE_GNU

#define STACK_SIZE 4096

typedef unsigned long address_t;

typedef struct Queue Queue;
typedef struct Node Node;

ucontext_t main_context;

int maxThreads = 10;
Queue *threadQueue;

typedef struct thread_control_block {
    unsigned int tid;
    ucontext_t *context;
    void* args;
} tcb;


//! Creates a new thread
int uthread_create(void *(*start_routine)(void *), void *args)
{
    if(threadQueue == NULL)
        threadQueue = BuildQueue(maxThreads);

    ucontext_t c;
    getcontext(&c);
    char st[STACK_SIZE];
    if(getcontext(&c) == -1)
        abort();
    
    c.uc_link = &main_context;
    c.uc_stack.ss_sp = st;
    c.uc_stack.ss_size = sizeof(st);
    makecontext(&c, (void (*) (void)) start_routine, 1, args);

    tcb *thread = (tcb*)malloc(sizeof(tcb));
    thread->tid = getQueueSize(threadQueue);
    thread->context = &c;
    thread->args = args;

    Node *threadNode = BuildNode(thread);

    Enqueue(threadQueue, threadNode) == 0;

    return thread->tid;

}

//! Calling thread relinquishes control
int uthread_yield(void)
{

}

//! Returns tid of current running thread
int uthread_self(void)
{

}

//! Waits for thread to finish. Returns exit status of thread.
int uthread_join(int tid, void **retval)
{

}

//! Initializes thread
int uthread_init(int time_slice)
{

}

//! Terminates thread
int uthread_terminate(int tid)
{

}

//! Suspends thread temporarily
int uthread_suspend(int tid)
{

}

//! Resumes thread execution
int uthread_resume(int tid)
{

    Node *tN = Dequeue(threadQueue);
    tcb *thread = tN->thread;
    swapcontext(&main_context, thread->context);

}

//! Async I/O
ssize_t async_read(int fildes, void *buf, size_t nbytes)
{

}
