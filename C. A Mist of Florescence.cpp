#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
void solve() {
  cin >> a >> b >> c >> d;
  a--;
  b--;
  c--;
  d--;
  cout << 40 << " " << 50 << "\n";
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 50; j++) {
      if (a && i % 2 == 0 && j % 2 == 0) {
        a--;
        cout << "A";
      } else {
        cout << "D";
      }
    }
    cout << "\n";
  }
  for (int i = 10; i < 20; i++) {
    for (int j = 0; j < 50; j++) {
      if (b && i % 2 == 0 && j % 2 == 0) {
        b--;
        cout << "B";
      } else {
        cout << "A";
      }
    }
    cout << "\n";
  }
  for (int i = 20; i < 30; i++) {
    for (int j = 0; j < 50; j++) {
      if (c && i % 2 == 0 && j % 2 == 0) {
        c--;
        cout << "C";
      } else {
        cout << "B";
      }
    }
    cout << "\n";
  }
  for (int i = 30; i < 40; i++) {
    for (int j = 0; j < 50; j++) {
      if (d && i % 2 == 0 && j % 2 == 0) {
        d--;
        cout << "D";
      } else {
        cout << "C";
      }
    }
    cout << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}