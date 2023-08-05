#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this->data = data;
        next = prev = nullptr;
    }
};
class DLL
{
    Node *head, *tail;

public:
    DLL()
    {
        head = tail = nullptr;
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
    void printRev()
    {
        Node *curr = tail;
        while (tail)
        {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }
    void push_front(int data)
    {
        Node *newItem = new Node(data);
        if (head == nullptr)
        {
            head = tail = newItem;
            return;
        }
        newItem->next = head;
        head->prev = newItem;
        head = newItem;
    }
    void push_back(int data)
    {
        Node *newItem = new Node(data);
        if (tail == nullptr)
        {
            head = tail = newItem;
            return;
        }
        newItem->prev = tail;
        tail->next = newItem;
        tail = newItem;
    }
    void insertAfterValue(int value, int data)
    {
        if (head == nullptr)
            return;
        Node *curr = head;
        while (curr && curr->data != value)
        {
            curr = curr->next;
        }
        if (curr)
        {
            if (curr->next == NULL)
            {
                push_back(data);
                return;
            }
            Node *newItem = new Node(data);
            newItem->prev = curr;
            newItem->next = curr->next;
            curr->next = newItem;
        }
    }
    void afterPositionInsert(int data, int position)
    {
        if (head == nullptr)
            return;
        Node *curr = head;
        int curPos = 1;
        while (curr && curPos < position)
        {
            curr = curr->next;
            curPos++;
        }
        if (curr)
        {
            if (curr->next == NULL)
            {
                push_back(data);
                return;
            }
            Node *newItem = new Node(data);
            newItem->prev = curr;
            newItem->next = curr->next;
            curr->next = newItem;
        }
    }
    void pop_back()
    {
        if (head)
        {
            Node *prev = tail->prev;
            Node *curr = tail;
            if (prev)
            {
                prev->next = nullptr;
                tail = prev;
                delete curr;
            }
            else
            {
                tail = nullptr;
                delete curr;
            }
        }
    }
    void pop_front()
    {
        if (head)
        {
            Node *nxt = head->next;
            Node *curr = head;
            if (nxt)
            {
                head = nxt;
                nxt->prev = nullptr;
                delete curr;
            }
            else
            {
                head = nullptr;
                delete curr;
            }
        }
    }
    void deleteValue(int value)
    {
        if (head == NULL)
            return;
        Node *curr = head;
        while (curr && curr->data != value)
        {
            curr = curr->next;
        }
        if (curr)
        {
            if (curr->next == NULL)
                pop_back();
            else if (curr->prev == NULL)
                pop_front();
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }
        }
    }
    void deletePosition(int position)
    {
        if (head == nullptr)
            return;
        Node *curr = head;
        int curPos = 1;
        while (curr && curPos <= position)
        {
            curr = curr->next;
            curPos++;
        }
        if (curr)
        {
            if (curr->next == NULL)
                pop_back();
            else if (curr->prev == NULL)
                pop_front();
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }
        }
    }
};
int main()
{
    DLL dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.print(); // 1 2
    dll.push_front(0);
    dll.push_front(5);
    dll.print(); // 5 0 1 2
    dll.pop_back();
    dll.print(); // 5 0 1
    dll.pop_front();
    dll.print(); // 0 1
    dll.afterPositionInsert(10, 100);
    dll.afterPositionInsert(10, 1);
    dll.print(); // 0 10 1
    dll.insertAfterValue(10, 100);
    dll.insertAfterValue(1000, 100);
    dll.print(); // 0 10 100 1
    dll.deleteValue(100);
    dll.deleteValue(1000);
    dll.print(); // 0 10 1
    dll.afterPositionInsert(100, 2);
    dll.print(); // 0 10 100 1
    dll.deletePosition(2);
    dll.print(); // 0 100 1
}