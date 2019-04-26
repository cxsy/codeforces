#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

const int NMAX = 2e5 + 5;
vector<ll> v(1, 0LL);
int arr[NMAX];
int BIT[NMAX];
void upd(int N, int index) {
  for (int i = index + 1; i <= N; i += i & (-i)) {
    BIT[i]++;
  }
}

int get(int index) {
  int freq = 0;
  for (int i = index + 1; i >= 1; i -= i & (-i)) {
    freq += BIT[i];
  }
  return freq;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, t;
  cin >> n >> t;
  int pref = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    pref += arr[i];
    v.push_back(pref);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  int vs = v.size();
  upd(vs, lower_bound(v.begin(), v.end(), 0LL) - v.begin());
  pref = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    pref += arr[i];
    int pos = upper_bound(v.begin(), v.end(), pref - t) - v.begin();
    ans += (i + 1 - get(pos - 1));
    int k = lower_bound(v.begin(), v.end(), pref) - v.begin();
    upd(vs, k);
  }
  cout << ans << "\n";
  return 0;
}