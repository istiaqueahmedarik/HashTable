#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *queue;
    int front, rear;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        queue = new int[size];
        front = rear = -1;
    }
    void enqueue(int data)
    {
        if (rear == size - 1)
        {
            int *temp = new int[size * 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = queue[i];
            }
            delete[] queue;
            queue = temp;
        }
        queue[++rear] = data;
        if (front == -1)
            front++;
    }
    void dequeue()
    {
        if (front == -1)
            return;
        else
        {
            front++;
            if (front > rear)
                front = rear = -1;
        }
    }
    void display()
    {
        if (rear == -1)
            return;
        else
        {
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
            cout << endl;
        }
    }
};