// write a code to implement binary search

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> user_input;
int main()
{

    user_input.push_back(10);
    user_input.push_back(30);
    user_input.push_back(5);
    user_input.push_back(1000);
    user_input.push_back(9);
    user_input.push_back(20);

    int key = 7;

    int i = 0;
    int j = 0;
    int mid = 0;

    int flag = 0;

    int n = user_input.size();

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        mid = (start + end) / 2;


        cout << "mid = " << mid << "user input mid - 1 " << user_input[mid - 1] << endl;

        if (user_input[mid - 1] <= key && user_input[mid] <= key)
        {
            flag = 1;
            break;
        }
        else if (user_input[mid] <= key && user_input[mid + 1] <= key)
        {
            flag = 1;
            break;
        }
        else if (user_input[mid] < key)
        {
            start = mid + 1;
        }
        else if (user_input[mid] > key)
        {
            end = mid - 1;
        }
    }

    if (flag == 1)
    {
        cout << "Element found at index " << mid << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}