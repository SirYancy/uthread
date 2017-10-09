#ifndef QUEUE_C
#define QUEUE_C

typedef struct thread_control_block tcb;

typedef struct Node Node;
typedef struct Queue Queue;

struct Node {
    tcb *thread;
    struct Node *prev;
};

struct Queue {
    Node *head;
    Node *tail;
    int size;
    int limit;
};

Queue *BuildQueue(int limit);

void DestroyQueue(Queue *queue);

int Enqueue(Queue *pQueue, Node *item);

Node *Dequeue(Queue *pQueue);

int isEmpty(Queue* pQueue);

int getQueueSize(Queue* pQueue);

Node *BuildNode(tcb *thread);


#endif //QUEUE_C
