#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    //**********VARIABLE DECLARATIONS**********
    string title;
    string column1;
    string column2;
    string dataPoint;
    int firstComma = 0;
    vector <string> wordInputs;
    vector <int> numberInputs;
    string strData;
    int intData = 0;
    int commaCount;

    //**********INPUT TITLE**********
    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl;

    //**********INPUT COLUMN 1**********
    cout << "Enter the column 1 header:" << endl;
    getline(cin, column1);
    cout << "You entered: " << column1 << endl;

    //**********INPUT COLUMN 2**********
    cout << "Enter the column 2 header:" << endl;
    getline(cin, column2);
    cout << "You entered: " << column2 << endl;

    //**********DATA POINT**********
    while (true) {
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, dataPoint);
        if (dataPoint == "-1") {
            break;
        }
        commaCount = 0;
        for (unsigned int i = 0; i < dataPoint.size(); i++) {
            if (dataPoint.at(i) == ',') {
                commaCount++;
            }
        }
        if (commaCount == 0) {
            cout << "Error: No comma in string." << endl;
        }
        //****Original version that gave me issues****
           //if (dataPoint.find(',') == string::npos){
           // cout << "Error: No comma in string." << endl;
           //}
        else if (commaCount > 1) {
            cout << "Error: Too many commas in input." << endl;
        }
        //****Original version that also gave me issues****
           //(isdigit(dataPoint.find(',', dataPoint.find(','))))
           // to find a second comma
        else {
            firstComma = dataPoint.find(',');
            try {
                strData = dataPoint.substr(0, firstComma);
                intData = stoi(dataPoint.substr(firstComma + 1));
                wordInputs.push_back(strData);
                numberInputs.push_back(intData);
                cout << "Data string: " << strData << endl;
                cout << "Data integer: " << intData << endl;
            }
            catch (std::invalid_argument const&) {
                cout << "Error: Comma not followed by an integer." << endl;
            }
        }
    }

    //**********TABLE**********
    cout << endl;
    cout << setw(33) << title << endl;
    cout << setw(20) << left << column1 << "|" << setw(23) << right << column2 << endl;
    cout << "--------------------------------------------" << endl;
    for (unsigned int i = 0; i < wordInputs.size(); i++) {
        cout << setw(20) << left << wordInputs[i] << "|" << setw(23) << right << numberInputs[i] << endl;
    }
    cout << endl;

    //**********HISTOGRAM**********
    for (unsigned int i = 0; i < wordInputs.size(); i++) {
        cout << setw(20) << wordInputs[i] << " ";
        for (int j = 0; j < numberInputs[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

//**********INSTRUCTOR OUTLINE**********
   /* Overall flow of the program:
   Get some input for the title
   Get some input for column header #1
   Get some input for column header #2

   Until the user types "-1":
   Get input for a string
   Validate input
   If valid...
      Split
      Validate second half of input
      If also valid...
         Store separate pieces

   Print out data in table format

   Print out data in chart format
   */