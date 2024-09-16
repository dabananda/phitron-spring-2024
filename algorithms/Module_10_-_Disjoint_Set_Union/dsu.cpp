/**
 * Title: Disjoint Set Union
 * Descripton: Basic operations of disjoint set union algorithm
 * Link: Phitron | Batch 05 | Introduction to Algorithms | Week 03
 * Author: Dabananda Mitra
 * Email: imdmitra@gmail.com
 * Created: 2024-09-16 17:59:02
 * Copyright 2024, Dabananda Mitra. All right reserved.
 *
 */

#include <bits/stdc++.h>

using namespace std;

int parent[100];
int groupSize[100];
int level[100];

void dsuInit() {
  fill(parent, parent + 100, -1);
  fill(groupSize, groupSize + 100, 1);
  fill(level, level + 100, 1);
}

int dsuFind(int node) {
  if (parent[node] == -1) {
    return node;
  }
  int leader = dsuFind(parent[node]);
  parent[node] = leader;
  return leader;
}

void dsuUnion(int x, int y) {
  int a = dsuFind(x);
  int b = dsuFind(y);
  parent[a] = b;
}

void UnionBySize(int x, int y) {
  int a = dsuFind(x);
  int b = dsuFind(y);
  if (groupSize[a] > groupSize[b]) {
    parent[b] = a;
    groupSize[a] += groupSize[b];
  } else {
    parent[a] = b;
    groupSize[b] += groupSize[a];
  }
}

void UnionByLevel(int x, int y) {
  int a = dsuFind(x);
  int b = dsuFind(y);
  if (level[a] > level[b]) {
    parent[b] = a;
  } else if (level[b] > level[a]) {
    parent[a] = b;
  } else {
    parent[a] = b;
    level[b]++;
  }
}

int main() {
  dsuInit();
  UnionByLevel(1, 2);
  UnionByLevel(2, 3);
  UnionByLevel(4, 5);
  UnionByLevel(5, 6);
  UnionByLevel(1, 4);

  cout << dsuFind(1) << endl;
  cout << dsuFind(4) << endl;

  return 0;
}