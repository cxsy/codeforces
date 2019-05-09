#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define mp make_pair

const int N = 1e5 + 5;
int arr1[N], arr2[N];
vector<ii> v1, v2;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr1[i];
  for (int i = 0; i < m; i++) cin >> arr2[i];
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
  for (int i = 0; i < n; i++) {
    int count = 1;
    while (i + 1 < n && arr1[i] == arr1[i + 1]) {
      i++;
      count++;
    }
    v1.emplace_back(mp(arr1[i], count));
  }
  v1.emplace_back(mp(INT32_MAX, 0));
  v2.emplace_back(mp(0, 0));
  for (int i = 0; i < m; i++) {
    int count = 1;
    while (i + 1 < m && arr2[i] == arr2[i + 1]) {
      i++;
      count++;
    }
    v2.emplace_back(mp(arr2[i], count));
  }
  int64_t ans = 0;
  int i1 = 0, i2 = v2.size() - 1;
  int l = v1[i1].first, r = v2[i2].first;
  while (l < r) {
    if (v1[i1].second < v2[i2].second) {
      ans += 1LL * v1[i1].second * (min(r, v1[i1 + 1].first) - l);
      v1[i1 + 1].second += v1[i1].second;
      l = v1[++i1].first;
    } else {
      ans += 1LL * v2[i2].second * (r - max(l, v2[i2 - 1].first));
      v2[i2 - 1].second += v2[i2].second;
      r = v2[--i2].first;
    }
  }
  cout << ans << "\n";
  return 0;
}