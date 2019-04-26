#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

const int NMAX = 1e6 + 5;
int arr[NMAX];
int cc[NMAX];
int f1[NMAX];
ll f2[NMAX];

template <class T>
void upd(T* f, int index, int val, int N) {
  for (int i = index + 1; i <= N; i += i & (-i)) {
    f[i] += val;
  }
}
template <class T>
T get(T* f, int index) {
  T sum = 0;
  for (int i = index + 1; i >= 1; i -= i & (-i)) {
    sum += f[i];
  }
  return sum;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  copy(begin(arr), begin(arr) + n, cc);
  sort(begin(cc), begin(cc) + n);
  ll ret = 0;
  for (int i = n - 1; i >= 0; i--) {
    int index = lower_bound(begin(cc), begin(cc) + n, arr[i]) - begin(cc);
    // cout << index << "\n";
    ret += get(f2, index - 1);
    upd(f2, index, get(f1, index - 1), n);
    upd(f1, index, 1, n);
  }
  cout << ret << "\n";
  return 0;
}