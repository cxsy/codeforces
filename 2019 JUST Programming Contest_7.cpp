#include <bits/stdc++.h>
using namespace std;
int T, x1, y1, x2, y2;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << abs(x1 - x2) + abs(y1 - y2) << "\n";
  }
  return 0;
}