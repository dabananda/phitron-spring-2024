#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int parent[N];
int group_size[N];

void dsu_init(int n) {
  for (int i = 0; i < n; i++) {
    parent[i] = -1;
    group_size[i] = 1;
  }
}

int dsu_find(int node) {
  if (parent[node] == -1) {
    return node;
  }
  return parent[node] = dsu_find(parent[node]);
}

void dsu_union_by_size(int x, int y) {
  int a = dsu_find(x);
  int b = dsu_find(y);
  if (group_size[a] > group_size[b]) {
    parent[b] = a;
    group_size[a] += group_size[b];
  } else {
    parent[a] = b;
    group_size[b] += group_size[a];
  }
}

int main() {
  int n, e;
  cin >> n >> e;
  bool cycle = false;
  dsu_init(n);
  while (e--) {
    int a, b;
    cin >> a >> b;
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA == leaderB) {
      cycle = true;
    } else {
      dsu_union_by_size(a, b);
    }
  }
  cout << (cycle ? "Cycle found!" : "No cycle detected.") << endl;

  return 0;
}