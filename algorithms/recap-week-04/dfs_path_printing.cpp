/**
 * Author: Dabananda Mitra
 * Email: imdmitra@gmail.com
 * Created: 2024-09-27 13:49:39
 * Copyright 2024, Dabananda Mitra. All right reserved.
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int vis[N];
int par[N];
vector<int> adj[N];

void bfs(int src) {
  vis[src] = 1;
  queue<int> q;
  q.push(src);
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    for (int x : adj[p]) {
      if (!vis[x]) {
        vis[x] = 1;
        par[x] = p;
        q.push(x);
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
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  fill(vis, vis + n, 0);
  fill(par, par + n, -1);
  int src, des;
  cin >> src >> des;
  bfs(src);
  vector<int> path;
  int x = des;
  while (x != -1) {
    path.push_back(x);
    x = par[x];
  }
  reverse(path.begin(), path.end());
  for (int x : path) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}