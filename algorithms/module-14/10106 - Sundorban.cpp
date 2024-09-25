/**
 * Title: Sundorban
 * Link: https://school.outsbook.com/problems/problemdetails/10106
 * Author: Dabananda Mitra
 * Email: imdmitra@gmail.com
 * Created: 2024-09-25 23:42:20
 *
 */

#include <bits/stdc++.h>

using namespace std;

void bfs(int si, int sj, int n, vector<vector<char> >& mat, vector<vector<bool> >& vis, vector<vector<int> >& dis) {
  queue<pair<int, int> > q;
  q.push({si, sj});
  dis[si][sj] = 0;
  vector<pair<int, int> > dir;
  dir.push_back({0, -1});
  dir.push_back({0, 1});
  dir.push_back({-1, 0});
  dir.push_back({1, 0});
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = p.first + dir[i].first;
      int y = p.second + dir[i].second;
      if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && mat[x][y] != 'T') {
        q.push({x, y});
        vis[x][y] = true;
        dis[x][y] = dis[p.first][p.second] + 1;
      }
    }
  }
}

int main() {
  int n;
  while (cin >> n) {
    vector<vector<char> > mat(n, vector<char>(n));
    vector<vector<bool> > vis(n, vector<bool>(n, false));
    vector<vector<int> > dis(n, vector<int>(n, -1));
    int si, sj, di, dj;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> mat[i][j];
        if (mat[i][j] == 'S') {
          si = i, sj = j;
        } else if (mat[i][j] == 'E') {
          di = i, dj = j;
        }
      }
    }
    bfs(si, sj, n, mat, vis, dis);
    cout << dis[di][dj] << endl;
  }

  return 0;
}