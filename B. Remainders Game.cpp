#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 1e6 + 5;
int A[N];
ll getLCM(ll a, ll b) { return a * b / (__gcd(a, b)); }
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int gcd = A[0];
  for (int i = 1; i < n; i++) {
    gcd = __gcd(gcd, A[i]);
  }
  ll lcm = A[0] % k;
  for (int i = 1; i < n; i++) {
    lcm = getLCM(lcm, A[i]) % k;
  }
  cout << (lcm == 0 ? "YES" : "NO") << "\n";
  return 0;
}