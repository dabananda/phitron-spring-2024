#include <bits/stdc++.h>

using namespace std;

vector<int> v[100];
bool vis[100] = {false};
int parentArray[100] = {-1};
bool ans = false;

void dfs(int src) {
  vis[src] = true;
  for (int x : v[src]) {
    if (vis[x] && parentArray[src] != x) {
      ans = true;
      return;
    }
    if (!vis[x]) {
      vis[x] = true;
      parentArray[x] = src;
      dfs(x);
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
  dfs(src);
  cout << (ans ? "Cycle detected!" : "No cycle!") << endl;

  return 0;
}