#include <bits/stdc++.h>

using namespace std;

const int N = 100;

vector<pair<int, int>> v[N];
int d[N];

void dijkstra(int src) {
  queue<pair<int, int>> q;
  q.push({src, 0});
  d[src] = 0;
  while (!q.empty()) {
    pair<int, int> parent = q.front();
    q.pop();
    int node = parent.first;
    int cost = parent.second;
    for (pair<int, int> child : v[node]) {
      int childNode = child.first;
      int childCost = child.second;
      if (cost + childCost < d[childNode]) {
        d[childNode] = cost + childCost;
        q.push({childNode, d[childNode]});
      }
    }
  }
}

int main() {
  int n, e;
  cin >> n >> e;
  while (e--) {
    int a, b, w;
    cin >> a >> b >> w;
    v[a].push_back({b, w});
    v[b].push_back({a, w});
  }
  fill(d, d + N, INT_MAX);
  int src;
  cin >> src;
  dijkstra(src);
  for (int i = 0; i < n; i++) {
    cout << i << ": " << d[i] << endl;
  }

  return 0;
}