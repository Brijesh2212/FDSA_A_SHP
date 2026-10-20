#include<iostream>
using namespace std;

int main()
{
    int table[10];

    for(int i=0;i<10;i++)
    {
        table[i] = -1;
    }

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int number;
        cin >> number;

        int index = number % 10;
        int start = index;

        while(table[index] != -1)
        {
            index = (index + 1) % 10;

            if(index == start)
            {
                cout << "Parking Full" << endl;
                break;
            }
        }

        if(table[index] == -1)
        {
            table[index] = number;
        }
    }

    cout << "Parking Slots:" << endl;

    for(int i=0;i<10;i++)
    {
        if(table[i] == -1)
            cout << i << " : Empty" << endl;
        else
            cout << i << " : " << table[i] << endl;
    }

    return 0;
}