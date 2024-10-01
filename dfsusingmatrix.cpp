#include <bits/stdc++.h>
using namespace std;

int node, edge;
vector<int> color;
vector<vector<int>> adjacencyMatrix;
vector<int> previous;
vector<int> fi;
vector<int> di;
int t = 0;

void addEdges(int s, int d) {
    adjacencyMatrix[s][d]=adjacencyMatrix[d][s]=1;
    
}

void rundfs(int u) {
    cout << u << " ";
    color[u] = 1; 
    t++;
    di[u] = t;

    for(int v=0; v<node; v++){
        if(adjacencyMatrix[u][v]==1 && color[v]==0){
            previous[v]=u;
            rundfs(v);
        }
        
    }

    color[u] = 2; 
    t++;
    fi[u] = t;
}

void dfs() {
    for (int i = 0; i < node; i++) {
        if (color[i] == 0) {
            rundfs(i);
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
    adjacencyMatrix.resize(node,vector<int>(node,0));



    for (int i = 0; i < edge; i++) {
        cout << "Enter source and destination: ";
        int s, d;
        cin >> s >> d;
        addEdges(s, d);
    }

    dfs();

    return 0;
}
