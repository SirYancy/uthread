#ifndef TCB_H
#define TCB_H

#ifndef __USE_GNU
#define __USE_GNU
#endif

#include <ucontext.h>
#include <cstddef>

#define STACK_SIZE 4096

using namespace std;

typedef unsigned long address_t;

enum State{
    INIT = 0,
    READY,
    RUNNING,
    WAITING,
    FINISHED
};


class TCB
{

    public:

       //! Contructor
       TCB(const int tid, void *(*start_routine)(void *), void *args);

       //! Thread ID getter
       int getTID() const;

       //! Context getter
       ucontext_t *getContext() const;

       //! Program Counter Getter
       address_t getProgramCounter() const;

       //! Stack pointer getter
       address_t getStackPointer() const;

       //! Arguments array (?) getter
       address_t getArguments() const;

       //! Return value getter
       address_t getReturnValue() const;

       //! Return value setter
       void setReturnValue(const void* ret);

       //! State getter
       State getState() const;

       //! State setter
       void setState(const State);


    private:
        //! Thread ID
        int tid;

        //! Thread context
        ucontext_t *context;

        //! Stack Pointer
        address_t sp;

        //! Program Counter
        address_t pc;

        //! Entry function arguments
        address_t arg;

        //! Entry function return value.
        address_t ret_val;

        State state;
};



#endif //TCB_H
