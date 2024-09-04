#include <bits/stdc++.h>

using namespace std;

vector<int> v[100];
bool visited[100];
int parent[100];

void bfs(int src) {
  queue<int> q;
  q.push(src);
  visited[src] = true;
  parent[src] = -1;
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    for (int child: v[p]) {
      if (visited[child] == false) {
        q.push(child);
        visited[child] = true;
        parent[child] = p;
      }
    }
  }
}

int main() {
  int n, e;
  cin >> n >> e;
  while (e--) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  memset(visited, false, sizeof(visited));
  memset(parent, -1, sizeof(parent));
  int src, destination;
  cin >> src >> destination;
  bfs(src);
  int x = destination;
  while (x != -1) {
    cout << x << " ";
    x = parent[x];
  }
  cout << endl;

  return 0;
}