#include <bits/stdc++.h>

using namespace std;

int bfs(int src, int dst, vector<int> graph[], bool visited[]) {
  queue<pair<int, int>> q;
  q.push({src, 0});
  visited[src] = true;
  int n, l;
  bool ans = false;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    n = p.first;
    l = p.second;
    if (n == dst) {
      ans = true;
      break;
    }
    q.pop();
    for (int i : graph[n]) {
      if (visited[i] == false) {
        q.push({i, l + 1});
        visited[i] = true;
      }
    }
  }
  return ans ? l : -1;
}

int main() {
  int n, e;
  cin >> n >> e;
  vector<int> graph[100];
  bool visited[100] = {false};
  while (e--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int q;
  cin >> q;
  while (q--) {
    int src, dst;
    cin >> src >> dst;
    fill(visited, visited + 100, false);
    cout << bfs(src, dst, graph, visited) << endl;
  }

  return 0;
}