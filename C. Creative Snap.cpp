#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int64_t helper(const vector<int> a, int l, int h, int A, int B) {
  int count =
      upper_bound(a.begin(), a.end(), h) - lower_bound(a.begin(), a.end(), l);
  if (count == 0) {
    return A;
  }
  int64_t minn = B * count * (h - l + 1);
  if (h > l) {
    int mid = (h - l) / 2 + l;
    minn = min(minn, helper(a, l, mid, A, B) + helper(a, mid + 1, h, A, B));
  }
  return minn;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, A, B;
  cin >> n >> k >> A >> B;
  for (int i = 0; i < k; i++) {
    int num;
    cin >> num;
    a.push_back(num);
  }
  sort(a.begin(), a.end());
  cout << helper(a, 1, 1 << n, A, B) << "\n";
  return 0;
}