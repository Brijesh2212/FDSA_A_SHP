#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binarySearchRecursive(arr, mid + 1, high, target);
    }
    else
    {
        return binarySearchRecursive(arr, low, mid - 1, target);
    }
}

int main()
{
    int n;

    cout << "Enter number of book codes: ";
    cin >> n;

    int arr[n];

    cout << "Enter book codes in sorted order:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;

    cout << "Enter book code to search: ";
    cin >> target;

    int result1 = binarySearchIterative(arr, n, target);

    if (result1 != -1)
    {
        cout << "Iterative Binary Search: Book code found at position " << result1 + 1 << endl;
    }
    else
    {
        cout << "Iterative Binary Search: Book code not found." << endl;
    }

    int result2 = binarySearchRecursive(arr, 0, n - 1, target);

    if (result2 != -1)
    {
        cout << "Recursive Binary Search: Book code found at position " << result2 + 1 << endl;
    }
    else
    {
        cout << "Recursive Binary Search: Book code not found." << endl;
    }

    return 0;
}