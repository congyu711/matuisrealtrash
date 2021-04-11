#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class bst
{
public:
    int val, key;
    bst *lson, *rson;
    int sz;
    bst() : val(0), key(0), sz(0)
    {
        lson = nullptr;
        rson = nullptr;
    }
    bst(int v, int k) : val(v), key(k), sz(0)
    {
        lson = nullptr;
        rson = nullptr;
    }
    bst(int k, int v, int n) : key(k), val(v), sz(n)
    {
        lson = nullptr;
        rson = nullptr;
    }
};
int getval(bst *root, int key)
{
    if (root == nullptr)
        return -1; //doesn't exist
    else if (key == root->key)
        return root->val;
    else if (key > root->key)
        return getval(root->rson, key);
    else
        return getval(root->lson, key);
}
//find node a with key=_key, if val!=_val,update it,
//  if a doesn't exist, create a new node
bst *put(bst *root, int _key, int _val)
{
    if (root == nullptr)
        return new bst(_key, _val, 1);
    if (root->key > _key)
        root->lson = put(root->lson, _key, _val);
    else if (root->key < _key)
        root->rson = put(root->rson, _key, _val);
    else
        root->val = _val;
    //root->sz=root->lson->sz+root->rson->sz+1;
    int lsz = root->lson == nullptr ? 0 : root->lson->sz;
    int rsz = root->rson == nullptr ? 0 : root->rson->sz;
    root->sz = lsz + rsz + 1;
    return root;
}
bst *bstmin(bst *root) //pointer
{
    if (root->lson == nullptr)
        return root;
    return bstmin(root->lson);
}
int bstminkey(bst *root)
{
    return bstmin(root)->key;
}
bst *bstfloor(bst *root, int _key)
{
    if (root == nullptr)
        return nullptr;
    else if (root->key == _key)
        return root;
    else if (root->key > _key)
        return bstfloor(root->lson, _key);
    else
    {
        bst *t = bstfloor(root->rson, _key);
        if (t == nullptr)
            return root;
        else
            return t;
    }
}
bst *bstceil(bst *root, int _key)
{
    if (root == nullptr)
        return nullptr;
    else if (root->key == _key)
        return root;
    else if (root->key < _key)
        return bstceil(root->rson, _key);
    else
    {
        bst *t = bstceil(root->lson, _key);
        if (t == nullptr)
            return root;
        else
            return t;
    }
}
//notice! rank of the smallest num is 0
bst *bstselect(bst *root, int k)
{
    if (root == nullptr)
        return nullptr;
    int t = root->lson == 0 ? 0 : root->lson->sz;
    if (t > k)
        return bstselect(root->lson, k);
    else if (t < k)
        return bstselect(root->rson, k - t - 1);
    else
        return root;
}
int bstrank(int _key, bst *root)
{
    if (root == nullptr)
        return 0;
    else if (root->key > _key)
        return bstrank(_key, root->lson);
    else if (root->key < _key)
    {
        int lsz = root->lson == nullptr ? 0 : root->lson->sz;
        return lsz + 1 + bstrank(_key, root->rson);
    }
    else
    {
        int lsz = root->lson == nullptr ? 0 : root->lson->sz;
        return lsz;
    }
}
bst *bstdelmin(bst *root)
{
    if (root->lson == nullptr)
        return root->rson;
    root->lson = bstdelmin(root->lson);
    int lsz = root->lson == nullptr ? 0 : root->lson->sz;
    int rsz = root->rson == nullptr ? 0 : root->rson->sz;
    root->sz = lsz + rsz + 1;
    return root;
}
bst *bstdel(bst *root, int _key)
{
    if (root == nullptr)
        return nullptr;
    if (root->key > _key)
        root->lson = bstdel(root->lson, _key);
    else if (root->key < _key)
        root->rson = bstdel(root->rson, _key);
    else
    {
        if (root->lson == nullptr)
            return root->rson;
        if (root->rson == nullptr)
            return root->lson;
        bst *t = root;
        root = bstmin(root->rson);
        root->rson = bstdelmin(t->rson);
        root->lson = t->lson;
    }
    //root->sz = root->lson->sz + root->rson->sz + 1;
    int lsz = root->lson == nullptr ? 0 : root->lson->sz;
    int rsz = root->rson == nullptr ? 0 : root->rson->sz;
    root->sz = lsz + rsz + 1;
    return root;
}
void midorderprint(bst *root)
{
    if (root == nullptr)
        return;
    midorderprint(root->lson);
    cout << root->key << ' ' << root->sz << endl;
    midorderprint(root->rson);
}
//find nodes(lo<=key<=hi) and put them into res.
void keys(bst *root, int lo, int hi, queue<bst *> &res)
{
    if (root == nullptr)
        return;
    if (lo < root->key)
        keys(root->lson, lo, hi, res);
    if (root->key >= lo && root->key <= hi)
        res.push(root);
    if (hi > root->key)
        keys(root->rson, lo, hi, res);
}
int main()
{
    ifstream infile;
    infile.open("bst1.in");
    int n, c;
    infile >> n;
    infile >> c;
    bst *binarysearchtree = new bst(c, c);
    for (int i = 1; i < n; i++)
    {
        infile >> c;
        put(binarysearchtree, c, c);
    }
    midorderprint(binarysearchtree);
    queue<bst *> q;
    keys(binarysearchtree, 0, 19, q);
    while (!q.empty())
    {
        cout << q.front()->key << ' ';
        q.pop();
    }
    cout << endl;
}