#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9 + 5;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int px = -INF, ph = 0;
    int cx, ch;
    vector<int> dp(3);
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp(3);
        cin >> cx >> ch;
        if (cx - px > ph + ch)
        {
            tmp[0] = dp[2] + 1;
            tmp[1] = dp[2];
        }
        else if (cx - px > ch && cx - px <= ph)
        {
            tmp[1] = max(dp[0], dp[1]);
            tmp[0] = tmp[1] + 1;
        }
        else if (cx - px <= ch && cx - px > ph)
        {
            tmp[1] = dp[2];
        }
        else if (cx - px <= ch && cx - px <= ph)
        {
            tmp[1] = max(dp[0], dp[1]);
        }
        else
        {
            tmp[0] = max(dp[0], dp[1]) + 1;
            tmp[1] = dp[2];
        }
        tmp[2] = tmp[1] + 1;
        px = cx;
        ph = ch;
        dp = tmp;
    }
    cout << max(dp[0], max(dp[1], dp[2])) << "\n";
    return 0;
}
