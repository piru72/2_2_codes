#include<bits/stdc++.h>
using namespace std;
void quick_sort(int ar[],int p,int q);
int partition_(int arr[],int a, int b);
int main()
{
    int a[8]={2,8,7,1,3,5,6,4};
    int l,u;
    l = 0;
    u = 7;
    quick_sort(a,l,u);

    for(int i=7; i>=0; i--)
    {
        cout<<a[i]<<endl;
    }

 return 0;
}
void quick_sort(int ar[],int p,int q)
{
    int j;
    if(p < q)
    {

      j = partition_(ar,p,q);
      quick_sort(ar,p,j-1);
      quick_sort(ar,j+1,q);

    }
}
int partition_(int arr[],int m, int p)
{
    int x,i,j;

   x = arr[m];
   i = m;
   j =p;
   while(i <= j)
   {
       while(arr[i] >= x)
       {
           i++;
       }
       while(arr[j] <= x)
       {
           j--;
       }
       if(i < j)
    {
        swap(arr[i],arr[j]);
    }

   }
   arr[m] = arr[j];
   arr[j] = x;
   return j;
}