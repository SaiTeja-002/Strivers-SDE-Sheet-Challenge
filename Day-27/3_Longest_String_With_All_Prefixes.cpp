#include <bits/stdc++.h> 

class Node
{
    public:
        Node* child[26];
        bool isEnd;
};

void insert(string &w, Node* node)
{
    Node* cur = node;

    for(auto c:w)
    {
        if(!cur->child[c-'a'])
            cur->child[c-'a'] = new Node();

        cur = cur->child[c-'a'];
    }

    cur->isEnd = true;
}

bool fun(string &w, Node* node)
{
    Node* cur = node;

    for(auto c:w)
    {
        if(!cur->child[c-'a'])
            return false;
        cur = cur->child[c-'a'];

        if(!cur->isEnd)
            return false;
    }

    return true;
}

string completeString(int n, vector<string> &arr)
{
    Node* node = new Node();

    for(auto w:arr)
        insert(w, node);

    string ans = "";

    for(auto w:arr)
        if(fun(w, node))
            if(ans.size() <= w.length())
                ans = (ans.length() == w.length()) ? (min(ans, w)) : (w);

    return (ans.length() == 0) ? ("None") : (ans);
}