#include <iostream>
using namespace std;
const int NMAX = 1005, MMAX = 10;
int a[MMAX][NMAX], pos[MMAX][NMAX], dp[NMAX];
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
          {
            cin >> a[i][j];
            pos[i][a[i][j]] = j;
        }
    }
    int ans = 0;
    for (int j = 1; j <= n; j++)
    {
        int maxx = 0;
        for (int p = 1; p < j; p++)
        {
            int i;
            for (i = 2; i <= k && pos[i][a[1][p]] < pos[i][a[1][j]]; i++);
            if (i == k + 1 && dp[p] > maxx)
            {
                maxx = dp[p];
            }
        }
        dp[j] = maxx + 1;
        ans = max(ans, dp[j]);
    }
    cout << ans << "\n";
    return 0;
}