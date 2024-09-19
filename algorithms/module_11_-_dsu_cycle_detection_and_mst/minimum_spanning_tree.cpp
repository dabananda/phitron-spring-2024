#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int parent[N];
int group_size[N];

class Edge {
  public:
  int a, b, w;
  Edge(int a, int b, int w) {
    this->a = a;
    this->b = b;
    this->w = w;
  }
};

bool comp(Edge a, Edge b) {
  return a.w < b.w;
}

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
  dsu_init(n);
  vector<Edge> v;
  while (e--) {
    int a, b, w;
    cin >> a >> b >> w;
    v.push_back(Edge(a, b, w));
  }
  sort(v.begin(), v.end(), comp);
  int totalCost = 0;
  for (Edge ed: v) {
    int x = dsu_find(ed.a);
    int y = dsu_find(ed.b);
    if (x != y) {
      dsu_union_by_size(ed.a, ed.b);
      totalCost += ed.w;
    }
  }
  cout << totalCost << endl;

  return 0;
}