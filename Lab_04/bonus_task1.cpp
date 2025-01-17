#include <iostream>
using namespace std;
int find(int arr[], int high, int low, int key)
{
    int mid = (high + low) / 2;
    if (low > high)
        return -1;
    else if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        return find(arr, mid - 1, low, key);
    }
    if (arr[mid] < key)
    {
        return find(arr, high, mid + 1, key);
    }
}
int main()
{
    int size = 6;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value  " << i + 1 << " : ";
        cin >> arr[i];
    }

   for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int key;
    cout << "Enter the value to be searched: ";
    cin >> key;
    int result = find(arr, size - 1, 0, key);
    if (result == -1)
    {
        cout << "Value is not present in array";
    }
    else
    {
        cout << "Value " << key << " is present at index " << result;
    }
}