#include <iostream>
using namespace std;
int linearsearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int size, target;
    cout << "Enter the size of array " << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the array element at index " << i << "\t";
        cin >> arr[i];
    }
    cout << "Enter the target value to search " << endl;
    cin >> target;
    int result = linearsearch(arr, size, target);
    if (result != -1)
    {
        cout << "the key value " << target << " is found at " << result << " index " << endl;
    }
    else
    {
        cout << "The key value " << target << " is not found " << endl;
    }
    return 0;
}