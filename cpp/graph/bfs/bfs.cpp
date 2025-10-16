#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
  vector<bool> visited(adj.size(), false);
  vector<int> traversal;
  queue<int> q;

  visited[0] = true;
  q.push(0);

  while (!q.empty()) {
    int current = q.front();
    q.pop();
    traversal.push_back(current);

    for (int &x : adj[current]) {
      if (!visited[x]) {
        visited[x] = true;
        q.push(x);
      }
    }
  }

  return traversal;
}

int main() {

  vector<vector<int>> adj = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
  vector<int> ans = bfs(adj);
  for (auto i : ans) {
    cout << i << " ";
  }
  return 0;
}
