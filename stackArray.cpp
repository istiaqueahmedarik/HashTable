#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int *stack;
    int top;
    int count;
    int mx;
    Stack(int sz)
    {
        stack = new int[sz];
        top = -1;
        count = 0;
        mx = sz;
    }
    void push(int x)
    {
        if (top == mx - 1)
        {
            cout << "Stack Overflow! Resizing...." << endl;
            int *temp = new int[2 * mx];
            for (int i = 0; i < mx; i++)
            {
                temp[i] = stack[i];
            }
            mx *= 2;
            delete[] stack;
            stack = temp;
        }
        top++;
        stack[top] = x;
        count++;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
        count--;
    }
    int Top() { return stack[top]; }
    bool isEmpty() { return top == -1; }
    int size() { return count; }
    bool isFull() { return top == mx - 1; }
    ~Stack() { delete[] stack; }
};
int main()
{
    Stack s(2);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
}