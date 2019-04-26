#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e6 + 5;
int arr[NMAX];
int freq[NMAX];
void upd(int index, int N) {
  for (int i = index + 1; i <= N; i += i & (-i)) {
    freq[i]++;
  }
}

int64_t get(int index) {
  int64_t ret = 0;
  for (int i = index + 1; i >= 1; i -= i & (-i)) {
    ret += freq[i];
  }
  return ret;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  unordered_map<int, int> mm;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mm[arr[i]]++;
  }
  int64_t ans = 0;
  unordered_map<int, int> mm1;
  for (int i = n - 1; i >= 0; i--) {
    ans += get(--mm[arr[i]]);
    upd(++mm1[arr[i]], n);
  }
  cout << ans << "\n";
  return 0;
}