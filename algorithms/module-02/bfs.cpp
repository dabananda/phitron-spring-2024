#include <bits/stdc++.h>

using namespace std;

vector<int> v[10];
bool visited[10];

void bfs(int src) {
  queue<int> q;
  q.push(src);
  visited[src] = true;
  while (!q.empty()) {
    int parent = q.front();
    q.pop();
    cout << parent << endl;
    for (int child: v[parent]) {
      if (visited[child] == false) {
        q.push(child);
        visited[child] = true;
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
  int src;
  cin >> src;
  bfs(src);
  return 0;
}