#ifndef UTHREAD_H
#define UTHREAD_H

#ifndef __USE_GNU
#define __USE_GNU
#endif //__USE_GNU

typedef unsigned long address_t;

//! Creates a new thread
int uthread_create(void *(*start_routine)(void *), void *args);

//! Calling thread relinquishes control
int uthread_yield(void);

//! Returns tid of current running thread
int uthread_self(void);

//! Waits for thread to finish. Returns exit status of thread.
int uthread_join(int tid, void **retval);

//! Initializes thread
int uthread_init(int time_slice);

//! Terminates thread
int uthread_terminate(int tid);

//! Suspends thread temporarily
int uthread_suspend(int tid);

//! Resumes thread execution
int uthread_resume(int tid);

//! Async I/O
ssize_t async_read(int fildes, void *buf, size_t nbytes);

#endif //UTHREAD_H
