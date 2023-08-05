#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left, *right, *parent;
    Node(int val, Node *parent) : val(val), left(NULL), right(NULL), parent(parent){};
};
class BST
{
    Node *root;

public:
    BST() : root(NULL){};
    ~BST() { delete root; }
    void insertIteratively(int val)
    {
        if (root == NULL)
        {
            root = new Node(val, NULL);
            return;
        }
        Node *curr = root, *par = NULL;
        while (curr)
        {
            par = curr;
            if (curr->val > val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (par->val > val)
            par->left = new Node(val, par);
        else
            par->right = new Node(val, par);
    }
    void insertRecursively(int val, Node *curr, Node *par)
    {
        if (curr == NULL)
        {
            if (par == NULL)
            {
                curr = new Node(val, NULL);
                return;
            }
            if (par->val > val)
            {
                par->left = new Node(val, par);
                return;
            }
            else
            {
                par->right = new Node(val, par);
                return;
            }
        }
        if (curr->val > val)
            insertRecursively(val, curr->left, curr);
        insertRecursively(val, curr->right, curr);
    }
    void insertRecursively(int val)
    {
        insertRecursively(val, root, NULL);
    }
    Node *search_iteratively(int val)
    {
        if (root == NULL)
            return root;
        Node *curr = root;
        while (curr)
        {
            if (curr->val > val)
                curr = curr->left;
            else if (curr->val < val)
                curr = curr->right;
            else
                return curr;
        }
        return NULL;
    }
    Node *search_recursively(int val, Node *curr)
    {
        if (curr == NULL)
            return NULL;
        if (curr->val == val)
            return curr;
        if (curr->val > val)
            return search_recursively(val, curr->left);
        return search_recursively(val, curr->right);
    }
    Node *search_recursively(int val)
    {
        return search_recursively(val, root);
    }
    bool isPresent(int val) { return search_recursively(val) == NULL ? false : true; }
    int height(Node *curr) { return curr ? max(height(curr->left), height(curr->right)) + 1 : 0; }
    int depth(Node *curr) { return curr ? 1 + depth(curr->parent) : 0; }
    int Childs(Node *curr)
    {
        if (curr == NULL)
            return -1;
        if (curr->left == NULL && curr->right == NULL)
            return 0;
        if (curr->left == NULL || curr->right == NULL)
            return 1;
        return 2;
    }
    void deleteLeaf(Node *curr, Node *par)
    {
        if (curr == root)
        {
            root = NULL;
            delete curr;
            return;
        }
        if (par->left == curr)
            par->left = NULL;
        else
            par->right = NULL;
        delete curr;
    }
    void deleteSingleChild(Node *curr, Node *par)
    {
        if (curr->left)
        {
            if (par == NULL)
            {
                root = curr->left;
                delete curr;
                return;
            }
            if (par->left == curr)
            {
                par->left = curr->left;
            }
            else
            {
                par->right = curr->left;
            }
            delete curr;
            return;
        }
        if (par == NULL)
        {
            root = curr->right;
            delete curr;
            return;
        }
        if (par->left == curr)
        {
            par->left = curr->right;
        }
        else
        {
            par->right = curr->right;
        }
        delete curr;
    }
    Node *leftest(Node *curr) { return curr->left ? leftest(curr->left) : curr; }
    Node *rightest(Node *curr) { return curr->right ? rightest(curr->right) : curr; }
    Node *inSucc(Node *curr)
    {
        if (curr)
        {
            curr = curr->right;
            return leftest(curr);
        }
        return curr;
    }
    Node *inPre(Node *curr)
    {
        if (curr)
        {
            curr = curr->left;
            return rightest(curr);
        }
        return curr;
    }
    void deleteNode(Node *curr)
    {
        Node *dltNode = curr;
        if (dltNode == NULL)
            return;
        if (Childs(dltNode) == 0)
        {
            deleteLeaf(dltNode, dltNode->parent);
            return;
        }
        if (Childs(dltNode) == 1)
        {
            deleteSingleChild(dltNode, dltNode->parent);
            return;
        }
        if (height(dltNode->left) > height(dltNode->right))
        {
            Node *pre = inPre(dltNode);
            dltNode->val = pre->val;
            deleteNode(pre);
            return;
        }
        Node *succ = inSucc(dltNode);
        dltNode->val = succ->val;
        deleteNode(succ);
    }
    void deleteNode(int val)
    {
        deleteNode(search_recursively(val));
    }
    void inorder(Node *curr)
    {
        if (curr)
        {
            inorder(curr->left);
            cout << curr->val << " ";
            inorder(curr->right);
        }
    }
    void print()
    {
        inorder(root);
        cout << endl;
    }
};
int main()
{
    BST bst;
    bst.insertIteratively(10);
    bst.insertIteratively(20);
    bst.insertRecursively(30);
    bst.print(); // 10 20 30
    bst.deleteNode(20);
    bst.print();                                                       // 10 30
    bst.isPresent(10) ? cout << "Present\n" : cout << "Not Present\n"; // Present
    bst.insertRecursively(50);
    bst.print(); // 10 30 50
}