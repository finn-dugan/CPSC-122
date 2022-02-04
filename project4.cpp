/* 
Name: Louis Cerda and Finn Dugan
Class: CPSC 122 Section 1
Date: 1.21.22
Assignment: Project 4
Description:
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int keyGen();
char encrypt(char ch, int key);
char decrypt(char ch, int key);
void generateKey(fstream& keyFile);
void fileOpen(fstream&, string name, char mode);
void encryptFile(fstream& plainText, fstream& encryptText);
void decryptFile(fstream& encryptText, fstream& decryptText);


int main (int argc, char* argv[])
{
    fstream plainText, encryptText, decryptText, keyFile;

    int value = atoi(argv[1]);

    switch(value)
    {
        case 0: keyGen(argv[2]);  // generate the key
        case 1: encrypt(argv[2]); // encrypt plaintext
        case 2: decrypt(argv[2]); // decrypt ciphertext
    }

    return 0;
}

/*
go case by case depending on what argv[1] is 
so change argv[1]  to an integer
then you go into the case swtich loop
and from there you put the funciton that is going to be sued
in the funcitons you can use argv[3][4] inot naming the files 
*/

int keyGen()
{
    int randomNum = rand() % 25;

    return randomNum;
}

/*generateKey(string)

*/

char encrypt(char ch, int key)
{
    // array1 string[];

    // for(int i = 0; i < sizeof(array1), i++)
    // {
    //     ch = array1[i] + key;

    //     fileOpen(fout, argv[2], ch);
    // }

    // while(fin.peek() != EOF)
    // {
    //     ch = fin.get();
    //     fileOpen.put(ch);
    // }

    // while(fin.peek() != EOF)
    // {
    //     getline(fin.line, '\n');
    //     line = amend(line);
    //     fout << line << endl;
    // }

    // while(fin.peek() != EOF)
    // {
    //     getchar(fin.ch, '\n');
    //     ch = ch + key;
    //     fout << ch;
    // }

    // if(islower(ch))
    // {
    //     ch -= 32;
    // }

    ch += key;

    if(ch > 90)
    {
        ch -= 26;
    }
    return ch;
}

char decrypt(char ch, int key)
{

    for(int i = 0; i < sizeof(array1), i++)
    {
        ch = (array1[i] - key + 26) % 26;

        fileOpen(fout, argv[2], ch);
    }

    if(ch == ' ')
    {
        return ' ';
    }

    ch -= key;

    if(ch < 65)
    {
        ch += 26;
    }

    return ch;
}

void fileOpen(fstream&, string name, char mode)
{
    string fileType;

    if (mode == 'r')
        fileType = "input";
    if (mode == 'w')
        fileType = "output";

    if (mode == 'r')
        file.open(name, ios::in);  //available thorugh fstream
    if (mode == 'w')
        file.open(name, ios::out);  //available through fstream;

    if (file.fail()) //error condition 
    {
        cout << "Error opening " << fileType << " file" << endl; 
        exit(EXIT_FAILURE);
    }

}


void encryptFile(fstream& plainText, fstream& encryptText)
{
    while(fin.peek() != EOF)
    {
        getchar(fin.ch, '\n');
        ch = ch + key;
        fout << ch;
    }

    if(islower(ch))
    {
        ch -= 32;
    }
}

void decryptFile(fstream& encryptText, fstream& decryptText)
{
    while(fin.peek() != EOF)
    {
        getchar(fin.ch, '\n');
        ch = ch + key;
        fout << ch;
    }

    if(islower(ch))
    {
        ch -= 32;
    }
}