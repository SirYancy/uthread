#include "uthread.h"
#include "tcb.h"
#include <ucontext.h>
#include <queue>
#include <cstddef>

using namespace std;

typedef unsigned long address_t;

#define MAXTHREADS 10

ucontext_t mainContext;

queue<TCB> readyQueue;
queue<TCB> waitingQueue;
queue<TCB> finishedQueue;

int threadCount = 0;

TCB *runningThread;
TCB *createdThread;


//! Creates a new thread
/*! Creates a new thread and then calls thread_init() to complete the process.
 * \param start_routine the entry function for this thread
 * \param args the arguments to be passed to the entry function
 */
int uthread_create(void *(*start_routine)(void *), void *args)
{
    createdThread = new TCB(threadCount++, start_routine, args); 
    uthread_init(0); //TODO implement timing.
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
    ucontext_t *context = createdThread->getContext();
    getcontext(context);
    context->uc_mcontext.gregs[REG_RIP] =
        createdThread->getProgramCounter();
    context->uc_mcontext.gregs[REG_RSP] =
        createdThread->getStackPointer();
    sigemptyset(&(context->uc_sigmask));
    
    createdThread->setState(State::READY);
    readyQueue.push(*createdThread);
    createdThread = NULL;
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

}

/*
//! Async I/O
ssize_t async_read(int fildes, void *buf, size_t nbytes)
{

}
*/

//! Stub
/*! Possibly not necessary for this library?
 * Ref page 156 of text
 */
void stub(void *(*start_routine)(void *), void *args)
{
    //TODO
    //uthread_join()
}
