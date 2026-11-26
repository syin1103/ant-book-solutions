/*
 * AOJ 0033: Ball
 */

#include <iostream>

int balls[10];

void solve() {
  int b = balls[0];
  int c = 0;

  for (int i = 1; i < 10; i++) {
    int min_x = std::min(b, c);
    int max_x = std::max(b, c);

    if (balls[i] < min_x) {
      std::cout << "NO" << std::endl;
      return;
    }

    if (min_x < balls[i] && balls[i] < max_x) {
      if (b < c) {
        b = balls[i];
      } else {
        c = balls[i];
      }
      continue;
    }

    // balls[i] > max_x;
    if (b > c) {
      b = balls[i];
    } else {
      c = balls[i];
    }
  }

  std::cout << "YES" << std::endl;
  return;
}

int main() {
  int n = 0;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      std::cin >> balls[j];
    }
    solve();
  }

  return 0;
}