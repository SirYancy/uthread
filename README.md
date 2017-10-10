# uthread
A user-level thread library in C/C++

## CSCI 5103

The library must implement the following APIs:

**pthread**

* int uthread_create(void *(*start_routine)(void *), void *arg);
* int uthread_yield(void);
* int uthread_self(void);
* int uthread_join(int tid, void **retval);

**control**

* int uthread_init(int time_slice);
* int uthread_terminate(int tid);
* int uthread_suspend(int tid);
* in uthread_resume(int tid);

**Async I/O**

* ssize_t async_read(int fildes, void *buf, size_t nbytes);
    * I have no idea what to do with this one at this point.

**Synchronization** Locks, etc (optional)

We have two function pairs to choose from. I'm voting for the `getcontext` and `setcontext` functions. One problem with this code as written is that it uses some functions we are not allowed to use. That is, the makecontext and swapcontext functions. So that needs to be rectified.

Also, I want to convert this all to C++, and implement the Thread Control Block as a class because... well, it's just the way I think. Structs are all well and good, but I prefer classes.

## Tests folder

In the tests folder I have the example files and some other tests that I've run. We should disregard any of my tests that used `makecontext`. That's cheating. I'll delete them later.

## TODO

* Thinking of changing the vectors to deques because vectors are very annoyingly FILO and we need FIFO behavior, but queues are not indexable. So, the deque seems like kind of a heavy solution to the problem, but it should be fine.
* Continuing to implement the other methods in uthread.cpp
