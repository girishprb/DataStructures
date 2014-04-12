//Singly linked lists
#include<iostream>
#include<stdlib.h>
using namespace std;

//Class for single nodes
class Node
{
public:
    int value;
    Node* next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }

    Node(int val, Node *ptr)
    {
        value = val;
        next = ptr;
    }
};


//Class LinkedList that contains 0 or more Nodes and supports myriad of operations on this list.
class LinkedList
{
    Node * head, *tail;

public:
    //Inserts at the front
    void Push(int val);

    //Pops the first element
    int Pop();

    //Inserts node to the bottom
    void Enqueue(int val);



    //Deletes the last Node
    int Dequeue();

    //Deletes the node at the specified location
    bool Delete(int position);

    //Inserts the node into the specified position
    bool Insert(int val, int position);

    //Resets the Linked list
    //Create a linked list with specified size and optional range
    void Initialize(int size, int min=0, int max=100);

    //returns the length of the current linked list
    int GetLength();

    //Print all the nodes present in the linked list
    void PrintList();

    //Delete all Linked list
    void DeleteAll();

    //Traverse the list to specified position
    Node * TraverseList(int position);

    ~LinkedList()
    {
        if(head!=NULL)
            DeleteAll();
    }

};


Node * LinkedList::TraverseList(int position)
{
    int length = GetLength();
    int index = 0;
    Node * current = NULL;
    if(position >= 0 && position < length)
    {
        current = head;
        while(index != position)
        {
            current = current->next;
            index++;
        }
    }
    return current;
}

//Inserts at the front
void LinkedList::Push(int val)
{
    Node *node = new Node(val, head);
    if(head == NULL)
        tail = node;
    head= node;
}

//Pops the first element
int LinkedList::Pop()
{
    int result;
    Node *tmp;
    if(head != NULL)
    {
        result = head->value;
        tmp = head;
        head = head->next;
        delete tmp;
        if(head == NULL)
            tail = NULL;
    }
    else
        cout<<"Linked List is empty";
    return result;
}


//Inserts node to the bottom
void LinkedList::Enqueue(int val)
{
    Node *node = new Node(val);
    if(head==NULL)
        head = node;
    else
        tail->next=node;
    tail = node;
}

//Deletes the last Node
int LinkedList::Dequeue()
{
    int result;
    int length = GetLength();
    if(length >=2)
    {
        Node *current = TraverseList(length -2);
        result = tail->value;
        Node *tmp = tail;
        tail = current;
        tail->next = NULL;
        delete tmp;
    }
    else if(length == 1)
    {
        result = tail->value;
        Node *tmp = tail;
        tail = NULL;
        head = NULL;
        delete tmp;
    }
    return result;
}

//Deletes the node at the specified location
bool LinkedList::Delete(int position)
{
    bool result = false;
    return result;
}

//Inserts the node into the specified position
bool LinkedList::Insert(int val, int position)
{
    bool result = false;
    if(position == 0)
    {
        Push(val);
        result = true;
    }
    else
    {
        Node *current = TraverseList(position-1);
        bool result = false;
        if(current != NULL)
        {
            Node * nextPtr = current->next;
            Node *newNode = new Node(val, current->next);
            current->next = newNode;
            result = true;
        }
    }
    return result;
}

//Resets the Linked list
//Create a linked list with specified size and optional range
void LinkedList::Initialize(int size, int min, int max)
{
    head = NULL;
    for(int i =0; i<size; i++)
    {
        //Enqueue(min + (rand() % (int)(max + min)));
        Push(min + (rand() % (int)(max + min)));
    }
}

//returns the length of the current linked list
int LinkedList::GetLength()
{
    int count = 0;
    Node * current = head;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

//Print all the nodes present in the linked list
void LinkedList::PrintList()
{
    Node * current = head;
    int i=0;
    if(head == NULL)
        cout<<"Linked list is empty"<<endl;
    else
    {
        while(current != NULL)
        {
            cout<<"Node "<<i++<<":"<<current->value<<endl;
            current = current->next;
        }
    }
}

//Delete all Linked list
void LinkedList::DeleteAll()
{
    Node * current = head;
    Node * tmp;
    while(current != NULL)
    {
        tmp = current;
        current = current->next;
        delete tmp;
    }
    head = NULL;
}


//Tested: Pop
//Tested: PrintList
//Tested: GetLength
//Tested: Enqueue
//Tested: Dequeue
//Tested: Initialize
//Tested: DeleteAll
//Tested: Insert
//Tested: Traverse
int main()
{
    LinkedList linkedList;
    linkedList.Initialize(10);
    linkedList.PrintList();

    return 0;


    ////DEQUEUE
    // cout<<"Dequeue values"<<endl;
    // int len= linkedList.GetLength();
    // for(int i=0; i < len; i++)
    // {
    //     cout<<"Dequeue Node "<<i<<":"<<linkedList.Dequeue()<<endl;
    // }
    // linkedList.PrintList();

    ////INSERT AT
    //bool result = linkedList.Insert(120, 10);

    ////DELETE ALL
    //linkedList.DeleteAll();
    //linkedList.PrintList();

    ////GET LENGTH
    //int len =  linkedList.GetLength();

    ////POP
    // cout<<"Popping values, size of the list is "<<len <<endl;
    // for(int i=0; i < len; i++)
    // {
    //     cout<<"Popped Node "<<i<<":"<<linkedList.Pop()<<endl;
    // }
}
