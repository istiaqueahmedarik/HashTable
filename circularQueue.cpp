#include <bits/stdc++.h>
using namespace std;
class CQueue
{
    int *queue;
    int front, rear;
    int sz;

public:
    CQueue(int sz = 1000)
    {
        queue = new int[sz];
        front = rear = -1;
        this->sz = sz;
    }
    bool isFull() { return front == rear + 1 || front == 0 && rear == sz - 1; }
    bool isEmpty() { return front == -1; }
    void push(int x)
    {
        if (isFull())
            return;
        if (front == -1)
            front = 0;
        rear = (rear + 1) % sz;
        queue[rear] = x;
    }
    void pop()
    {
        if (isEmpty())
            return;
        if (front == rear)
            front = rear = -1;
        front = (front + 1) % sz;
    }
    void display()
    {
        if (isEmpty())
            return;
        for (int i = front; i != rear; i = (i + 1) % sz)
            cout << queue[i] << " ";
        cout << queue[rear] << endl;
    }
};
int main()
{
}