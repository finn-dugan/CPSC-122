#include <iostream>
using namespace std;

#include "3-ListT.h"


//Class-related functions
//Constructor
ListT::ListT()
{       
 length = 0;
 head = NULL;
}

//Destructor
ListT::~ListT()
{
  while(length > 0)
  {
      DeleteItemH();
  }
}

//Head-related functions
void ListT::PutItemH(itemType item)
{
    node* temp = new node; // declaring a new node
    temp->item = item; // temp points to item which = itemIn
    temp->next = head; 
    head = temp;
    temp = NULL;
    length ++;
}

itemType ListT::GetItemH() const
{ 
    return head->item; // returns item 
}

void ListT::DeleteItemH()
{
    node* cur = head;
    head = head->next;
    delete cur;
    length--;
}

// insert node at tail of linked list
void ListT::PutItemT(const itemType itemIn)
{
    node* temp = new node;
    temp->item = itemIn;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        node* cur = head;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }
    temp = NULL;
    length++;
}

//return item at tail of linked list
itemType ListT::GetItemT() const
{
    node* cur = head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    return cur->item;
}

//delete item at tail of linked list
void ListT::DeleteItemT()
{
    node* cur = head;
    while(cur->next->next != NULL)
    {
        cur = cur->next;
    }
    delete cur->next;
    cur->next = NULL;
    length--;

}

//General operations on the class

void ListT::Print() const
{
    node* cur = head;

    for(int i = 0; i < length; i++)
    {
        cout << cur->item << endl;
        cur = cur->next;
    }
}

bool ListT::IsEmpty() const
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}

int ListT::FindItem(const itemType target) const
{
    node* cur = head;
    int pass = 0;

    while (cur != NULL && cur->next != NULL) // (!cur->target) // if cur isnt pointing to target
    {
        if (cur->item == target)
            pass++;
        cur = cur->next;
    }

    cur = NULL;
    return pass; // returning the # of times the target is hit
}

int ListT::GetLength() const
{
    node* cur = head;
    int length = 0;

    while(cur != NULL && cur->next != NULL)
    {
        length ++;
        cur = cur->next;
    }
    length ++;
    cur = cur->next;

    cur = NULL;
    return length;
}

int ListT::DeleteItem(const itemType target)
{
    int pass = 0;
    node* cur = new node;
    cur = head;

    for(int i = 0; i < length; i++)
    {
        if(cur->item == target)
        {
            node* temp = cur;
            cur = cur->next;
            temp = NULL;
            length--;
            pass++;
        }
        cur = cur->next;
    }
    return pass;
}

node* ListT::PtrTo()
{
    node* temp = new node;
    temp = head;
    while(temp->next != tail->next)
    {
        temp = temp->next;
    }
    return temp;
}