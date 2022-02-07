#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


// Write a program in C to create and display Singly Linked List
typedef struct Node
{
    int number;
    struct Node *next;
}Node;

Node * CreateLinkedList(int n);
void Display(Node* head);
void Display_Reverse(Node* head);
Node * Add_Node_Beginning(Node* head);
void Add_Node_The_End(Node* head);
void Inserting(Node* head);
Node* Delete_First_Node(Node* head);
void Delete_Middle_Node(Node* head);
void Delete_Last_Node(Node* head);
void freeList(struct Node* head);
void Search_Element(Node* head);



int main(void)
{
    system("cls");
    int n = 0 ;
    Node* Head = NULL;
    printf("Input the number of nodes :");
    scanf("%d",&n);
    Head = CreateLinkedList(n);
    // Head = Add_Node_Beginning(Head);
    // Head = Delete_First_Node(Head);
    Search_Element(Head);
    freeList(Head);
    return 0;
}

//Write a program in C to create and display Singly Linked List.
Node * CreateLinkedList(int n)
{
    Node* head = NULL;
    Node* temp = NULL;
    Node* p = NULL;
    for (int i = 0 ; i < n ; i++)
    {
        // Initial the temp node
        temp = (Node*)malloc(sizeof(Node));
        printf("Input data for node %d :",i+1);
        scanf("%d",&(temp->number));
        temp->next = NULL;
        // Start the an array
        if(head == NULL)
        {
            head = temp;
        }

        else
        {
            // Assign a next node equal the next node 
            p = head;
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
        
    }
    return head;
}

// Free space after allocate
void FreeList(Node* head)
{
   struct node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
    free(tmp);

}

// Print out the value in the list 
void Display(Node* head)
{

    Node* tmp = head;
    while (tmp != NULL)
    {
        printf("The data = %d\n",tmp->number);
        tmp = tmp->next; 
    }
    
}

//Write a program in C to create a singly linked list of n nodes and display it in reverse order.
void Display_Reverse(Node* head)
{
    if(head == NULL)
    {
        return 0;
    }
    Display_Reverse(head->next);
    printf("%d ", head->number);
}

//Write a program in C to insert a new node at the beginning of a Singly Linked List.
Node * Add_Node_Beginning(Node* head)
{
    Node* p = (Node*)malloc(sizeof(Node));
    printf("What value your want to add : \n");
    scanf("%d",&(p->number));
    p->next = head;
    return p;
}

//Write a program in C to insert a new node at the middle of Singly Linked List
void Add_Node_Middle(Node* head)
{
    int n;
    int i;
    Node* Cur_Node = head;
    Display(Cur_Node);
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->next = NULL;
    printf("What value your want to add : ");
    scanf("%d",&(NewNode->number));
    if (Cur_Node == NULL && NewNode == NULL)
    {
        return 0;
    }
    printf("Where do you want to put : ");
    scanf("%d",&n);
    for(int i=2; i <= n - 1 ; i++) 
    {
        if(Cur_Node->next != NULL) {
        Cur_Node = Cur_Node->next;
        }
    }
    NewNode->next = Cur_Node->next;
    Cur_Node->next = NewNode;
}

//Write a program in C to insert a new node at the end of a Singly Linked
void Add_Node_End(Node* head)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* p = (Node*)malloc(sizeof(Node));
    printf("What value your want to add : ");
    scanf("%d",&(p->number));
    p->next = NULL;
    temp->next = p;
}

//Write a program in C to delete first node of Singly Linked List. 
Node* Delete_First_Node(Node* head)
{
    Node* Cur_Node = head;
    Display(Cur_Node);
    printf("Data of node 1 which is being deleted is : %d\n",Cur_Node->number);
    printf("Data after deletion of first note \n");
    return Cur_Node->next;
    free(Cur_Node);
}

// Write a program in C to delete a node from the middle of Singly Linked List.
void Delete_Middle_Node(Node* head)
{
    int n;
    Node* Cur_Node = head;
    Display(Cur_Node);
    printf("Input the position of node to delete : ");
    scanf("%d",&n);
    for(int i=2; i < n; i++) 
    {
        if(Cur_Node->next != NULL) {
        Cur_Node = Cur_Node->next;
        }
    }
    Cur_Node->next = Cur_Node->next->next;
}

//Write a program in C to delete the last node of Singly Linked List.
void Delete_Last_Node(Node* head)
{
    Node* Cur_Node = head;
    Display(Cur_Node);
    while (Cur_Node->next->next != NULL)
    {
        Cur_Node = Cur_Node->next; 
    }
    printf("The new list after deletion the last node are : %d\n",Cur_Node->number);
    Cur_Node->next = NULL;
    free(Cur_Node); 
}

//Write a program in C to search an existing element in a singly linked list.
void Search_Element(Node* head)
{
    int i,n;
    Node* Cur_Node = head;
    printf("Data entered in the list: \n");
    Display(Cur_Node);
    printf("Input the element to be searched: ");
    scanf("%d",&i);
    while(Cur_Node != NULL)
    {
        
        if (Cur_Node->number == i)
        {

            printf("Element found at node %d\n",n + 1);
            exit(0);
        }
        else{
            Cur_Node = Cur_Node->next;
        }
    }
    printf("The element is not in the list \n");
}