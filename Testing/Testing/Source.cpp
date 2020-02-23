#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int GetNumOfNonWSCharacters(const string userString)
{
    string inputStr = userString;
    int inputStrSize = inputStr.size();
    int characterCount = inputStrSize;

    for (int i = 0; i < inputStrSize; i++)
    {
        if (inputStr.at(i) == ' ')
        {
            characterCount--;
        }
    }

    return characterCount;
}

int GetNumOfWords(string userString)
{
    int wordCount = 1;
    int length = userString.size();
    string userStr = userString;

    for (int i = 0; i < length; i++)
    {
        if (isspace(userStr.at(i)) && !isspace(userStr.at(i + 1)))
            wordCount++;
    }

    return wordCount;
}

int FindText(string stringQuery, string stringQueried)
{
    int length = stringQueried.size();
    int queryMatches = 0;
    string query = stringQuery;

    while (stringQueried.find(query) != string::npos)
    {
        queryMatches++;
    }

    /*for (int i = 0; i < length; i++)
    {
        if (stringQueried.find(query) != string::npos)
            queryMatches++;
    }*/

    return queryMatches;
}

char PrintMenu(string userString)
{
    char menuOption;
    bool isValidEntry = false;
    string usrStr = userString;

    cout << "\nMENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl;

    do
    {
        cout << "\nChoose an option:" << endl;
        cin >> menuOption;

        switch (menuOption)
        {
        case 'q':
        {
            isValidEntry = true;
            break;
        }
        case 'c':
        {
            cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(usrStr) << endl;
            isValidEntry = true;
            break;
        }
        case 'w':
        {
            cout << "Number of words: " << GetNumOfWords(usrStr) << endl;
            isValidEntry = true;
            break;
        }
        case 'f':
        {
            string strQuery;
            cin.ignore();
            cout << "Enter a word or phrase to be found: " << endl;
            cin >> strQuery;
            cout << "\n\"" << strQuery << "\" instances: " << FindText(strQuery, usrStr);
            isValidEntry = true;
            break;
        }
        case 'r':
        case 's':
        {
            isValidEntry = true;
            break;
        }
        default:
        {
            cout << "Invalid entry" << endl;
            isValidEntry = false;
            break;
        }
        }

    } while (isValidEntry == false);



    return menuOption;
}

int main() {

    string userString;
    char userOption;

    cout << "Enter a sample text:";
    getline(cin, userString);

    cout << "\n\nYou entered: " << userString << endl;

    do
    {
        userOption = PrintMenu(userString);

    } while (userOption != 'q');/* Type your code here. */

    return 0;
}