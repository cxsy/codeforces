#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int m = 1e9 + 7;
const int N = 1e6 + 5;
int T[N];
int a, b, n;
int extended_euclidean(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int x1, y1;
  int d = extended_euclidean(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
int inverse_modular(int a) {
  int x, y;
  int g = extended_euclidean(a, m, x, y);
  x = (x % m + m) % m;
  return x;
}
bool test(int i) {
  while (i > 0) {
    if (i % 10 != a && i % 10 != b) return false;
    i /= 10;
  }
  return true;
}
void build() {
  cin >> a >> b >> n;
  T[0] = T[1] = 1;
  for (int i = 2; i < N; i++) {
    T[i] = int((1ll * T[i - 1] * i) % m);
  }
}
void solve() {
  int sol = 0;
  for (int i = 0; i <= n; i++) {
    int sum = a * i + b * (n - i);
    if (test(sum)) {
      sol = (sol + (((1ll * T[n] * inverse_modular(T[i])) % m) * inverse_modular(T[n - i])) % m) % m;
    }
  }
  cout << sol << "\n";
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  build();
  solve();
  return 0;
}