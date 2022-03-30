#include <iostream>
using namespace std;

#include "3-ListT.h"

int main()
{

// testing deleteItemH
/*
  //Static list 
     ListT lst;
     for (int i = 0; i < 5; i++) 
        lst.PutItemH(i);
     lst.Print();
     cout << endl;
     lst.DeleteItemH();
     cout << endl;
     lst.Print();
     cout << endl;

  //Dynamic list 
     ListT* lst1 = new ListT;
     for (int i = 0; i < 5; i++)
        lst1->PutItemH(10*i);
     lst1->Print();
     cout << endl;
     lst1->DeleteItemH();
     cout << endl;
     lst1->Print();
*/
// testing getlength
/*
 //Static list 
     ListT lst;
     for (int i = 0; i < 5; i++) 
        lst.PutItemH(i);
     lst.Print();
     cout << "The length of the linked list is:" << lst.GetLength() << endl;
     cout << endl;

 //Dynamic list 
     ListT* lst1 = new ListT;
     for (int i = 0; i < 5; i++)
        lst1->PutItemH(10*i);
     lst1->Print();
     cout << "The length of the linked list is:" << lst1->GetLength() << endl;
     cout << endl;
*/
// testing isEmpty
/*
 //Static list 
     ListT lst;
     for (int i = 0; i < 5; i++) 
        lst.PutItemH(i);
     lst.Print();
     if (lst.IsEmpty())
        cout << "The list is empty.";
     else
        cout << "The list is not empty.";
     cout << endl;

 //Dynamic list 
     ListT* lst1 = new ListT;
     for (int i = 0; i < 5; i++)
        lst1->PutItemH(10*i);
     lst1->Print();
     if (lst1->IsEmpty())
        cout << "The list is empty.";
     else
        cout << "The list is not empty.";
     cout << endl;
*/
 //Static list
/*    
     ListT lst;
     for (int i = 0; i < 5; i++) 
        lst.PutItemH(i);
     lst.Print();
     itemType conetents1 = lst.GetItemH();
     cout << "Contents pointed to by the head of the list is: " << conetents1;
     cout << endl;

 //Dynamic list 
     ListT* lst1 = new ListT;
     for (int i = 0; i < 5; i++)
        lst1->PutItemH(10*i);
     lst1->Print();
     itemType conetents2 = lst1->GetItemH();
     cout << "Contents pointed to by the head of the list is: " << conetents2;
     cout << endl;
*/
 // testing find
/*
    //Static list 
     ListT lst;
     for (int i = 0; i < 5; i++) 
        lst.PutItemH(i);
     lst.Print();
     cout << "Number of times 3 is found in the list is:  " << lst.Find(3);
     cout << endl;

 //Dynamic list 
     ListT* lst1 = new ListT;
     for (int i = 0; i < 5; i++)
        lst1->PutItemH(10*i);
     lst1->Print();
     cout << "Number of times 3 is found in the list is:  " << lst1->Find(3);;
     cout << endl;
*/
// testing DeleteItem

//Static list
/* 
     ListT lst;
     for (int i = 0; i < 5; i++) 
        lst.PutItemH(i);
     lst.Print();
     cout << "The number of items deleted that stored 3 were: " << lst.DeleteItem(3);
     cout << endl;

 //Dynamic list 
     ListT* lst1 = new ListT;
     for (int i = 0; i < 5; i++)
        lst1->PutItemH(10*i);
     lst1->Print();
     cout << "The number of items deleted that stored 3 were: " << lst1->DeleteItem(3);
     cout << endl;
*/

//getItem test
/*
    // Static list
     ListT lst;
     for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
     lst.Print();
     cout << "The item stored in Head is: " << lst.GetItemH() << endl;

 // Dynamic list
     ListT* lst1 = new ListT;
     for (int i = 0; i < 5; i++)
        lst1->PutItemH(10*i);
     lst1->Print();
     cout << "The item stored in Head is: " << lst1->GetItemH() << endl;
     cout << endl;
*/

//PutItemT test
/*
    // Static list
     ListT lst;
     for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
     lst.Print();

     cout << "this is the new list: " << endl;
     lst.PutItemT(5);
     lst.Print();

    cout << "-------------------------------------------------" << endl;
    // Dynamic list
        ListT* lst1 = new ListT;
        for (int i = 0; i < 5; i++)
            lst1->PutItemH(10*i);
        lst1->Print();

        cout << "this is the new list: " << endl;
        lst1->PutItemT(5);
        lst1->Print();
        cout << endl;

*/
//GetItemT test
/*
    // Static list
     ListT lst;
     for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
     lst.Print();
     cout << "The item stored in Tail is: " << lst.GetItemT() << endl;

    // Dynamic list
     ListT* lst1 = new ListT;
     for (int i = 0; i < 5; i++)
        lst1->PutItemH(10*i);
     lst1->Print();
     cout << "The item stored in Tail is: " << lst1->GetItemT() << endl;
     cout << endl;
*/

//DeleteItemT test

    // Static list
     ListT lst;
     for (int i = 0; i < 5; i++)
        lst.PutItemH(i);
     lst.Print();
     lst.DeleteItemT();
     lst.Print();
     cout << endl;

    // Dynamic list
    //  ListT* lst1 = new ListT;
    //  for (int i = 0; i < 5; i++)
    //     lst1->PutItemH(10*i);
    //  lst1->Print();
    //  cout << "The number of items deleted that stored 3 were: " << lst1->DeleteItemT();
    //  cout << endl;


 //delete lst1; //necessary to invoke destructor on dynamic list
 cout << endl;
 return 0;
}