#include <bits/stdc++.h>
using namespace std;
vector <int> yusha[100];
vector<int> status;
stack<int>s;

void inputGraph(int N, int E)
{
    int so,des;
    for(int i=1; i<=E; i++)
    {
        cin>>so>>des;
        yusha[so].push_back(des);
    }
}

void printAM(int N)
{
    for(int i=1; i<=N; i++)
    {
        cout<<"Nodee---: "<<i<<" connected to : ";
        for(int j=0; j<yusha[i].size(); j++)
        {

            cout<<yusha[i][j]<<" ";
        }
        cout<<endl;
    }
}
void addNeighbors(int nodeN)
{
    for(int i=0; i<yusha[nodeN].size(); i++)
    {


        if (status[yusha[nodeN][i]]==1)
        {
            s.push(yusha[nodeN][i]);

            status[yusha[nodeN][i]]=2;
        }
    }
}

void dfs(int source)
{

    s.push(source);
    status[source] = 2;
    while(s.empty()!=true)
    {

        int N;
        N=s.top();
        s.pop();
        cout<<N<<">";
        status[N]=3;
        addNeighbors(N);

    }
}

int main()
{
    int n,e, source;
    //cout<<"Enter NUmber of Nodes: ";
    cin>>n;

    //cout<<"Enter Number of Edges: ";
    cin>>e;

    cout<<"Enter Start: ";
    cin>>source;

    status.assign(n+1,1);

    inputGraph(n,e);
    printAM(n);

    dfs(source);
    return 0;
}