#include <iostream>
using namespace std;

void FindDuplicates(string& str) {
    //if a string can contain Null char, use this method instead
    /*string temp = str;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i+1; j < str.size(); j++)
        {
            if (temp[j] != ')') {
                if (toupper(str[j]) == toupper(str[i]))
                {
                    temp[i] = ')';
                    temp[j] = ')';
                }
            }
        }
        if (temp[i] != ')') temp[i] = '(';
    }
    str = temp;*/
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '\0') str[i] = ')'; //if str[i] is already checked, change it to ')' and go to the next one
        else
        {
            bool bFound = false;
            for (int j = i + 1; j < str.size(); j++) //if it's not, compare it to all the chars to the right
            {
                if (toupper(str[j]) == toupper(str[i])) //if a match is found, change bool
                {
                    //cout << "Found str[" << i << "] = " << str[i] << " and str[" << j << "] = " << str[j] << endl; //log
                    bFound = true;
                    str[j] = '\0'; //and change all the matches
                }
            }
            (bFound) ? str[i] = ')' : str[i] = '('; //change str[i] based on bool
        }
    }
}

int main()
{
    string str = "(( @"; //enter the string here
    cout << "Before: " << str << endl;
    FindDuplicates(str); //send and change string by reference
    cout << "After: " << str;
    return 0;
}