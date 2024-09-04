#include <bits/stdc++.h>

using namespace std;

vector<int> v[100];
bool visited[100];

void bfs(int src) {
  queue<pair<int, int>> q;
  q.push({src, 0});
  visited[src] = true;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    int parent = p.first;
    int level = p.second;
    q.pop();
    cout << parent << " " << level << endl;
    for (int child: v[parent]) {
      if (visited[child] == false) {
        q.push({child, level + 1});
        visited[child] = true;
      }
    }
  }
}

int main() {
  int n, e;
  cin >> n >> e;
  memset(v, -1, sizeof(v));
  memset(visited, false, sizeof(visited));
  while (e--) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int src;
  cin >> src;
  bfs(src);

  return 0;
}