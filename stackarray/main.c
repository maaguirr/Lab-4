#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int stackSize;
// Data structure to represent a stack
typedef struct Stack
{
   
    float items;
    struct Stack *next;
   
} Stack;

struct Stack *head = NULL;

int isEmpty(){
    if (head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
// Utility function to initialize the stack
void pushStack(float value)
{
    Stack *pStack = (Stack*)malloc(sizeof(Stack));
   
    if (pStack == NULL){
        printf("Stack overflow.");
        exit(1);
    }
 
    pStack->items = value;
    pStack->next = NULL;
   
    pStack->next = head;
   
    head = pStack;
    stackSize++;
}

void print(){
    struct Stack* temp;
    temp = head;
    if (isEmpty()){
        printf("Stack underflow");
        exit(1);
    }
    printf("the stack elements are: ");
    while (temp){
        printf("%0.1f ", temp->items);
        temp = temp->next;
    }
   
    printf("\n");
}
 
 
float pop(){
    struct Stack* temp;
    float val;
    if(isEmpty()){
        printf("Stack underflow");
        exit(1);
    }
    temp = head;
    val = temp->items;
    head = head->next;
    free(temp);
    temp = NULL;
    stackSize--;
    return val;
    
}

float peek(){
    if (isEmpty()){
        printf("Stack underflow");
        exit(1);
    }
    return head->items;
}
 
int main()
{
    int choice;
    float data;
    while(1){
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. print top element\n");
        printf("4. print all elements\n");
        printf("5. print stack size\n");
        printf("6. quit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
       
        switch(choice){
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%f", &data);
                pushStack(data);
                break;
            case 2:
                data = pop();
                print();
                break;
            case 3:
                printf("the topmost elements of the stack is %f\n", peek());
            case 4:
                print();
            case 5:
                printf("the stack size is %d", stackSize);
            case 6:
                exit(1);
            default:
                printf("incorrect choice");
                
        }
       
    }
    // create a stack of capacity 5
    //Stack *pt = newStack(5);
    //float  value;
 
    //push(pt, 1.0);
    //push(pt, 2.0);
   
   
   
    /*printf("The stack size is %d\n", size(pt));
    peek(pt, &value);
    printf("Top val on stack is %f\n", value);
    pop(pt, &value);
    pop(pt, &value);
    pop(pt, &value);
 
    if (isEmpty(pt)) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }*/
 
    return 0;
}