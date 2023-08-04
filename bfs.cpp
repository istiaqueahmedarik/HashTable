#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
unordered_map<int, int> color;
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
        color[u] = 0;
        color[v] = 0;
    }
    queue<int> q;
    q.push(1);
    color[1] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : mp[node])
        {
            if (!color[it])
            {
                q.push(it);
                color[it] = 1;
            }
        }
        color[node] = 2; // visited
    }
}