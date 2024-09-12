#include <bits/stdc++.h>

using namespace std;

class Edge {
 public:
  int a, b, weight;
  Edge(int a, int b, int weight) {
    this->a = a;
    this->b = b;
    this->weight = weight;
  }
};

int main() {
  int n, e;
  cin >> n >> e;
  vector<Edge> edgeList;
  while (e--) {
    int a, b, weight;
    cin >> a >> b >> weight;
    edgeList.push_back(Edge(a, b, weight));
  }
  int distanceArray[n];
  fill(distanceArray, distanceArray + n, INT_MAX);
  distanceArray[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (Edge ed : edgeList) {
      int a = ed.a, b = ed.b, weight = ed.weight;
      if (distanceArray[a] < INT_MAX && distanceArray[a] + weight < distanceArray[b]) {
        distanceArray[b] = distanceArray[a] + weight;
      }
    }
  }
  bool flag = false;
  for (Edge ed : edgeList) {
    int a = ed.a, b = ed.b, weight = ed.weight;
    if (distanceArray[a] < INT_MAX && distanceArray[a] + weight < distanceArray[b]) {
      flag = true;
      break;
    }
  }
  if (flag == true) {
    cout << "Cycle detected. No valid answer!" << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << i << " -> " << distanceArray[i] << endl;
    }
  }

  return 0;
}