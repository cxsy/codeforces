#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const int N = 1e5 + 5;
int arr[N];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (sum % 2) {
    cout << "NO\n";
    exit(0);
  }
  sum /= 2;
  unordered_set<ll> ss;
  ll presum = 0;
  for (int i = 0; i < n; i++) {
    presum += arr[i];
    ss.insert(arr[i]);
    if (ss.count(presum - sum)) {
      cout << "YES\n";
      exit(0);
    }
  }
  ss.clear();
  presum = 0;
  for (int i = n - 1; i >= 0; i--) {
    presum += arr[i];
    ss.insert(arr[i]);
    if (ss.count(presum - sum)) {
      cout << "YES\n";
      exit(0);
    }
  }
  cout << "NO\n";
  return 0;
};