#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    string temp = "";
    string longest = "";
    int maxLength = 0;
    int count = 0;

    for (int i = 0; i <= s.length(); i++)
    {
        if (i == s.length() || s[i] == ' ')
        {
            if (count > maxLength)
            {
                maxLength = count;
                longest = temp;
            }

            temp = "";
            count = 0;
        }
        else
        {
            temp = temp + s[i];
            count++;
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Number of characters: " << maxLength << endl;

    return 0;
}