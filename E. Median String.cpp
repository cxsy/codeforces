#include <bits/stdc++.h>
using namespace std;

const int KMAX = 2e5 + 5;
vector<int> s1, s2;
char arr1[KMAX], arr2[KMAX];
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  cin >> k;
  cin >> arr1 >> arr2;
  for (int i = 0; i < k; i++) {
    s1.push_back(arr1[i] - 'a');
    s2.push_back(arr2[i] - 'a');
  }
  for (int i = k - 1; i >= 0; i--) {
    s1[i] += s2[i];
    if (i > 0) {
      s1[i - 1] += s1[i] / 26;
      s1[i] %= 26;
    }
  }
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] % 2) s1[i + 1] += 26;
    cout << (char)((s1[i] / 2) + 'a');
  }
  cout << "\n";
  return 0;
}