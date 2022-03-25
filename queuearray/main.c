#include <stdio.h>
#include <stdlib.h>

int qCount;
// A Linked List Node
struct Node
{
    float items;               // integer items
    struct Node* next;      // pointer to the next node
}*rear = NULL, *front = NULL;
 
// Utility function to allocate the new queue node
struct Node* newNode(float item)
{
    // allocate a new node in a heap
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
 
    // check if the queue (heap) is full. Then inserting an element would
    // lead to heap overflow
    if (node != NULL)
    {
        // set items in the allocated node and return it
        node->items = item;
        node->next = NULL;
        return node;
    }
    else {
        printf("\nHeap Overflow");
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to dequeue the front element
float dequeue()        // delete at the beginning
{
    if (front == NULL)
    {
        printf("\nQueue Underflow");
        exit(EXIT_FAILURE);
    }
 
    struct Node* temp = front;
    printf("Removing %f\n", temp->items);
 
    // advance front to the next node
    front = front->next;
 
    // if the list becomes empty
    if (front == NULL) {
        rear = NULL;
    }
 
    // deallocate the memory of the removed node and optionally return the removed item
    float item = temp->items;
    qCount--;
    free(temp);
    return item;
}
 
// Utility function to add an item to the queue
void enqueue(float item)        // insertion at the end
{
    // allocate a new node in a heap
    struct Node* node = newNode(item);
    printf("Inserting %f\n", item);
 
    // special case: queue was empty
    if (front == NULL)
    {
        // initialize both front and rear
        front = node;
        rear = node;
    }
    else {
        // update rear
        rear->next = node;
        rear = node;
    }
    
    qCount++;
}
 
// Utility function to return the top element in a queue
float peek()
{
    // check for an empty queue
    if (front != NULL) {
        return front->items;
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to check if the queue is empty or not
int isEmpty() {
    return rear == NULL && front == NULL;
}
 
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    
    printf("\nqcount is: %d\n\n", qCount);
 
    printf("The front element is %f\n", peek());
 
    dequeue();
    dequeue();
    dequeue();
    dequeue();
 
    if (isEmpty()) {
        printf("The queue is empty");
    }
    else {
        printf("The queue is not empty");
    }
    
    printf("\nqcount is: %d\n\n", qCount);
 
    return 0;
}