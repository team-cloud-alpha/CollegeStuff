#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
public:
    Graph(): V(0), adj(vector<vector<int>>(0, vector<int>(0))) {}
    void AddEdge(int, int, int);
    void MST(int);
};

void Graph::AddEdge(int start, int end, int cost) {
    int n = max(start, end) + 1;
    if (adj.size() < n) {
        adj.resize(n);
        for (int i = 0; i < n; i++) 
            adj[i].resize(n, 0);
        V = n;
    }
    adj[start][end] = cost;
    adj[end][start] = cost;
}

void Graph::MST(int v) {
    int edges = 0;
    vector<bool> selected(V, false);
    vector<pair<int, int>> MST;

    selected[v] = true;
    while(edges < V-1) {
        int x = v, y = v, min = INT_MAX;
        for(int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && adj[i][j]) {
                        if (min > adj[i][j]) {
                            min = adj[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        MST.push_back(make_pair(x, y));
        selected[y] = true;
        edges++;
    }
    cout << "Edge\t|\tWeight\n";
    int cost = 0;
    for (int i = 0; i < MST.size(); i++) {
        cout << MST[i].first << "-" << MST[i].second << "\t|\t" << adj[MST[i].first][MST[i].second] << "\n";
        cost += adj[MST[i].first][MST[i].second] ;
    }
    cout << "Minimum Cost - " << cost << "\n";
}

int main() {
    Graph graph;
    int choice;
    while(true) {
        cout << "MENU\n";
        cout << "1. Add Edge\n";
        cout << "2. Perform MST\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                int start, end, cost;
                cout << "Enter the start of the edge: ";
                cin >> start;
                cout << "Enter the end of the edge: ";
                cin >> end;
                cout << "Enter the cost of the edge: ";
                cin >> cost;
                graph.AddEdge(start, end, cost);
                break;
            }
            case 2: {
                cout << "Enter the vertex from which to find a MST: ";
                cin >> choice;
                graph.MST(choice);
            }
            default:
                break;
        }
    }
}