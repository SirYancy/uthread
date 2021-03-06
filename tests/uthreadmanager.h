#ifndef THREAD_MANAGER
#define THREAD_MANAGER

int uthread_create(void *(*start_routine)(void *), void *arg);
int uthread_yield(void);
int uthread_self(void);
int uthread_join(int tid, void **retval);

int uthread_init(int time_slice);
int uthread_terminate(int tid);
int uthread_suspend(int tid);
int uthread_resume(int tid);


#endif //THREAD_MANAGER
