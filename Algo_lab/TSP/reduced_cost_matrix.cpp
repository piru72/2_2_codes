
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[7];

queue<int> min_costs_queue[2];
int min_col = 5;
int min_row = 6;
int user_infinity = 101;
int base_cost = 0;
int total_nodes = 5;

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

void find_minimum_going_cost(int i)
{
    int minimum_cost = *min_element(graph[i].begin(), graph[i].end());
    min_costs_queue[0].push(minimum_cost);
}

void find_minimum_backing_cost(int j)
{
    int minimum_cost = user_infinity;
    for (int i = 1; i <= total_nodes; i++)
    {

        if (graph[i][j] < minimum_cost)
        {
            minimum_cost = graph[i][j];
        }
    }

    min_costs_queue[1].push(minimum_cost);
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

void initial_reduced_matrix(int i)
{

    for (int j = 0; j < graph[i].size(); j++)
    {

        if (i - 1 != j)
        {
            graph[i][j] -= min_costs_queue[0].front();
        }
    }
    base_cost += min_costs_queue[0].front();
    min_costs_queue[0].pop();
}

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

void final_reduced_matrix(int j)
{
    for (int i = 1; i <= total_nodes; i++)
    {
        if (i - 1 != j)
        {
            graph[i][j] -= min_costs_queue[1].front();
        }
    }
    base_cost += min_costs_queue[1].front();
    min_costs_queue[1].pop();
}

void reduced_cost_matrix();
void set_source_node_row_infinity(int source_node)
{
    int i = source_node ;

    for (int j = 0 ; j < graph[i].size();j++)
    {
        graph[i][j] = user_infinity;
    }
}
int main()
{
    sample_graph();
    reduced_cost_matrix();
    int source_node = 1 ;
    set_source_node_row_infinity(source_node);
    print_graph(total_nodes);
}

void reduced_cost_matrix()
{
    // cout << "\nUser given sample graph" <<endl;
    // print_graph(5);

    for (int i = 1; i <= total_nodes; i++)
    {
        find_minimum_going_cost(i);
    }
    // cout << "\nMinimum going cost of person " <<endl;
    // print_graph(total_nodes);

    // showq(min_costs_queue[0]);
    for (int i = 1; i <= total_nodes; i++)
    {
        initial_reduced_matrix(i);
    }

    // cout << "\nInitial reduced matrix " <<endl;
    // print_graph(total_nodes);

    // cout << "\nMinimum backing cost of person " <<endl;

    for (int i = 0; i < total_nodes; i++)
    {
        find_minimum_backing_cost(i);
    }

    // showq(min_costs_queue[1]);

    for (int i = 0; i < total_nodes; i++)
    {
        final_reduced_matrix(i);
    }

    cout << "\nFinal reduced matrix " << endl;
    print_graph(total_nodes);

    cout << " \n The base cost is " << base_cost << endl;
}
