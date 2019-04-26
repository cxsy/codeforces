#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int main(int argc, char const *argv[])
{
    int t, k;
    cin >> t >> k;
    vector<pair<int, int>> arr;
    int maxx = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        maxx = max(maxx, arr[i].second);
    }
    vector<int> dp(maxx + 1);
    vector<int> sum(maxx + 1);
    for (int i = 1; i <= maxx; i++)
    {
        dp[i] = dp[i - 1];
        if (i >= k)
        {
            dp[i] = (dp[i] + dp[i - k]) % mod;
        }
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    for (int i = 0; i < t; i++)
    {
        cout << sum[arr[i].second] - sum[arr[i].first - 1] << "\n";
    }
    return 0;
}
