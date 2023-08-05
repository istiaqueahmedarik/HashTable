#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1000];
vector<int> parent(1000);
vector<int> visited(1000);
vector<int> dist(1000);
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
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    while (!q.empty())
    {
        int node = q.front();
        visited[node] = 1;
        q.pop();
        for (auto i : adjList[node])
        {
            if (!visited[i])
            {
                q.push(i);
                parent[i] = node;
                dist[i] = dist[node] + 1;
            }
        }
    }
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