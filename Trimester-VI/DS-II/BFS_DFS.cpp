#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

template<class T>
class List {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
public:
    List(): head(NULL) {}
    void push_back(T val) {
        if (head == NULL) {
            Node* temp = new Node();
            temp->data = val;
            temp->next = NULL;
            head = temp;
        } else {
            Node* current = head;
            while (current->next != NULL)
                current = current->next;
            current->next = new Node();
            current->next->data = val;
            current->next->next = NULL;
        }
    }
    friend class Graph;
};

class Graph {
private:
    int V;
    vector<List<int>> adj_list;
    void DFS_Rec(int, vector<bool>&);
    void DFS_Non_Rec(int, vector<bool>);
public:
    Graph():V(0), adj_list(vector<List<int>>(0)) {}
    void AddEdge(int, int);
    void DFS(int);
    void BFS(int);
};

void Graph::AddEdge(int start, int end) {
    if (adj_list.size() < max(start, end) + 1) {
        adj_list.resize(max(start, end) + 1, List<int>());
        V = max(start, end) + 1;
    }
    adj_list[start].push_back(end);
}

void Graph::DFS_Rec(int v, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";
    auto current = adj_list[v].head;
    while(current != NULL) {
        if (!visited[current->data]) 
            DFS_Rec(current->data, visited);
        current = current->next;
    }
}

void Graph::DFS_Non_Rec(int v, vector<bool> visited) {
    stack<int> stk;
    stk.push(v);
    while(!stk.empty()) {
        int vertex = stk.top();
        stk.pop();
        if (!visited[vertex]) {
            cout << vertex << " ";
            visited[vertex] = true;
        }

        auto current = adj_list[vertex].head;
        while(current != NULL) {
            if (!visited[current->data]) 
                stk.push(current->data);
            current = current->next;
        }
    }
}

void Graph::DFS(int v) {
    int choice;
    cout << "\nDFS MENU\n";
    cout << "1. Recursive\n";
    cout << "2. Non Recursive\n";
    cout << "Enter your choice: ";
    cin >> choice;
    vector<bool> visited(V, false);
    if (choice == 1)
        DFS_Rec(v, visited);
    else if (choice == 2)
        DFS_Non_Rec(v, visited);
    cout << "\n";
}

void Graph::BFS(int v) {
    queue<int> q;
    vector<bool> visited(V, false);
    visited[v] = true;
    q.push(v);

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        auto current = adj_list[vertex].head;
        while(current != NULL) {
            if (!visited[current->data]) 
                q.push(current->data);
            current = current->next;
        }
    }
} 

int main() {
    Graph graph;
    int choice;
    while(true) {
        cout << "MENU\n";
        cout << "1. Add Edge\n";
        cout << "2. Depth First Traversal\n";
        cout << "3. Breadth First Traversal\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1: {
                int start, end;
                cout << "Enter the start of the edge: ";
                cin >> start;
                cout << "Enter the end of the edge: ";
                cin >> end;
                graph.AddEdge(start, end);
                break;
            }
            case 2: {
                cout << "Enter the vertex from which to start traversal: ";
                cin >> choice;
                graph.DFS(choice);
                break;
            }
            case 3: {
                cout << "Enter the vertex from which to start traversal: ";
                cin >> choice;
                graph.BFS(choice);
                break;
            }
            default:
                break;
        }
    }
}