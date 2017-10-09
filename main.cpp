#include <iostream>
#include <string>
#include "tcb.h"
#include "uthread.h"

using namespace std;
typedef unsigned long address_t;

int f (int i)
{
    for(int i = 0; i<10; i++)
    {
        cout << "Working...\n" << i << "\n";
    }
}

int main()
{
    int i = 5;
    uthread_create((void *(*)(void *))f, &i);
}
