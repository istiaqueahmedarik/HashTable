#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < pivot; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void qsort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int pos = partition(arr, low, high);
    qsort(arr, low, pos - 1);
    qsort(arr, pos + 1, high);
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    qsort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
}
