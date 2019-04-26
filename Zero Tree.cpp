#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int *dfs(int root, unordered_set<int> visited, unordered_map<int, int> val, unordered_map<int, unordered_set<int>> edge)
{
    int ret[2] = {};
    bool isLeaf = true;
    for (int ch : edge[root])
    {
        if (!visited.count(ch))
        {
            isLeaf = false;
            visited.insert(ch);
            int *sub = dfs(ch, visited, val, edge);
            ret[0] = max(ret[0], sub[0]);
            ret[1] = max(ret[1], sub[1]);
        }
    }
    if (isLeaf)
    {
        if (val[root] > 0)
        {
            ret[1] = val[root];
        }
        else
        {
            ret[0] = val[root];
        }
    }
    else
    {
        if (val[root] + ret[0] - ret[1] > 0)
        {
            ret[1] += val[root] + ret[0] - ret[1];
        }
        else
        {
            ret[0] -= (val[root] + ret[0] - ret[1]);
        }
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    unordered_map<int, unordered_set<int>> edge;
    unordered_map<int, int> val;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        edge[n1].insert(n2);
        edge[n2].insert(n1);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    unordered_set<int> visited;
    visited.insert(1);
    int *ans = dfs(1, visited, val, edge);
    cout << ans[0] + ans[1] << "\n";
    return 0;
}
