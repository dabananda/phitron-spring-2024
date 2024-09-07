#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

vector<int> graph[N];
bool visited[N];

void dfs(int src) {
  visited[src] = true;
  cout << src << endl;
  for (int child: graph[src]) {
    if (visited[child] == false) {
      visited[child] = true;
      dfs(child);
    }
  }
}

int main() {
  int n, e;
  cin >> n >> e;
  while (e--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  memset(visited, false, sizeof(visited));
  int src;
  cin >> src;
  dfs(src);

  return 0;
}