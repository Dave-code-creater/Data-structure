#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    int Value;
    struct Node* Prev;
    struct Node* Next;
}Node;

Node * CreateLinkedList(int n);
Node* Add_New_Node_At_Begining(Node* Head);
Node* Delete_First_Node(Node* head);
Node* Delete_Last_Node(Node* Tail);
void Display(Node* head);
void FreeList(Node* Head,Node* Tail);
void Add_Node_The_End(Node* Tail,Node* Head);
void Inserting(Node* head);
void Delete(Node* Head);




int main(void)
{
    system("cls");
    int n = 0 ;
    Node* Head = NULL;
    Node* Tail = NULL;
    printf("Input the number of nodes :");
    scanf("%d",&n);
    Head = CreateLinkedList(n);
    Tail = Get_Tail(Head);
    Delete(Head);
    Display_Reverse(Tail);
    FreeList(Tail,Head);

    return 0;
}
//Write a program in C to create and display Doubly Linked List and get the head of the list

Node * CreateLinkedList(int n)
{
    Node* head = NULL;
    Node* Cur = NULL;
    Node* temp = NULL;

    for (int i = 0 ; i < n ; i++)
    {
        Cur = (Node*)malloc(sizeof(Node));
        if (Cur == NULL)
        {
            return 1;
        }
        Cur->Next = Cur->Prev = NULL;
        printf("Input data for node %d : ",i + 1);
        scanf("%d",&(Cur->Value));
        if (head == NULL)
        {

            head = Cur;
            head->Next = NULL;
            head->Prev = NULL;
        }
        else
        {
            temp = head;
            while (temp->Next != NULL)
            {
                temp = temp->Next;
            }
            temp->Next = Cur;
            Cur->Prev = temp;
            
        }

    }
    return head;
}

// Get the tail of the list
Node* Get_Tail(Node* Head)
{
    Node* Tail = Head;
    while(Tail->Next != NULL)
    {
        Tail = Tail->Next;
    }
    
    return Tail;
}

// Free space after allocate
void FreeList(Node* Head,Node* Tail)
{
    Node* Curr = Tail;
    while (Curr->Next != NULL)
    {
        Curr = Curr->Next;
        free(Curr->Prev);
    }
    free(Curr);
    Tail = NULL;
    Head = NULL;
}

// Print out the value in the list
void Display(Node* head)
{
    Node* tem = head;
    while (tem != NULL)
    {
        printf("Data = %d\n",tem->Value);
        tem = tem->Next;
    }
}

//Write a program in C to create a doubly linked list of n nodes and display it in reverse order.
void Display_Reverse(Node* Tail)
{
    Node* tem = Tail;
    while (tem != NULL)
    {
        printf("Data = %d\n",tem->Value);
        tem = tem->Prev;
    }
}

//Write a program in C to create a doubly linked list of n nodes and display it in reverse order.
Node* Add_New_Node_At_Begining(Node* Head)
{
    Node* Cur = Head;
    Display(Head);
    Node* p = (Node*)malloc(sizeof(Node));
    if(p == NULL)
    {
        return 1;
    }
    printf("What value your want to add : ");
    p->Next = p->Prev = NULL;
    scanf("%d",&(p->Value));
    p->Next = Cur;
    p->Prev = NULL;
    return p;
}

//Write a program in C to insert a new node at the middle of Doubly Linked List
void Add_Node_Middle(Node* head)
{
    int n;
    int i;
    Node* Cur_Node = head;
    Display(Cur_Node);
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Next = NewNode->Prev = NULL;
    printf("What value your want to add : ");
    scanf("%d",&(NewNode->Value));

    if (Cur_Node == NULL && NewNode == NULL)
    {
        return 0;
    }

    printf("Where do you want to put : ");
    scanf("%d",&n);

    for(int i=2; i <= n - 1 ; i++) 
    {
        if(Cur_Node->Next != NULL) {
        Cur_Node = Cur_Node->Next;
        }
    }
    NewNode->Next = Cur_Node->Next;
    Cur_Node->Next->Prev = NewNode;

    NewNode->Prev = Cur_Node;
    Cur_Node->Next = NewNode;
}

//Write a program in C to insert a new node at the beginning of a Doubly Linked List.
void Add_Node_End(Node* Tail,Node* Head)
{
    Display(Head);
    Node* Cur = Tail;
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
    {
        return 1;
    }
    printf("What value your want to add : ");
    p->Next = p->Prev = NULL;
    scanf("%d",&(p->Value));
    Cur->Next = p;
    p->Prev = Cur;

}



////Write a program in C to delete first node of Doubly Linked List. 
Node* Delete_First_Node(Node* head)
{
    Node* Cur_Node = head;
    Display(Cur_Node);
    printf("Data of node 1 which is being deleted is : %d\n",Cur_Node->Value);
    printf("Data after deletion of first note \n");
    Cur_Node->Next->Prev = NULL;
    free(Cur_Node);
    return Cur_Node->Next;
}

// Write a program in C to delete a node from the middle of Doubly Linked List.
void Delete(Node* Head)
{
    int n;
    Node* Cur_Node = Head;
    Display(Cur_Node);
    printf("Input the position of node to delete : ");
    scanf("%d",&n);
    for(int i=2; i < n; i++) 
    {
        if(Cur_Node->Next != NULL) {
        Cur_Node = Cur_Node->Next;
        }
    }
    Cur_Node->Next = Cur_Node->Next->Prev;
    Cur_Node->Next->Prev = Cur_Node->Next;
    free(Cur_Node);
}

//Write a program in C to delete the last node of Doubly Linked List.
Node* Delete_Last_Node(Node* Tail)
{
    Node* Cur_Node = Tail;
    Display(Cur_Node);
    printf("Data of last node which is being deleted is : %d\n",Cur_Node->Value);
    printf("Data after deletion of first note \n");
    Cur_Node->Prev->Next = NULL;
    free(Cur_Node);
    return Cur_Node->Prev;
}

