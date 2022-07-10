
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
queue<int> min_costs_queue[2];
int user_infinity = 101;
int base_cost = 0;
int total_nodes = 5;

typedef vector<vector<int>> myVector1;
typedef pair<int, myVector1> visited_vector;
typedef pair<int, visited_vector> predecessor;
typedef pair<int, predecessor> base_costs;
priority_queue<base_costs> pq;

int temp_cost;

void sample_graph()
{
    vector<int> g;
    vector<int> empty;
    g.push_back(101);
    g.push_back(20);
    g.push_back(30);
    g.push_back(10);
    g.push_back(11);

    graph.push_back(g);
    g = empty;

    g.push_back(15);
    g.push_back(101);
    g.push_back(16);
    g.push_back(4);
    g.push_back(2);

    graph.push_back(g);
    g = empty;

    g.push_back(3);
    g.push_back(5);
    g.push_back(101);
    g.push_back(2);
    g.push_back(4);

    graph.push_back(g);
    g = empty;

    g.push_back(19);
    g.push_back(6);
    g.push_back(18);
    g.push_back(101);
    g.push_back(3);

    graph.push_back(g);
    g = empty;

    g.push_back(16);
    g.push_back(4);
    g.push_back(7);
    g.push_back(16);
    g.push_back(101);

    graph.push_back(g);
    g = empty;
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

void show_vector(vector<vector<int>> myVector)
{
    for (int i = 0; i < myVector.size(); i++)
    {
        for (int j = 0; j < myVector[i].size(); j++)
        {
            cout << setw(6) << myVector[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> set_row_column_to_infinity(vector<vector<int>> myVector, int row, int column)
{
    for (int i = 0; i < myVector.size(); i++)
    {
        for (int j = 0; j < myVector[i].size(); j++)
        {
            if (i == row)
            {
                myVector[i][j] = 101;
            }
            else if (j == column)
            {
                myVector[i][j] = 101;
            }
        }
    }

    return myVector;
}





void prepare_for_action_2(int, int, vector<vector<int>>);

vector<vector<int>> reduce_matrix(vector<vector<int>> myVector)
{

    for (int i = 0; i < myVector.size(); i++)

    {
        int minimum_cost = *min_element(myVector[i].begin(), myVector[i].end());

        if (minimum_cost == 101)
            min_costs_queue[0].push(0);
        else
            min_costs_queue[0].push(minimum_cost);
    }

    for (int i = 0; i < total_nodes; i++)
    {
        for (int j = 0; j < total_nodes; j++)
        {
            if (myVector[i][j] != user_infinity)
                myVector[i][j] -= min_costs_queue[0].front();
        }
        temp_cost += min_costs_queue[0].front();
        min_costs_queue[0].pop();
    }

    int minimum_cost = user_infinity;

    for (int j = 0; j < total_nodes; j++)
    {
        for (int i = 0; i < total_nodes; i++)
        {

            if (myVector[i][j] < minimum_cost)
            {
                minimum_cost = myVector[i][j];
            }
        }
        if (minimum_cost == 101)
            min_costs_queue[1].push(0);
        else
            min_costs_queue[1].push(minimum_cost);
        minimum_cost = user_infinity;
    }

    for (int j = 0; j < total_nodes; j++)
    {
        for (int i = 0; i < total_nodes; i++)
        {
            if (myVector[i][j] != user_infinity)
                myVector[i][j] -= min_costs_queue[1].front();
        }

        temp_cost += min_costs_queue[1].front();
        min_costs_queue[1].pop();
    }
    queue<int> empty;
    min_costs_queue[0] = empty;
    min_costs_queue[1] = empty;

    if (base_cost == 0)
    {
        base_cost = temp_cost;
        temp_cost = 0;
    }

    return myVector;
}

int debug_flag = 0;
int main()
{
    int source_node = 1;
    sample_graph();
    graph = reduce_matrix(graph);
    show_vector(graph);
    cout << "The base cost is   " << base_cost << endl;
    cout << "The source node is " << source_node << endl;

    cout << "\n\n***** THE MAIN ACTION IS DOWN BELOW *****" << endl;

    for (int i = 1; i <= 5; i++)
    {
        if (i != source_node)
        {
            prepare_for_action_2(i, source_node, graph);
        }
    }

    

    // int current_source_node = pq.top().second.second.first;
    // int current_source_nodes_predecessor = pq.top().second.first;
    // int current_base_cost = pq.top().first * -1;
    // base_cost = current_base_cost;

    // cout << "\nFor node " << current_source_node << endl;
    // //end_node = current_source_node;
    // cout << "Base cost is " << current_base_cost << endl;
    // cout << "Source is " << current_source_nodes_predecessor << endl;

    // cout << "The reduced cost matrix is" << endl;

    // vector<vector<int>> myVector;

    // for (int i = 0; i < total_nodes; i++)
    // {
    //     myVector.push_back(pq.top().second.second.second[i]);
    // }

    //show_vector(myVector);

    int end_node;
    while (!pq.empty())
    {

        int current_source_node = pq.top().second.second.first;
        int current_source_nodes_predecessor = pq.top().second.first;
        int current_base_cost = pq.top().first * -1;
        base_cost = current_base_cost;

        end_node = current_source_node;

        cout << "Source is " << current_source_nodes_predecessor << endl;

        vector<vector<int>> myVector;

        for (int i = 0; i < total_nodes; i++)
        {
            myVector.push_back(pq.top().second.second.second[i]);
        }
        pq = priority_queue<base_costs>();

        for (int i = 0; i < total_nodes; i++)
        {
            if (myVector[i][0] != user_infinity)
            {
                prepare_for_action_2(i + 1, current_source_node, myVector);
            }
        }
    }

    cout << "End node is " << end_node << endl;
}

void prepare_for_action_2(int current_node, int source_node, vector<vector<int>> myVector1)
{
    vector<vector<int>> myVector;
    for (int i = 0; i < total_nodes; i++)
        myVector.push_back(myVector1[i]);

    int source_to_curr_cost = myVector[source_node - 1][current_node - 1]; // saving the coming cost to currnode
    myVector[current_node - 1][0] = user_infinity;                         // so it can not go back before visiting every node  //! this is the bug a static backtracing
    myVector = set_row_column_to_infinity(myVector, source_node - 1, current_node - 1);
    myVector = reduce_matrix(myVector);
    int total_coming_cost = base_cost + source_to_curr_cost + temp_cost;
    temp_cost = 0;
    pq.push(make_pair(total_coming_cost * -1, make_pair(source_node, make_pair(current_node, myVector))));

    // pq.push(make_pair(25 * -1, make_pair(source_node, make_pair(current_node, myVector))));

    //show_vector(myVector);
    //cout << endl;
}

/*
Final reduced matrix
   101     10     17      0      1
    12    101     11      2      0
     0      3    101      0      2
    15      3     12    101      0
    11      0      0     12    101

The base cost is 25
***** THE MAIN ACTION IS DOWN BELOW *****
Source is 1
Source is 4
Source is 2
Source is 5
End node is 3

*/