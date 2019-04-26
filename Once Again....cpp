#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int NMAX = 305;
int main(int argc, char const *argv[]) {
  int n, T;
  cin >> n >> T;
  vector<int> arr(n);
  map<int, pair<int,int>> map;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    map[arr[i]] = ;
  }
  map[0] = 0;
  for (auto &p : map) {
    for (int i = 0; i < n; i++) {
      if (arr[i] >= p.first) {
        p.second++;
      }
    }
  }
  vector<int> dp(NMAX);
  for (int t = 0; t < T; t++) {
    int sum = 0;
    for (auto &p : map) {
      dp[p.first] += map[p.first];
    }
  }
  return 0;
}
