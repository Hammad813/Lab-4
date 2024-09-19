#include <iostream>
#include <string>
using namespace std;
struct Contact
{
    string name;
    string phoneNumber;
};
int linearSearch(Contact contacts[], int n, string targetName)
{
    for (int i = 0; i < n; i++)
    {
        if (contacts[i].name == targetName)
        {
            return i;
        }
    }
    return -1;
}
void sortContacts(Contact contacts[], int n)
{
    for (int i = 0; i < n ; i++)
    {
        for (int j = i+1 ; j < n ; j++)
        {
            if (contacts[i].name > contacts[j].name)
            {
                Contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
}

int binarySearch(Contact contacts[], int low, int high, string targetName)
{
    if (low > high)
    {
        return -1; // Not found
    }
    int mid = (low + high) / 2;
    if (contacts[mid].name == targetName)
    {
        return mid;
    }
    else if (contacts[mid].name > targetName)
    {
        return binarySearch(contacts, low, mid - 1, targetName);
    }
    else
    {
        return binarySearch(contacts, mid + 1, high, targetName);
    }
}
int main()
{
    int n;
    cout << "Enter the number of contacts: ";
    cin >> n;
    Contact contacts[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter name for contact " << i + 1 << ": ";
        cin >> contacts[i].name;
        cout << "Enter phone number for contact " << i + 1 << ": ";
        cin >> contacts[i].phoneNumber;
    }

    string targetName;
    cout << "Enter the name to search for: ";
    cin >> targetName;

    int linearResult = linearSearch(contacts, n, targetName);
    if (linearResult != -1)
    {
        cout << "Found using Linear Search at index " << linearResult
             << " with phone number: " << contacts[linearResult].phoneNumber << endl;
    }
    else
    {
        cout << "Not found using Linear Search." << endl;
    }
    sortContacts(contacts, n);
    int binaryResult = binarySearch(contacts, 0, n - 1, targetName);
    if (binaryResult != -1)
    {
        cout << "Found using Binary Search at index " << binaryResult
             << " with phone number: " << contacts[binaryResult].phoneNumber << endl;
    }
    else
    {
        cout << "Not found using Binary Search." << endl;
    }
    return 0;
}