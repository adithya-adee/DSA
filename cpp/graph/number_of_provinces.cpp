#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  void bfs(int startNode, int n, const vector<vector<int>> &isConnected,
           vector<bool> &visited) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (int neighbor = 0; neighbor < n; ++neighbor) {
        if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
  }

  int findCircleNum(const vector<vector<int>> &isConnected) {
    if (isConnected.empty()) {
      return 0;
    }

    int n = isConnected.size();
    vector<bool> visited(n, false);
    int province_count = 0;

    cout << "Starting to find provinces..." << endl;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        province_count++;
        cout << "\nFound a new province. Starting node: " << i << endl;
        bfs(i, n, isConnected, visited);
      }
    }

    return province_count;
  }
};
