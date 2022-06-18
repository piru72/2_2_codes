//Write a program to sort an array of integers using heap sort using vector.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 vector<int> v;


 void print_vector(vector<int> v)
 {
     for(int i=0; i<v.size(); i++)
     {
         cout<<v[i]<<" ";
     }
    
 }

int main()
{
   
    v.push_back(10);
    v.push_back(30);
    v.push_back(5);
    v.push_back(1000);
    v.push_back(9);
    v.push_back(20);
    cout<<"Before sort function call "<<endl;
    print_vector(v);
   
    cout<<endl;
    return 0;


}