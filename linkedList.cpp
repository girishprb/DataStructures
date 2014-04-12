//Singly linked lists
#include<iostream>
#include<set>
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
public:
    Node * head, *tail;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    //Tested
    //Inserts at the front
    void Push(int val);

    //Tested
    //Pops the first element
    int Pop();

    //Tested
    //Inserts node to the bottom
    void Enqueue(int val);

    //Tested
    //Deletes the last Node
    int Dequeue();

    //Tested
    //Deletes the node at the specified location
    bool Delete(int position);

    //Tested
    //Inserts the node into the specified position
    bool Insert(int val, int position);

    //Tested
    //Resets the Linked list
    //Create a linked list with specified size and optional range
    void Initialize(int size, int min=0, int max=100);

    //Tested
    //returns the length of the current linked list
    int GetLength();

    //Tested
    //Print all the nodes present in the linked list
    void PrintList();

    //Tested
    //Delete all Linked list
    void DeleteAll();

    //Tested
    //Traverse the list to specified position
    Node * TraverseList(int position);

    //Tested
    //Delete repeated values using sets/maps
    void RemoveDuplicates_Set();

    //Tested
    //Delete repeated values using sets/maps
    void RemoveDuplicates_Iter();

    //Tested
    //Print k to last values
    void PrintFromK(int pos);

    //Tested
    //Delete node from middle of the List without using head
    void DeleteFromMiddle(int pos);

    ~LinkedList()
    {
        if(head!=NULL)
            DeleteAll();
    }

};

//Traverse to the required node
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
    Node *node = new Node(val);
    if(head == NULL)
    {
        tail = node;
        head = node;
    }
    else
    {
        node->next = head;
        head = node;
    }

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
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next=node;
        tail = node;
    }
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
    int length = GetLength();
    if(position == 0)
    {
        Pop();
        result = true;
    }
    else if(position == length-1)
    {
        Dequeue();
        result = true;
    }
    else if(position > 0 && position < length)
    {
        Node *current = TraverseList(position-1);
        Node * tmp = current->next;
        current->next = tmp->next;
        delete tmp;
    }
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

//Delete repeated values using sets/maps
void  LinkedList::RemoveDuplicates_Set()
{
    if(head != NULL)
    {
        std::set<int> duplicateSet;
        std::pair<std::set<int>::iterator,bool> ret;
        Node *current = head, *previous = head, *tmp;
        while(current!= NULL)
        {
            ret = duplicateSet.insert(current->value);
            //Collision, duplicate present
            if(ret.second == false)
            {
                previous->next = current->next;
                tmp = current;
                if(tail == current)
                    tail = previous;
                current =current->next;
                delete tmp;
            }
            //No duplicate, normal execution
            else
            {
                previous = current;
                current = current->next;
            }
        }
    }
}

//Delete repeated values using sets/maps
void LinkedList::RemoveDuplicates_Iter()
{
    if(head!= NULL)
    {
        Node *current = head, *runner, *previous;
        while(current!= NULL)
        {
            runner = current->next;
            previous = current;
            while(runner!=NULL)
            {
                if(current->value == runner->value)
                {
                    Node *tmp = runner;
                    previous->next = runner->next;
                    if(tail == runner)
                        tail = runner;
                    runner = runner->next;
                    delete tmp;
                }
                else
                {
                    previous = runner;
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
}

//Print k to last values
void LinkedList::PrintFromK(int pos)
{
    if(head != NULL)
    {
        Node *prev=NULL, *current = head;
        int count = 0;
        while(current != NULL)
        {
            if(count >= pos)
            {
                prev = head->next;

            }
            count++;
            current = current->next;
        }

        if(prev == NULL)
            cout<<"Issue with printing, index out of range"<<endl;

        else
        {
            int length = GetLength();
            while(prev != NULL)
            {
                cout<<"Node "<<length - pos--<<":"<<prev->value<<endl;
                prev = prev->next;
            }
        }
    }
}

//Delete node from middle of the List without using head
void LinkedList::DeleteFromMiddle(int pos)
{
    Node *current = TraverseList(pos);
    if(current != NULL && current->next != NULL)
    {
        current->value = current->next->value;
        current->next = current->next->next;
    }
}

//TODO: get this to work
//Partition around k
LinkedList PartitionAroundK(LinkedList linkedList, int pos)
{
    Node *pivot = linkedList.TraverseList(pos);
    LinkedList *before = new LinkedList();
    LinkedList *after = new LinkedList();
    if(pivot!= NULL)
    {
        Node *current = linkedList.head;
        while(current!=NULL)
        {
            if(current != pivot)
            {
                if(current->value <= pivot->value)
                {
                    (*before).Push(current->value);
                }
                else
                {
                    (*after).Push(current->value);
                }
            }
            current = current->next;
        }
        //before.PrintList();
        //after.PrintList();
        (*before).tail->next = (*after).head;
        linkedList = *before;
    }
    return linkedList;       
}


//Tested
//Computes the sum of two linked lists where each node has 1 digit, list is arranged from LSP(Least significant pos) to MSP(Most sign pos)
LinkedList Summation(LinkedList list1,LinkedList list2)
{
    LinkedList result;
    Node *curr1 = list1.head, *curr2=list2.head;
    int len1 = list1.GetLength();
    int len2 = list2.GetLength();
    int count = 0;
    int max = len1>len2?len1:len2;
    int sum, carry=0;
    while (count != max)
    {
        sum = carry;
        //take value from first list
        if(curr1 != NULL)
        {
            sum += curr1->value;
            curr1 = curr1->next;
        }

        //Take value from the second list
        if(curr2 != NULL)
        {
            sum += curr2->value;
            curr2 = curr2->next;
        }

        //compute the new carry to be used in the next iteration
        carry = sum /10;

        //Compute the value to be held in units place
        sum = sum %10;

        //Add the value to the result list
        result.Enqueue(sum);
        count++;
    }

    if(carry!=0)
        result.Enqueue(carry);

    return result;
}

int main()
{
    
    return 0;

    ////SUMMATION
    // LinkedList linkedList1, linkedList2;
    // linkedList1.Initialize(4, 0, 9);
    // linkedList1.Enqueue(9);
    // cout<<"List 1"<<endl;
    // linkedList1.PrintList();
    // linkedList2.Initialize(4, 0, 9);
    // linkedList2.Enqueue(9);
    // cout<<"List 2"<<endl;
    // linkedList2.PrintList();
    // LinkedList result = Summation(linkedList1, linkedList2);
    // cout<<"result"<<endl;
    // result.PrintList();


    ////PARTITION AROUND k
    // linkedList.PrintList();
    // linkedList=PartitionAroundK(linkedList,7);
    // linkedList.PrintList();

    ////DELETE FROM MIDDLE
    // linkedList.DeleteFromMiddle(5);
    // linkedList.PrintList();


    // PRINT FROM K
    // cout<<"Printing last 11"<<endl;
    // linkedList.PrintFromK(11);

    ////DeDuplicate
    // linkedList.Enqueue(20);
    // linkedList.Enqueue(20);
    // linkedList.Enqueue(20);
    // linkedList.Push(20);
    // linkedList.PrintList();
    // linkedList.RemoveDuplicates_Iter();


    ////DELETE
    // linkedList.Delete(5);
    // cout<<"After deletion"<<endl;
    // linkedList.PrintList();

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
