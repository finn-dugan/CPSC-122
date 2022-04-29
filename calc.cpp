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
    char* temp = new char[strlen(inFix)];
    strcpy(temp, inFix);
    delete [] inFix;
    inFix = new char[strlen(temp)];
    // int alpha = 65;
    
    // for(int i = 0; i < strlen(temp); i++)
    // {
    //     if(temp[i] == ' ')
    //     {
    //         continue;
    //     }
        // if(temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/')
        // {
        //     inFix[i] = temp[i];
        // }
        // else if(temp[i] == '(')
        // {
        //     inFix[i] = temp[i];
        //     stk->Peek();
        //     stk->Push(temp[i]);
        // }
        // else if(temp[i] == ')')
        // {
        //     inFix[i] = temp[i];
        //     stk->Peek();
        //     stk->Pop();
        // }
        // else if(temp[i] >=0))
        // {
        //     inFix[i] = temp[i];
        // }

        int i = 0;
        while (temp[i] != '/0')
        {
            // if operand add to the postfix expression
            if(inFix[i]>='a' && inFix[i]<='z'|| inFix[i]>='A'&& inFix[i]<='Z')          
            {
                postFix += inFix[i];
                i++;
            }
            // if opening bracket then push the stack
            else if(inFix[i]=='(')
            {
                stk->Push(inFix[i]);
                i++;
            }
            // if closing bracket then pop the stack
            else if(inFix[i]==')')
            {
                stk->Pop();
                i++;
            }
            // if operator then pop the stack and add to the postfix expression
            else if(inFix[i]=='+'||inFix[i]=='-'||inFix[i]=='*'||inFix[i]=='/')
            {
                stk->Pop();
                postFix += inFix[i];
                i++;
            }
        }
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
// void Calc::InFixToPostFix()
// {    
//     int len = strlen(inFix);
//     char* temp = new char[len + 1];

//     for(int i = 0; inFix[i] != '\0'; i++)
//     {
//         char temp = inFix[i];
    
//     if (temp >= 65 && temp <= (65 + 26))
//       strncat(temp, &temp, 1);
//     if (temp == '(')
//       stk->Push(temp);
//     if ((temp == '*') || (temp == '/') || (temp == '+') || (temp == '-'))
//       stk->Push(temp);
//     if (temp == ')')
//     {
//       while (stk->Peek() != '(')
//       {
//          char temp2 = stk->Peek();
//          strncat(tmp, &temp2, 1);
//          stk->Pop();
//       }
//       stk->Pop();
//     }

//     }
// }

void Calc::DisplayPostFix()
{
    cout << postFix << endl;
}

int Calc::Evaluate()
{
 return 0;
}
