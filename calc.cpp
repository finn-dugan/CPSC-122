#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
    inFix = new char[strlen(argvIn) + 1];
    strcpy(inFix, argvIn);
    if(!CheckTokens())
    {
        cout << "Error: Invalid input" << endl;
        exit(EXIT_FAILURE);
    }
    //CheckParens
    if(!CheckParens())
    {
        cout << "Error: Invalid input" << endl;
        exit(EXIT_FAILURE);
    }

    //MakeValueTbl
    MakeValueTbl();
    //Parse
    Parse();
}

Calc::~Calc()
{
    stk->~Stack();
    valueIdx = 0;
    delete [] valueTbl;
    delete [] inFix;
}

bool Calc::CheckTokens()
{
 for(int i = 0; i < strlen(inFix); i++)
    {
        if(inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' || inFix[i] == '/' || inFix[i] == '^' || inFix[i] == '(' || inFix[i] == ')')
        {
            continue;
        }
        else if(inFix[i] >= 'A' && inFix[i] <= 'Z')
        {
            continue;
        }
        else if(inFix[i] >= '0' && inFix[i] <= '9')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void Calc::MakeValueTbl()
{
    valueTbl = new int[26];
    for(int i = 0; i < 26; i++)
    {
        valueTbl[i] = 0;
    }
    valueIdx = 0;
}

void Calc::Parse()
{
    int len = strlen(inFix);
    char *temp = new char[len + 1];
    int inFixIdx = 0;
    int tmpIdx = 0;


    while (inFix[inFixIdx] != '\0')
    {
      if (isdigit(inFix[inFixIdx])) // Okay cool its a number
      {
        if (temp >= 65 && temp <= (65 + 26))
      strncat(tmp, &temp, 1);
        if (temp == '(')
      stk->Push(temp);
        if ((temp == '*') || (temp == '/') || (temp == '+') || (temp == '-'))
      stk->Push(temp);
        if (temp == ')')
        {
      while (stk->Peek() != '(')
      {
         char temp2 = stk->Peek();
         strncat(tmp, &temp2, 1);
         stk->Pop();
      }
      stk->Pop();
        }
      }
      else // Uh oh it isnt a number
      {
         tmp[tmpIdx] = inFix[inFixIdx];
         inFixIdx++;
         tmpIdx++;
      }
   }
    delete[] inFix;
    inFix = tmp;
    tmp = NULL;
    // //1. space for inFix expression is dynamically allocated 
    // char* inFixCopy = new char[strlen(inFix) + 1];
    // strcpy(inFixCopy, inFix);
    // //2. inFixCopy is copied to inFix
    // strcpy(inFix, inFixCopy);
    // //3. inFixCopy is deleted
    // delete [] inFixCopy;
    // //4. inFix is parsed
    // for(int i = 0; i < strlen(inFix); i++)
    // {
    //     if(inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' || inFix[i] == '/')
    //     {
    //         stk->Push(inFix[i]);
    //     }
    //     else if(inFix[i] >= 'A' && inFix[i] <= 'Z')
    //     {
    //         stk->Push(inFix[i]);
    //     }
    //     else if(inFix[i] >= '0' && inFix[i] <= '9')
    //     {
    //         stk->Push(inFix[i]);
    //     }
    //     else if(inFix[i] == '(')
    //     {
    //         stk->Push(inFix[i]);
    //     }
    //     else if(inFix[i] == ')')
    //     {
    //         while(stk->Peek() != '(')
    //         {
    //             stk->Pop();
    //         }
    //         stk->Pop();
    //     }
    // }
    // //5. while the stack is not empty, pop the stack and push the popped value to the output stack
    // while(!stk->IsEmpty())
    // {
    //     stk->Pop();
    // }
}

bool Calc::CheckParens()
{
    int leftParens = 0;
    int rightParens = 0;
    for(int i = 0; i < strlen(inFix); i++)
    {
        if(inFix[i] == '(')
        {
            leftParens++;
        }
        else if(inFix[i] == ')')
        {
            rightParens++;
        }
    }
    if(leftParens == rightParens)
    {
        return true;
    }
    else
    {
        return false;
    }
 return true;
}

void Calc::DisplayInFix()
{
    cout << inFix << endl;
}

  /*
  pre: instance of Calc exists.  All tokens are legal and parens are balanced.
  post: postFix points to a dynamically declared array holding the postfix version
        of the the input infix expression.
 */
void Calc::InFixToPostFix()
{
    int len = strlen(inFix);
    char* temp = new char[len + 1];

    for(int i = 0; inFix[i] != '\0'; i++)
    {
        char temp = inFix[i];
    
    if (temp >= 65 && temp <= (65 + 26))
      strncat(tmp, &temp, 1);
    if (temp == '(')
      stk->Push(temp);
    if ((temp == '*') || (temp == '/') || (temp == '+') || (temp == '-'))
      stk->Push(temp);
    if (temp == ')')
    {
      while (stk->Peek() != '(')
      {
         char temp2 = stk->Peek();
         strncat(tmp, &temp2, 1);
         stk->Pop();
      }
      stk->Pop();
    }

    }
}

void Calc::DisplayPostFix()
{
    cout << postFix << endl;
}

int Calc::Evaluate()
{
 return 0;
}