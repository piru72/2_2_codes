
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[7];

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

void prepare_for_action(int, int);
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

    return myVector;
}

int debug_flag = 0;
int main()
{
    sample_graph();
    reduced_cost_matrix();
    int source_node = 1;

    cout << "***** THE MAIN ACTION IS DOWN BELOW *****" << endl;

    for (int i = 1; i <= 5; i++)
    {
        if (i != source_node)
        {
            prepare_for_action(i, source_node);
        }
    }

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

void reduced_cost_matrix()
{
    
    for (int i = 1; i <= total_nodes; i++)
    {
        find_minimum_going_cost(i);
    }
    for (int i = 1; i <= total_nodes; i++)
    {
        initial_reduced_matrix(i);
    }

    for (int i = 0; i < total_nodes; i++)
    {
        find_minimum_backing_cost(i);
    }
    for (int i = 0; i < total_nodes; i++)
    {
        final_reduced_matrix(i);
    }

    cout << "\nFinal reduced matrix " << endl;
    print_graph(total_nodes);

    cout << " \nThe base cost is " << base_cost << endl;
}
void prepare_for_action(int current_node, int source_node)
{
    vector<vector<int>> myVector;
    for (int i = 1; i <= 5; i++)
        myVector.push_back(graph[i]);
    int source_to_curr_cost = myVector[source_node - 1][current_node - 1];
    myVector[current_node - 1][source_node - 1] = user_infinity;
    int total_coming_cost = base_cost + source_to_curr_cost;
    myVector = set_row_column_to_infinity(myVector, source_node - 1, current_node - 1);
    pq.push(make_pair(total_coming_cost * -1, make_pair(source_node, make_pair(current_node, myVector))));
}

void prepare_for_action_2(int current_node, int source_node, vector<vector<int>> myVector1)
{
    vector<vector<int>> myVector;
    for (int i = 0; i < total_nodes; i++)
        myVector.push_back(myVector1[i]);

    int source_to_curr_cost = myVector[source_node - 1][current_node - 1]; // saving the coming cost to currnode
    myVector[current_node - 1][0] = user_infinity;                         // so it can not go back before visiting every node
    myVector = set_row_column_to_infinity(myVector, source_node - 1, current_node - 1);
    myVector = reduce_matrix(myVector);
    int total_coming_cost = base_cost + source_to_curr_cost + temp_cost;
    temp_cost = 0;
    pq.push(make_pair(total_coming_cost * -1, make_pair(source_node, make_pair(current_node, myVector))));
}