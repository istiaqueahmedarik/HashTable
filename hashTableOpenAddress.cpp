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
    }
    Data() {}
    A getKey() { return key; }
    B getVal() { return value; }
};

template <class A, class B>
class HashTable
{
    Data<A, B> **table;
    long long mx;
    Data<A, B> *deleted;

public:
    HashTable(long long size = 20)
    {
        table = new Data<A, B> *[size];
        mx = size;
        for (long long int i = 0; i < size; i++)
            table[i] = NULL;
        deleted = new Data<A, B>;
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
    unsigned long long Hash(long long p)
    {
        return max(0LL, p % mx);
    }
    // insert function mixed probing method and chain method
    bool insert(Data<A, B> *data)
    {
        if (data == NULL)
            return false;
        int index = Hash(data->getKey());
        if (table[index] != NULL && table[index] != deleted)
            return insert_in_OpenAddress(data, index);
        table[index] = data;
    }

    // insert in probing method
    bool insert_in_OpenAddress(Data<A, B> *data, int index)
    {
        if (data == NULL)
            return false;
        for (int i = 0; i < mx; i++)
        {
            int nextPlace = (i + index) % mx;
            if (table[nextPlace] == NULL)
            {
                table[nextPlace] = data;
                return true;
            }
        }
        return false;
    }
    // find key
    Data<A, B> *find(A a)
    {
        int ind = Hash(a);
        for (int i = 0; i < mx; i++)
        {
            int nextPlace = (i + ind) % mx;
            if (table[nextPlace] == NULL)
                return NULL;
            if (table[nextPlace] == deleted)
                continue;
            if (table[nextPlace]->getKey() == a)
                return table[nextPlace];
        }
        return NULL;
    }
    Data<A, B> *operator[](A a)
    {
        int ind = Hash(a);
        for (int i = 0; i < mx; i++)
        {
            int nextPlace = (i + ind) % mx;
            if (table[nextPlace] == NULL)
                return NULL;
            if (table[nextPlace] == deleted)
                continue;
            if (table[nextPlace]->getKey() == a)
                return table[nextPlace];
        }
        return NULL;
    }
    // delete
    Data<A, B> *erase(A a)
    {
        int ind = Hash(a);
        for (int i = 0; i < mx; i++)
        {
            int nextPlace = (i + ind) % mx;
            if (table[nextPlace] == NULL)
                return NULL;
            if (table[nextPlace] == deleted)
                continue;
            if (table[nextPlace]->getKey() == a)
            {
                Data<A, B> *temp = table[nextPlace];
                table[nextPlace] = deleted;
                return temp;
            }
        }
        return NULL;
    }
    void Print()
    {
        for (long long i = 0; i < mx; i++)
        {
            if (table[i] == NULL)
            {
                cout << i << "-> <Empty>" << endl;
                continue;
            }
            if (table[i] == deleted)
            {
                cout << i << "-> <Deleted>" << endl;
                continue;
            }
            cout << table[i]->getKey() << "->" << table[i]->getVal() << endl;
        }
    }
    ~HashTable()
    {
        delete[] table;
        delete deleted;
    }
};

int main()
{
    HashTable<string, int> mp;
    while (1)
    {
        cout << "1. Insert\n2. Delete\n3. Find\n4. Print\n\nChoice: ";
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
            if (mp.insert(temp))
            {
                cout << "Successful!" << endl;
            }
            else
                cout << "Hash Table is full" << endl;
        }
        else if (choice == 2)
        {
            string s;
            cout << "Key: ";
            cin >> s;
            if (mp.erase(s) != NULL)
            {
                cout << "Deleted" << endl;
            }
            else
                cout << "Not Found" << endl;
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
        {
            mp.Print();
        }
    }
}