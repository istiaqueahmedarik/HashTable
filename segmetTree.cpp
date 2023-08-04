#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int tree[4000];

void build(int node, int start, int end)
{
    // leaf node
    if (start == end)
    {
        tree[node] = arr[node];
        return;
    }
    // mid
    int mid = (start + end) >> 1;
    // left
    build(2 * node, start, mid);
    // right
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
// start end is the required range
int RangeSum(int node, int start, int end, int left, int right)
{
    if (left >= start && right <= end)
        return tree[node];
    if (left > end || right < start)
        return 0;
    int mid = (left + right) >> 1;
    return RangeSum(2 * node, start, end, left, mid) + RangeSum(2 * node + 1, start, end, mid + 1, right);
}
// update
void update(int node, int start, int end, int index, int value)
{
    if (start > index || end < index)
        return;
    if (start == end && start == index)
    {
        tree[node] = value;
    }
    int mid = (start + end) >> 1;
    update(2 * node, start, mid, index, value);
    update(2 * node + 1, mid + 1, end, index, value);
}

int main()
{
}