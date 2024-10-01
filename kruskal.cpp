#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(int n, vector<int>& leader) {
    return leader[n];
}

void unionSets(int rootU, int rootV, vector<int>& leader) {
    int newLeader;
    if (rootU < rootV) {
        newLeader = rootU;
        for (int i = 0; i < leader.size(); i++) {
            if (leader[i] == rootV) {
                leader[i] = newLeader;
            }
        }
    } else {
        newLeader = rootV;
        for (int i = 0; i < leader.size(); i++) {
            if (leader[i] == rootU) {
                leader[i] = newLeader;
            }
        }
    }
}

void kruskalMST(int V, int E, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    vector<int> leader(V);
    for (int i = 0; i < V; i++) {
        leader[i] = i;
    }

    vector<Edge> result;
    int minimumCost = 0;

    for (int i = 0; i < edges.size(); i++) {
        Edge next_edge = edges[i];
        int x = find(next_edge.src, leader);
        int y = find(next_edge.dest, leader);

        if (x != y) {
            result.push_back(next_edge);
            minimumCost += next_edge.weight;
            unionSets(x, y, leader);
        }
    }

    cout << "Following are the edges in the constructed MST:\n";
    for (const Edge& edge : result) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
    cout << "Minimum Cost Spanning Tree: " << minimumCost << endl;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Unable to open file input.txt";
        return 1;
    }

    int V, E;
    inputFile >> V >> E;

    vector<Edge> edges(E);

    
    for (int i = 0; i < E; i++) {
        inputFile >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    inputFile.close();

    kruskalMST(V, E, edges);

    return 0;
}
