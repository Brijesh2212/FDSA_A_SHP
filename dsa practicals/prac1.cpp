#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
   int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

   int h;
    cin >> h;

    int k = h % n;

    for(int i = k; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for(int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}


