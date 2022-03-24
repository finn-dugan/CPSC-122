#include <iostream>
using namespace std;

#include "2-List.h"


//Class-related functions
//Constructor
List::List()
{       
 length = 0;
 head = NULL;
}

//Destructor
List::~List()
{
  while(length > 0)
  {
      DeleteItemH();
  }
}

//Head-related functions
void List::PutItemH(itemType item)
{
    node* temp = new node; // declaring a new node
    temp->item = item; // temp points to item which = itemIn
    temp->next = head; 
    head = temp;
    temp = NULL;
    length ++;
}

itemType List::GetItemH() const
{ 
    return head->item; // returns item 
}

void List::DeleteItemH()
{
    node* cur = head;
    head = head->next;
    delete cur;
    length--;
}


//General operations on the class

void List::Print() const
{
    node* cur = head;

    for(int i = 0; i < length; i++)
    {
        cout << cur->item << endl;
        cur = cur->next;
    }
}

bool List::IsEmpty() const
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}

int List::Find(const itemType target) const
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

int List::GetLength() const
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

int List::DeleteItem(const itemType target)
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

// finish getItem test