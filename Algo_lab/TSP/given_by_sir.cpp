#include<bits/stdc++.h>

using namespace std;
//step 5

//typedef vector<int> vector1;
typedef vector<vector<int> > myVector1;
priority_queue<pair<int,myVector1> > testPQwPV;

int main()
{
    int k, temp=0,temp3, temp4, temp5, n;
    cin>>n;
    //myVector.push_back(10);
    //myVector.push_back(20);
    //myVector.push_back(30);
    for(k=0;k<n;k++)
    {
        //cout<<"enter all values "<<endl;
        //cin>>temp3>>temp4>>temp5;
        vector<vector<int> > myVector;
        for(int i=0; i<n; i++){
            vector<int> row;
            for(int j=0; j<n; j++){
              cin>>temp;
              row.push_back(temp);
            }
            myVector.push_back(row);
        }
        testPQwPV.push(make_pair(k, myVector));
        //dtestPQ.push(make_pair(temp3,make_pair(temp4,temp5)));
    }

    for(k=0;k<n;k++)
    {

        cout<<k<<" PAIR IN PAIR VALUES ARE"<<endl;
        cout<<testPQwPV.top().first<< endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<testPQwPV.top().second[i][j]<<" ";
            }
            cout<<endl;
        }
        testPQwPV.pop();
    }
    return 0;
}