#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int number;
    struct Node *next;
}Node;

Node* Push(Node* top);
Node* Pop(Node* top,int n);
int size(Node* top);
int Peek(Node* top);
void Isempty(Node* top);
void Display(Node* top);
void FreeList(Node* top);


int main()
{
    Node* top = NULL;
    int n = 0 ;
    printf("Input the number of elemenet in stack you want :");
    scanf("%d",&n);
    int length  = size(top);
    for(int i = 0 ; i < n ; i++)
    {
        top = Push(top);
    }
    Isempty(top);
    int value = Peek(top);
    printf("The value at the top %d",value);
    for (int i = 0 ; i < n ; i++)
    {
        length = n - i;
        top = Pop(top,length);
    }
    
    FreeList(top);
    return 0 ;
}

// Utility function to add an element `x` to the stack
Node* Push(Node* top)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
       fprintf(stderr,"Unable to allocate memory"); 
    }
    printf("What value your want to add : ");
    scanf("%d",&(NewNode->number));
    NewNode->next = top;
    return NewNode;
}

// Utility function to pop a top element from the stack
Node* Pop(Node* top,int n)
{
    int element = n;
    Node* Temp = top;
    printf("\nData of node %d which is being deleted is : %d\n",element,Temp->number);
    return Temp->next;
    
}

// Free space after allocate
void FreeList(Node* top)
{
    Node* tmp = top;

    while (tmp != NULL)
    {
       tmp = tmp->next;
       free(tmp);
    }
    free(tmp);
}


// Print out the value
void Display(Node* top)
{
    Node* tmp = top;
    while (tmp != NULL)
    {
        printf("The data = %d\n",tmp->number);
        tmp = tmp->next; 
    }
 
}

// Utility function to return the top element of the stack
int Peek(Node* top)
{
    return top->number;
}

// Utility function to check if the stack is empty or not
void Isempty(Node* top)
{
    if (top == NULL)
    {
        fprintf(stderr,"The stack is empty"); 
    }
}

// Utility function to return the size of the stack
int size(Node* top)
{
    Node* tmp = top;
    int element = 0; 
    while (tmp != NULL)
    {
        element++;
        tmp = tmp->next;
    }
    return element;
}


