
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[7];
vector<int> vct[7];

void sample_graph()
{

    graph[1].push_back(101);
    graph[1].push_back(20);
    graph[1].push_back(30);
    graph[1].push_back(10);
    graph[1].push_back(11);

    graph[2].push_back(15);
    graph[2].push_back(101);
    graph[2].push_back(16);
    graph[2].push_back(4);
    graph[2].push_back(2);

    graph[3].push_back(3);
    graph[3].push_back(5);
    graph[3].push_back(101);
    graph[3].push_back(2);
    graph[3].push_back(4);

    graph[4].push_back(19);
    graph[4].push_back(6);
    graph[4].push_back(18);
    graph[4].push_back(101);
    graph[4].push_back(3);

    graph[5].push_back(16);
    graph[5].push_back(4);
    graph[5].push_back(7);
    graph[5].push_back(16);
    graph[5].push_back(101);
}

void print_graph(int size)
{
    for (int i = 1; i <= size; i++)
    {

        for (int j = 0; j < graph[i].size(); j++)
        {

            cout << setw(6) << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

int main ()
{
    sample_graph();
    print_graph(5);
}