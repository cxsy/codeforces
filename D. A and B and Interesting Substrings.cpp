#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int NMAX = 1e5 + 5;
unordered_map<char, unordered_map<ll, int>> mm;

int al[26];
char arr[NMAX];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 26; i++) {
    cin >> al[i];
  }
  cin >> arr;
  ll sum = 0, ans = 0;
  for (int i = 0; arr[i]; i++) {
    if (arr[i] == arr[i + 1]) ans++;
    sum += al[arr[i] - 'a'];
    ans += mm[arr[i + 1]][sum];
    mm[arr[i]][sum]++;
  }
  cout << ans << "\n";
  return 0;
}