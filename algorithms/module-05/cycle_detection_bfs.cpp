#include <bits/stdc++.h>

using namespace std;

vector<int> v[100];
bool vis[100] = {false};
int parentArray[100] = {-1};
bool ans = false;

void bfs(int src) {
  queue<int> q;
  q.push(src);
  vis[src] = true;
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    for (int x : v[p]) {
      if (vis[x] && parentArray[p] != x) {
        ans = true;
        return;
      }
      if (!vis[x]) {
        vis[x] = true;
        q.push(x);
        parentArray[x] = p;
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
  int src;
  cin >> src;
  bfs(src);
  cout << (ans ? "Cycle detected!" : "No cycle!") << endl;

  return 0;
}