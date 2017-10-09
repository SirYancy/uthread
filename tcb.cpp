#include <uthread.h>

#define STACK_SIZE 4096

using namespace std;

typedef unsigned long address_t;


//! Contructor
/*! Constructor sets all member variables for the thread control block
 * \param tid int thread ID number
 * \param start_routine pointer to entry function
 * \param args void arguments to pass to entry function
 */
TCB::TCB(const int tid, void *(*start_routine)(void *), void *args):
    tid(tid)
{
    char stack[STACK_SIZE];

    sp = (address_t)stack + STACK_SIZE - sizeof(int);
    pc = (address_t)start_routine;

    state = "INIT";
    
    arg = (address_t)args;
    
    ret_val = 0;

}

//! Thread ID getter
/*!
 * \return tid int Thread ID number
 */
int TCB::getTID() const
{
    return tid;
}

//! Context getter
/*!
 * \return context ucontext_t the context for this thread
 */
ucontext_t TCB::getContext()
{
    return context;
}

//! Stack pointer getter
/*!
 * \return sp address_t pointer to stack
 */
address_t TCB::getStackPointer()
{
    return sp;
}

//! Arguments array (?) getter
/*! 
 * \return args void* the arguments array (?) to be passed to the entry function
 */
address_t TCB::getArguments() const
{

    return arg;
}

//! Return value getter
/*!
 * \return ret_val address_t pointer to the return value of entry function
 */
address_t TCB::ret_val
{
    return re_val;
}

//! State getter
/*! \return state State the current state of this thread based on enum
 * declared in header file.
 */
State TCB::getState() const
{
    return state;
}

//! State setter
/*! \param state State the state this thread is transitioning to.
 */
void TCB::setState(const State s)
{
    state = s;
}











