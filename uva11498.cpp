#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int K, N, M;
  while (cin >> K) {
    if (K == 0) break;
    cin >> N >> M;
    for (int i = 0; i < K; i++) {
      int x, y;
      cin >> x >> y;
      if (x == N || y == M) {
        cout << "divisa"
             << "\n";
      } else if (x > N && y > M) {
        cout << "NE"
             << "\n";
      } else if (x < N && y > M) {
        cout << "NO"
             << "\n";
      } else if (x < N && y < M) {
        cout << "SO"
             << "\n";
      } else {
        cout << "SE"
             << "\n";
      }
    }
  }

  return 0;
}