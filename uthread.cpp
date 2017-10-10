#include "uthread.h"
#include "tcb.h"
#include <stdlib.h>
#include <ucontext.h>
#include <cstddef>
#include <vector>

using namespace std;

typedef unsigned long address_t;

#define MAXTHREADS 10

ucontext_t mainContext;

vector<TCB> readyQueue;
vector<TCB> waitingQueue;
vector<TCB> finishedQueue;

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
    int tid = createdThread->getTID();
    getcontext(context);
    context->uc_mcontext.gregs[REG_RIP] =
        createdThread->getProgramCounter();
    context->uc_mcontext.gregs[REG_RSP] =
        createdThread->getStackPointer();
    sigemptyset(&(context->uc_sigmask));
    
    createdThread->setState(State::READY);
    readyQueue.push_back(*createdThread);
    createdThread = NULL;

    return tid;
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
    if (runningThread != NULL)
    {
        uthread_yield();
    }
    if(tid < 0){
        runningThread = waitingQueue.pop_front();
    runningThread = getTCB(tid, readyQueue)
    volatile int flag = 0;
    int ret_val = getcontext(runningThread);
    if(flag == 1)
        return;
    flag = 1;
    setcontext(runningThread); 
}


//! Finds a TCB in a vactor by tid and removes it, returning pointer
/*!
 * \param tid int the thread id number
 * \param vec vector<TCB> The vector that the the TCB might be in
 * \return TCB* a pointer to the TCB or NULL
 */
TCB *getTCB(int tid, vector<TCB> vec)
{
    for(auto = vec.begin(); it != vec.end(); ++it){
        if(it->getTID() == tid)
        {
            TCB *block = &(*it);
            vec.erase(it);
            return block;
        }
        return NULL;
    }
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
