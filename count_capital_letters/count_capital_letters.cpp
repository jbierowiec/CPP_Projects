/*Create a proram that will ask the user if he will use a file or not.
If Y or y, it will ask the name of the text file. If it does not exist it will tell display Error.
If the file is present it will count the number of capital letters in the text file.
If the user enters N or n, the user will input a sentence and the program will count the 
capital letters*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void OpenFile(ifstream& inFile);
void CountCaps(ifstream& inFile, int& count);
void CountCaps(string sentence, int& count);
void Display(int count);

int main()
{
    char choice;
    int count = 0;
    string sentence;
    ifstream inFile;
    do
    {
        cout << "Are you using a file for input? (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            OpenFile(inFile);
            CountCaps(inFile, count);
            Display(count);

            return 0;
        }
        else if (choice == 'N' || choice == 'n')
        {
            cout << "Enter your string. Press Enter/Return to end: ";
            cin.ignore();
            getline(cin, sentence);
            CountCaps(sentence, count);
            Display(count);
        }
        else
        {
            cout << "Invalid input - try again." << endl;
        }
        count = 0;
    } while (choice != 'N' && choice != 'n');

    return 0;
}

void OpenFile(ifstream& inFile)
{
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;
    inFile.open(fileName.c_str());
    if (!inFile)
    {
        cout << "Error! File not found. Exiting..." << endl;
        exit(1);
    }
}

void CountCaps(ifstream& inFile, int& count)
{
    char ch;
    inFile.get(ch);
    while (!inFile.eof())
    {
        if (isupper(ch))
        {
            count++;
        }
        inFile.get(ch);
    }
    inFile.close();
}   

void CountCaps(string sentence, int& count)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        if (isupper(sentence[i]))
        {
            count++;
        }
    }
}

void Display(int count)
{
    cout << "The number of capitals in your string is: " << count << endl;
}