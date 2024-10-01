#include <bits/stdc++.h>
using namespace std;

int node, edge;
vector<int> color;
vector<int> previous;
int t = 0;
bool cycleFound = false;

void addEdges(vector<vector<int>>& adjacencylist, int s, int d) {
    adjacencylist[s].push_back(d);
    adjacencylist[d].push_back(s);
}

void rundfs(int u, vector<vector<int>>& adjacencylist, int parent) {
    color[u] = 1; 
    t++;

    for (int neighbour : adjacencylist[u]) {
        if (color[neighbour] == 0) {
            previous[neighbour] = u;
            rundfs(neighbour, adjacencylist, u);
        } else if (neighbour != parent) {
            
            cycleFound = true;
            return; 
        }
    }

    color[u] = 2; 
}

void dfs(vector<vector<int>>& adjacencylist) {
    for (int i = 0; i < node; i++) {
        if (color[i] == 0) {
            rundfs(i, adjacencylist, -1);
            if (cycleFound) {
                return; 
            }
        }
    }
}

int main() {
    cout << "Enter number of nodes and edges: ";
    cin >> node >> edge;

    color.resize(node, 0);
    previous.resize(node, -1);

    vector<vector<int>> adjacencylist(node);

    for (int i = 0; i < edge; i++) {
        cout << "Enter source and destination: ";
        int s, d;
        cin >> s >> d;
        addEdges(adjacencylist, s, d);
    }

    dfs(adjacencylist);

    if (cycleFound) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}
