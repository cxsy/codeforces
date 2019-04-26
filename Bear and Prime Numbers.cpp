#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e7 + 5;
void sieveEratosthenes(vector<bool> &prime) {
  prime[0] = prime[1] = false;
  for (int p = 2; p < prime.size(); p++) {
    if (prime[p]) {
      for (int i = 2; i * p < prime.size(); i++) {
        prime[i * p] = false;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  vector<bool> primes(NMAX, true);
  sieveEratosthenes(primes);
  vector<int> count(NMAX);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    count[num]++;
  }
  vector<int> f(NMAX);
  int maxx = 0;
  for (int p = 2; p < NMAX; p++) {
    f[p] = f[p - 1];
    if (primes[p]) {
      maxx = max(maxx, p);
      for (int i = 1; i * p < NMAX; i++) {
        f[p] += count[i * p];
      }
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    if (l > maxx) {
      cout << 0 << "\n";
      continue;
    }
    if (r >= NMAX) {
      r = NMAX - 1;
    }
    cout << f[r] - f[l - 1] << "\n";
  }
  return 0;
}