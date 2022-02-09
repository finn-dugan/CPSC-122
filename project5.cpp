/*
Name: Finn Dugan and Louis Cerda
Class: CPSC 122 Section 1
Date: 2.7.22
Assignment: Project 5
Description: 
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ios>

using namespace std;

void keyGen(string);
void fileOpen(fstream&, string, char);\
void fileControl(string keyFile, string fileIn, string fileOut, int mode);
char encrypt(char ch, int alpha, int beta);
char decrypt(char ch, int alpha, int beta, int MI[]);

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

void fileControl(string keyFileName, string fileInName, string fileOutName, int mode)
{
    fstream keyFile, fileIn, fileOut;
    fileOpen(keyFile, keyFileName, 'r');

    if(mode == 1)
    {
        fileOpen(fileIn, fileInName, 'r');
        fileOpen(fileOut, fileOutName, 'w');

        while(fileIn.peek() != EOF)
        {
            string input = " ";
            getline(fileIn, input);

            for(int i = 0; i < input.length(); i++)
                fileOut << encrypt(input[i]);
            
            fileOut << endl;
        }
    }

    if(mode == 2)
    {
        fileOpen(fileIn, fileInName, 'r');
        fileOpen(fileOut, fileOutName, 'w');

        while(fileOut.peek() != EOF)
        {
            string input = " ";
            getline(fileOut, input);

            for(int i = 0; i < input.length(); i++)
                fileOut << decrypt(input[i]);
            
            fileOut << endl;
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

    
}

char decrypt(char ch, int alpha, int beta, int MI[])
{
    

}