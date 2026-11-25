/*
 * AOJ 0118: Property Distribution
 */

#include <iostream>

int m = 0, n = 0, ans = 0;
int directions[5] = {-1, 0, 1, 0, -1};
char matrix[100][100];

void dfs(int i, int j) {
  if (matrix[i][j] == '.') return;

  char ch = matrix[i][j];
  matrix[i][j] = '.';

  for (int k = 0; k < 4; k++) {
    int x = i + directions[k], y = j + directions[k + 1];
    if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] == ch) {
      dfs(x, y);
    }
  }
}

void solve() {
  ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] != '.') {
        ++ans;
        dfs(i, j);
      }
    }
  }
}

int main() {
  while (std::cin >> m >> n && m > 0 && n > 0) {
    for (int i = 0; i < m; i++) {
      std::cin >> matrix[i];
    }
    solve();
    std::cout << ans << std::endl;
  }

  return 0;
}