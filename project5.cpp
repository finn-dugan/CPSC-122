/*
Name: Finn Dugan and Louis Cerda
Class: CPSC 122 Section 1
Date: 2.7.22
Assignment: Project 5
Description: 
*/

#include <iostream>
#include <ios>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

void keyGen(string);
void fileOpen(fstream&, string, char);
void fileControl(string keyFile, string fileIn, string fileOut, int mode);
char encrypt(char ch, int alpha, int beta);
char decrypt(char ch, int alpha, int beta, int MI[]);
int findInverse(int);

void keyGen(string keyFileName)
{
    fstream keyFile;
    fileOpen(keyFile, keyFileName, 'w');

    int alphaOptions[12] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    int alpha = alphaOptions[rand() % 12];
    int beta = (rand() % 25) + 1;

    keyFile << alpha << endl << beta;
}

void fileOpen(fstream& file, string name, char mode)
//void fileOpen(fstream& file, char name[], char mode)
{
    string fileType;

    if(mode == 'r')
        fileType = "input";
    if(mode == 'w')
        fileType = "output";

    if(mode == 'r')
        file.open(name, ios::in);  //available thorugh fstream
    if(mode == 'w')
        file.open(name, ios::out);  //available through fstream;

    if(file.fail()) //error condition 
    {
        cout << "Error opening " << fileType << " file" << endl; 
        exit(EXIT_FAILURE);
    }
}

int findInverse(int alpha)
{
    int inverse = 0;

    for(int i = 0; i < 26; i++)
    {
        if((alpha * i) % 26 ==1)
        {
            return i;
        }
    }
    
    return -1;
}

void fileControl(string keyFileName, string fileInName, string fileOutName, int mode)
{
    int MI[26];
    fstream keyFile, fileIn, fileOut;
    fileOpen(keyFile, keyFileName, 'r');

    int alpha, beta = 0;
    string input = "";

    keyFile >> alpha;
    getline(keyFile, input);
    keyFile >> beta;

    if(mode == 1)
    {
        fileOpen(fileIn, fileInName, 'r');
        fileOpen(fileOut, fileOutName, 'w');

        while(fileIn.peek() != EOF)
        {
            getline(fileIn, input);

            for(int i = 0; i < input.length(); i++)
                fileOut << encrypt(input[i], alpha, beta);
            
            fileOut << endl;
        }
    }

    if(mode == 2)
    {
        for(int i = 0; i < 26; i++)
        {
            MI[i] = findInverse(alpha);
        }
        fileOpen(fileOut, fileOutName, 'r');
        fileOpen(fileIn, fileInName, 'w');

        while(fileOut.peek() != EOF)
        {
            getline(fileOut, input);

            for(int i = 0; i < input.length(); i++)
            {
                fileIn << decrypt(input[i], alpha, beta, MI);
            }
            fileIn << endl;
        }
    }

    fileOut.close();
    fileIn.close();
}

char encrypt(char ch, int alpha, int beta)
{
    if(ch == ' ')
    {
        return ' ';
    }

    if(islower(ch))
    {
       ch -= 32;
    }

    ch = (char)((((alpha * (ch - 'A')) + beta) % 26) + 'A');

    return ch;
}

char decrypt(char ch, int alpha, int beta, int MI[])
{
    int inverse = MI[alpha];

    if(ch == ' ')
    {
        return ' ';
    }

    ch = (char)(((inverse * ((ch + 'A' - beta)) % 26)) + 'A');

    return ch;
}

int main(int argc, char* argv[])
{
    int mode = atoi(argv[1]);

    if(mode == 0)
    {
        keyGen(argv[2]);
    }
    if(mode == 1 || mode == 2)
    {
        fileControl(argv[2], argv[3], argv[4], mode);
    }
    return 0;
}