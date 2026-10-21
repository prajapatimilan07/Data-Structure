
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];
bool visited[100];

void DFS(int node) {
    cout << node << " ";
    visited[node] = true;

    for (int next : adj[node]) {
        if (!visited[next])
            DFS(next);
    }
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, e, u, v, start;

    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS: ";
    DFS(start);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout << "\nBFS: ";
    BFS(start);

    return 0;
}
