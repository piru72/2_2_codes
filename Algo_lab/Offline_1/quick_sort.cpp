#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10] = {1, 2, 8, 3, 11, 5, 23, 7, 9, 12};

int Partition(int *a, int m, int p)
{

    // int mid = (m + p) / 2;
    // int u = a[(m + p) / 2];
    int u = a[m];
    int i = m;
    int j = p;
    while (i <= j)
    {
        i = i + 1;
        while (a[i] < u)
        {
            i = i + 1;
        }
        j = j - 1;
        while (a[j] > u)
        {
            j = j - 1;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    a[m] = a[j];
    a[j] = u;
    return j;
}

void quickSort(int p, int q)
{
    if (p < q)
    {
        int j = Partition(a, p, q + 1);
        quickSort(p, j - 1);
        quickSort(j + 1, q);
    }
}
int main()
{
    int size = sizeof(a) / sizeof(a[0]);
    int lowest_index = 0;
    int highest_index = size - 1;

    // cout << "Input the array size : " << endl;

    // int size;
    // cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> a[i];
    // }

    cout << "The unsorted array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    quickSort(lowest_index, highest_index);

    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
