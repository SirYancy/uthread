#include <stdlib.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0

typedef struct thread_control_block tcb;

int getQueueSize(Queue* pQueue)
{
    return pQueue->size;
}


Queue *BuildQueue(int limit)
{
    Queue *queue = (Queue*) malloc(sizeof (Queue));
    if (queue == NULL)
        return NULL;
    if (limit <= 0)
    {
        limit = 65535;
    }

    queue->limit = limit;
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}
    
void DestroyQueue(Queue *queue)
{
    Node *pN;
    while(!isEmpty(queue)) {
        pN = Dequeue(queue);
        free(pN);
    }
    free(queue);
}

int Enqueue(Queue *pQueue, Node *item)
{
    if((pQueue == NULL) || (item == NULL))
        return FALSE;

    if (pQueue->size >= pQueue->limit)
        return FALSE;

    item->prev = NULL;
    if(pQueue->size == 0)
    {
        pQueue->head = item;
        pQueue->tail = item;
    }else{
        pQueue->tail->prev = item;
        pQueue->tail = item;
    }

    pQueue->size++;
    return TRUE;
}

Node *Dequeue(Queue *pQueue)
{
    Node *item;
    if(isEmpty(pQueue))
        return NULL;
    item = pQueue->head;
    pQueue->head = (pQueue->head)->prev;
    pQueue->size--;
    return item;
}

int isEmpty(Queue* pQueue)
{
    if(pQueue == NULL)
        return FALSE;
    if(pQueue->size == 0)
    {
        return TRUE;
    }else{
        return FALSE;
    }
}

Node *BuildNode(tcb *thread)
{
    Node *item;
    item = (Node*) malloc(sizeof(Node));
    item->thread = thread;
    return item;
}

