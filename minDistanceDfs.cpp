// will not work if graph has unequal weight

#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1000];
vector<int> parent(1000);
vector<int> visited(1000);
vector<int> dist(1000);
void dfs(int node)
{
    visited[node] = 1;
    for (auto child : adjList[node])
    {
        if (!visited[child])
        {
            parent[child] = node;
            dist[child] = dist[node] + 1;
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int s, d;
    cin >> s >> d;
    parent[s] = -1;
    dfs(s);
    cout << dist[d] << endl;
    stack<int> st;
    while (parent[d] != -1)
    {
        st.push(d);
        d = parent[d];
    }
    st.push(s);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}