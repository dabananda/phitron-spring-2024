/**
 * Title: Floyd Warshall Algorithm
 * Author: Dabananda Mitra
 * Email: imdmitra@gmail.com
 * Created: 2024-09-12 11:08:12
 *
 */

#include <bits/stdc++.h>
#define ll long long int
#define INF LLONG_MAX
using namespace std;

int main() {
  ll n, e;
  cin >> n >> e;
  ll adj[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        adj[i][j] = 0;
      } else {
        adj[i][j] = INF;
      }
    }
  }
  while (e--) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a][b] = w;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (adj[i][k] != INF && adj[k][j] != INF && adj[i][k] + adj[k][j] < adj[i][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }
  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (adj[i][i] < 0) {
      flag = true;
    }
  }
  if (flag == true) {
    cout << "Cycle detected!" << endl;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (adj[i][j] == INF) {
          cout << "INF" << " ";
        } else {
          cout << adj[i][j] << " ";
        }
      }
      cout << endl;
    }
  }

  return 0;
}
