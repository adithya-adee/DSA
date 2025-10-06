#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
private:
  void dfs_util(int startNode, vector<bool> &visited) {
    visited[startNode] = true;
    cout << " " << startNode;

    for (int neighbor : adjacency_list[startNode]) {
      if (!visited[neighbor]) {
        dfs_util(neighbor, visited);
      }
    }
  }

public:
  int V;
  vector<vector<int>> adjacency_list;

  Graph(int V) : V{V}, adjacency_list(V) {}

  void addEdge(int u, int v) {
    adjacency_list[u].push_back(v);
    adjacency_list[v].push_back(u);
  }

  void printAdjList() {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; ++i) {
      cout << "Vertex " << i << ":";
      for (int neighbor : adjacency_list[i]) {
        cout << " -> " << neighbor;
      }
      cout << endl;
    }
  }

  void printAdjMatrix() {
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    for (int i = 0; i < V; ++i) {
      for (int neighbor : adjacency_list[i]) {
        matrix[i][neighbor] = 1;
      }
    }

    cout << "Adjacency Matrix:" << endl;
    cout << setw(4) << " ";
    for (int i = 0; i < V; ++i) {
      cout << setw(3) << i;
    }
    cout << endl;

    for (int i = 0; i < V; ++i) {
      cout << setw(3) << i << "|";
      for (int j = 0; j < V; ++j) {
        cout << setw(3) << matrix[i][j];
      }
      cout << endl;
    }
  }

  void generateRandomGraph() {
    srand(time(0));
    // Ensure the graph is connected for more interesting traversals
    for (int i = 0; i < V - 1; ++i) {
      addEdge(i, i + 1);
    }

    int numExtraEdges = rand() % (V * (V - 1) / 4);
    for (int i = 0; i < numExtraEdges; ++i) {
      int u = rand() % V;
      int v = rand() % V;
      if (u != v) {
        addEdge(u, v);
      }
    }
  }

  void bfs(int startNode) {
    if (startNode >= V)
      return;
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS Traversal (starting from node " << startNode << "):";

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      cout << " " << node;

      for (int neighbor : adjacency_list[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
    cout << endl;
  }

  void dfs(int startNode) {
    if (startNode >= V)
      return;
    vector<bool> visited(V, false);
    cout << "DFS Traversal (starting from node " << startNode << "):";
    dfs_util(startNode, visited);
    cout << endl;
  }
};

int main() {
  int vertices = 5;
  Graph g(vertices);

  cout << "Initial Adjacency Matrix (as a list):" << endl;
  g.printAdjMatrix();
  cout << endl;

  g.generateRandomGraph();
  cout << "Adjacency Matrix after generating a random graph:" << endl;
  g.printAdjMatrix();
  cout << endl;

  cout << "Adding edge 0 -> 1" << endl;
  g.addEdge(0, 1);
  g.printAdjMatrix();

  return 0;
}
