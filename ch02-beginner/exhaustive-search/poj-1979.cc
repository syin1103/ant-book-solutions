/*
 * POJ 1979: Red and Black
 *
 * Problem: Count the number of reachable tiles starting from '@', moving in
 * four directions.
 *
 * Solution: Use DFS to traverse all reachable '.' tiles, marking visited tiles
 * to avoid revisiting.
 */

#include <iostream>

int m, n, ans;
char mat[20][20];
int directions[5] = {-1, 0, 1, 0, -1};

void dfs(int i, int j) {
  if (mat[i][j] != '.') return;
  ++ans;
  mat[i][j] = '#';
  for (int k = 0; k < 4; k++) {
    int x = i + directions[k], y = j + directions[k + 1];
    if (0 <= x && x < m && 0 <= y && y < n && mat[x][y] == '.') {
      dfs(x, y);
    }
  }
}

void solve() {
  ans = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> mat[i];
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == '@') {
        mat[i][j] = '.';
        dfs(i, j);
      }
    }
  }
}

int main() {
  while (std::cin >> n >> m && m > 0 && n > 0) {
    solve();
    std::cout << ans << std::endl;
  }
  return 0;
}