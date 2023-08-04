#include <bits/stdc++.h>
using namespace std;
unordered_map<string, vector<int>> mp;
int main()
{
    hash<string> x = mp.hash_function();
    cout << x("A");
}