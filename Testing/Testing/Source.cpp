#include <iostream>
#include <string>
#include <vector>
#include <sstream>//FIXME: stringstream library
#include <iomanip>//FIXME: stream manipulation library
#include <cctype>
using namespace std;

int main() {

    int tempInt;
    int size;
    int commaCount;
    string str;
    string dataTitle;
    string column1;
    string column2;
    string userString;
    string tempString;
    vector<string> dataPointString;
    vector<int> dataPointInt;

    cout << "Enter a title for the data:" << endl;
    getline(cin, dataTitle);
    cout << "You entered: " << dataTitle << endl << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, column1);
    cout << "You entered: " << column1 << endl << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, column2);
    cout << "You entered: " << column2 << endl << endl;

    cout << "Enter a data point (-1 to stop input):" << endl;
    getline(cin, userString);

    while (userString != "-1")
    {
        commaCount = 0;
        str = userString;
        size = str.size();

        if (str.find(',') == string::npos)
        {
            cout << "Error: No comma in string." << endl << endl;
            cout << "Enter a data point (-1 to stop input):" << endl;
            getline(cin, userString);
        }
        else
        {
            while (str.find(',') != string::npos)
            {
                commaCount++;
                str.replace(str.find(','), 1, " ");
            }
        }

        if (commaCount > 1)
        {
            cout << "Error: Too many commas in input." << endl << endl;
            cout << "Enter a data point (-1 to stop input):" << endl;
            getline(cin, userString);
        }
        else if (commaCount == 1)
        {
            size = userString.size();

            istringstream inSS(userString);

            getline(inSS, tempString, ',');
            inSS >> tempInt;

            if (inSS.fail())
            {
                inSS.clear();
                inSS.ignore(1000, '\n');
                cout << "Error: Comma not followed by an integer." << endl << endl;
            }
            else
            {
                dataPointString.push_back(tempString);
                dataPointInt.push_back(tempInt);

                size = dataPointString.size();

                cout << "Data string: " << dataPointString.at(size - 1) << endl;
                cout << "Data integer: " << dataPointInt.at(size - 1) << endl << endl;
            }
        }

        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, userString);
    }

    cout << endl;

    cout << setw(33) << right << dataTitle << endl;
    cout << setw(20) << left << column1;
    cout << "|";
    cout << setw(23) << right << column2 << endl;
    cout << "--------------------------------------------" << endl;

    for (int a = 0; a < size; a++)
    {
        cout << setw(20) << left << dataPointString.at(a);
        cout << "|";
        cout << setw(23) << right << dataPointInt.at(a) << endl;
    }



    /* Type code here. */

    return 0;
}