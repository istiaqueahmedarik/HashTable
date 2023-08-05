#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
class SLL
{
    Node *head;

public:
    SLL()
    {
        head = NULL;
    }
    void print()
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    void insertAtHead(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            return;
        }
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtTail(int data)
    {
        if (head)
        {
            Node *curr = head;
            while (curr->next)
                curr = curr->next;
            curr->next = new Node(data);
            return;
        }
        head = new Node(data);
    }
    void insertAfterValue(int data, int value)
    {
        if (head == nullptr)
            return;
        Node *newNode = new Node(data);
        Node *curr = head;
        while (curr && curr->data != value)
            curr = curr->next;

        if (curr)
        {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    // position is 1 based
    void insertAtPosition(int data, int position)
    {
        if (head == nullptr)
            return;
        Node *newNode = new Node(data);
        Node *curr = head;
        int currInd = 0;
        while (curr && currInd < position - 1)
        {
            curr = curr->next;
            currInd++;
        }
        if (curr)
        {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    void pop_front()
    {
        if (head == nullptr)
            return;
        Node *nxt = head->next;
        Node *curr = head;
        head = nxt;
        delete curr;
    }
    void pop_back()
    {
        if (head == nullptr)
            return;
        Node *pre = nullptr;
        Node *curr = head;
        while (curr->next)
        {
            pre = curr;
            curr = curr->next;
        }
        if (pre == nullptr)
        {
            head = nullptr;
            delete curr;
            return;
        }
        pre->next = nullptr;
        delete curr;
    }
    void deleteVal(int val)
    {
        if (head == nullptr)
            return;
        Node *curr = head;
        Node *prev = nullptr;
        while (curr->next && curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr->data == val)
        {
            if (prev == nullptr)
            {
                head = nullptr;
                delete curr;
                return;
            }
            prev->next = curr->next;
            delete curr;
        }
    }
    void deletePosition(int position)
    {
        if (head == NULL)
            return;
        Node *curr = head;
        Node *prev = nullptr;
        int currInd = 1;
        while (curr && currInd < position)
        {
            prev = curr;
            curr = curr->next;
            currInd++;
        }
        if (curr)
        {
            if (curr == head)
                pop_front();
            else if (curr->next == NULL)
                pop_back();
            else
            {
                prev->next = curr->next;
                delete curr;
            }
        }
    }
};
int main()
{
    SLL s;
    s.insertAtHead(1);
    s.insertAtHead(2);
    s.print(); // 2 1
    s.insertAtTail(3);
    s.print(); // 2 1 3
    s.insertAfterValue(4, 100);
    s.insertAfterValue(4, 2);
    s.print(); // 2 4 1 3
    s.insertAtPosition(10, 1000);
    s.insertAtPosition(10, 2);
    s.print(); // 2 4 10 1 3
    s.deleteVal(10);
    s.print(); // 2 4 1 3
    s.pop_front();
    s.print(); // 4 1 3
    s.pop_back();
    s.print(); // 4 1
    s.insertAtTail(10);
    s.print(); // 4 1 10
    s.deletePosition(2);
    s.print(); // 4 10
    s.deletePosition(1);
    s.print(); // 10
    s.insertAtPosition(4, 1);
    s.print(); // 10 4
    s.deletePosition(2);
    s.print(); // 10
}