#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adjacencyMatrix, int source, int node) {
    vector<int> visited(node, 0);
    vector<int> level(node, 9999);

    visited[source] = 1;
    level[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int currentNode = q.front();
        cout << currentNode << " ";
        q.pop();

        for (int v = 0; v < node; v++) {
            if (adjacencyMatrix[currentNode][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                level[v] = level[currentNode] + 1;
                q.push(v);
            }
        }

        visited[currentNode] = 2;
    }

    cout << endl;

    for (int i = 0; i < node; i++) {
        cout << "Current Node: " << i << " Level: " << level[i] << endl;
    }
}

int main() {
    int node, edge;
    cout << "Enter number of nodes and edges: ";
    cin >> node >> edge;

    
    vector<vector<int>> adjacencyMatrix(node, vector<int>(node, 0));

    for (int i = 0; i < edge; i++) {
        cout << "Enter source and destination: ";
        int s, d;
        cin >> s >> d;
        adjacencyMatrix[s][d] = 1;
        adjacencyMatrix[d][s] = 1; 
    }

    cout << "BFS traversal starting from node 0:" << endl;
    bfs(adjacencyMatrix, 0, node);

    return 0;
}
