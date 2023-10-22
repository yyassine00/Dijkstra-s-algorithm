//Younes Yassine
//Programming Lab 2 
//CSCI 3761 001
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits.h>
#include <set>
#include <ctime>

using namespace std;

const int INF = 1073741824; // a very large value representing infinity

// pair of integers (u, v) representing an edge with weight w from u to v
typedef pair<int, int> pii;

// implementation of Dijkstra's algorithm to find shortest path from source to all nodes
void dijkstra(int source, vector<vector<pii>>& adj_list, vector<int>& distances, vector<int>& prev) {

    // create a min-heap priority queue to store nodes and their tentative distances from the source
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // set the distance of the source node to zero and add it to the queue
    distances[source] = 0;
    pq.push(make_pair(0, source));

    // create a set to keep track of visited nodes
    set<int> visited;

    // print table header
    cout << "Step\tN'\t\t";
    for (int i = 1; i < distances.size(); i++) {
        if (i != source) {
            cout << i << "\t";
        }
    }
    cout << endl;

    int step = 0;
    while (!pq.empty()) {
        // get node with smallest tentative distance from queue
        int u = pq.top().second;
        pq.pop();

        // skip nodes that have already been visited
        if (visited.count(u)) {
            continue;
        }
        visited.insert(u);

        // print table row
        cout << step << "\t{";
        for (int node : visited) {
            cout << node << ",";
        }
        cout << "}\t\t";
        for (int i = 1; i < distances.size(); i++) {
            if (i != source) {
                if (distances[i] == INF) {
                    cout << "INF\t";
                } else {
                    cout << distances[i] << "," << prev[i] << "\t";
                }
            }
        }
        cout << endl;

        step++;

        // relax edges of u and update distances and previous nodes if a shorter path is found
        for (auto& neighbor : adj_list[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
                prev[v] = u;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}


int main() {

    clock_t start = clock();

    
    int num_nodes;
    string filename;
    int source_node;

    cout << "Enter the name of the file containing the graph: ";
    cin >> filename;
    cout << "Enter the source node: ";
    cin >> source_node;

    ifstream file(filename);

    file >> num_nodes;

    vector<vector<pii>> adj_list(num_nodes + 1);
    vector<int> distances(num_nodes + 1, INF);
    vector<int> prev(num_nodes + 1, -1);

    int u, v, weight;
    while (file >> u >> v >> weight) {
        adj_list[u].push_back(make_pair(v, weight));
        adj_list[v].push_back(make_pair(u, weight));
    }

    dijkstra(source_node, adj_list, distances, prev);

    cout << "Forwarding table for node " << source_node << ":" << endl;
    for (int i = 1; i <= num_nodes; i++) {
        if (i == source_node) {
            cout << "Node " << i << ": " << i << endl;
        } else if (distances[i] == INF) {
            cout << "Node " << i << ": not reachable" << endl;
        } else {
            cout << "Node " << i << ": ";
            int next_hop = i;
            while (prev[next_hop] != source_node) {
                next_hop = prev[next_hop];
            }
            cout << next_hop << endl;
        }
    }

    clock_t stop = clock(); 
    double duration = (double)(stop - start) / CLOCKS_PER_SEC; 
    cout << "Execution time: " << duration << " seconds" << endl;

    return 0;
}
