#include <bits/stdc++.h>
using namespace std;

template <class A, class B>
class Data
{

    A key;
    B value;

public:
    Data *next;
    Data(A key, B value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    A getKey() { return key; }
    B getVal() { return value; }
};

template <class A, class B>
class HashTable
{
    Data<A, B> **table;
    long long mx;
    int sz;

public:
    HashTable(long long size = 10)
    {
        table = new Data<A, B> *[mx = size];
        for (long long int i = 0; i < size; i++)
            table[i] = NULL;
        sz = 0;
    }
    unsigned long long Hash(const string &s)
    {
        unsigned long long ret = 0;
        for (char i : s)
        {
            ret = (ret + i) % mx;
            ret = (ret * (unsigned long long)i) % mx;
        }
        return ret;
    }
    unsigned long long Hash(long long p) { return max(0LL, p % mx); }
    void insert(Data<A, B> *data)
    {
        if (data == NULL)
            return;
        int index = Hash(data->getKey());
        if (table[index] != NULL)
            insert_in_chain(data, index);
        else
        {
            table[index] = data;
            sz++;
        }
    }

    void insert_in_chain(Data<A, B> *data, int index)
    {
        if (data == NULL)
            return;
        Data<A, B> *curr = table[index];
        while (curr->next)
            curr = curr->next;
        curr->next = data;
        sz++;
    }

    Data<A, B> *find(A a)
    {
        int ind = Hash(a);
        Data<A, B> *curr = table[ind];
        while (curr)
        {
            if (curr->getKey() == a)
                return curr;
            curr = curr->next;
        }
        return NULL;
    }
    Data<A, B> *operator[](A a)
    {
        int ind = Hash(a);
        Data<A, B> *curr = table[ind];
        while (curr)
        {
            if (curr->getKey() == a)
                return curr;
            curr = curr->next;
        }
        return NULL;
    }
    bool erase(A a)
    {
        int ind = Hash(a);
        if (table[ind] != NULL)
        {
            Data<A, B> *curr = table[ind];
            Data<A, B> *prev = NULL;
            while (curr && curr->getKey() != a)
            {
                prev = curr;
                curr = curr->next;
            }
            if (curr == NULL)
                return false;
            if (prev == NULL)
            {
                table[ind] = curr->next;
                sz--;
                return true;
            }
            else
            {
                prev->next = curr->next;
                sz--;
                return true;
            }
            return false;
        }
    }
    int getSize() { return sz; }
    void PrintLL(int index)
    {
        Data<A, B> *curr = table[index];
        cout << index << "-->";
        while (curr->next)
        {
            cout << "(" << curr->getKey() << "<->" << curr->getVal() << ")->";
            curr = curr->next;
        }
        cout << "(" << curr->getKey() << "<->" << curr->getVal() << ")\n";
    }
    void Print()
    {
        for (long long i = 0; i < mx; i++)
        {
            if (table[i] == NULL)
            {
                cout << i << "--> <Empty>\n";
                continue;
            }
            PrintLL(i);
        }
        cout << endl;
    }
    ~HashTable() { delete[] table; }
};

int main()
{
    HashTable<string, int> mp;
    while (1)
    {
        cout << "1. Insert\n2. Delete\n3. Find\n4. Size\n5. Print\n\nChoice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            string s;
            cout << "Key: ";
            cin >> s;
            int x;
            cout << "Value: ";
            cin >> x;
            Data<string, int> *temp = new Data<string, int>(s, x);
            mp.insert(temp);
        }
        else if (choice == 2)
        {
            string s;
            cout << "Key: ";
            cin >> s;
            if (mp.erase(s))
                cout << "Deleted\n";
            else
                cout << "Not Found\n";
        }
        else if (choice == 3)
        {
            string s;
            cout << "Key: ";
            cin >> s;
            if (mp.find(s) != NULL)
                cout << "Found" << endl;
            else
                cout << "Not Found" << endl;
        }
        else if (choice == 4)
            cout << "Size " << mp.getSize() << endl;
        else if (choice == 5)
            mp.Print();
    }
}