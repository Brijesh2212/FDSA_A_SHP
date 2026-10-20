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
        int id;
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);

        int index;

        for(int j=0;j<10;j++)
        {
            index = (h1 + j * h2) % 10;

            if(table[index] == -1)
            {
                table[index] = id;
                break;
            }
        }
    }

    cout << "Hash Table:" << endl;

    for(int i=0;i<10;i++)
    {
        if(table[i] == -1)
            cout << i << " : Empty" << endl;
        else
            cout << i << " : " << table[i] << endl;
    }

    return 0;
}