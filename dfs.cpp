#include <bits/stdc++.h>
using namespace std;

int node, edge;
vector<int> color;
vector<int> previous;
vector<int> fi;
vector<int> di;
int t = 0;

void addEdges(vector<vector<int>>& adjacencylist, int s, int d) {
    adjacencylist[s].push_back(d);
    adjacencylist[d].push_back(s);
}

void rundfs(int u, vector<vector<int>>& adjacencylist) {
    cout << u << " ";
    color[u] = 1; 
    t++;
    di[u] = t;

    for (int neighbour : adjacencylist[u]) {
        if (color[neighbour] == 0) {
            previous[neighbour] = u;
            rundfs(neighbour, adjacencylist);
        }
    }

    color[u] = 2; 
    t++;
    fi[u] = t;
}

void dfs(vector<vector<int>>& adjacencylist) {
    for (int i = 0; i < node; i++) {
        if (color[i] == 0) {
            rundfs(i, adjacencylist);
        }
    }
}

int main() {
    cout << "Enter number of nodes and edges: ";
    cin >> node >> edge;


    color.resize(node, 0);
    previous.resize(node, -1);
    fi.resize(node, 9999);
    di.resize(node, 9999);

    vector<vector<int>> adjacenlist(node);

    for (int i = 0; i < edge; i++) {
        cout << "Enter source and destination: ";
        int s, d;
        cin >> s >> d;
        addEdges(adjacenlist, s, d);
    }

    dfs(adjacenlist);

    return 0;
}
