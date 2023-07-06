#include <bits/stdc++.h> 

class Node{
    public:
        Node* links[26];
};


void fun(Node* root, string& str, int& count)
{
    int n = str.length();
    Node* cur = root;

    for(int i=0; i<n; i++)
    {
        if(!cur->links[str[i]-'a'])
        {
            count++;
            cur->links[str[i]-'a'] = new Node();
        }

        cur = cur->links[str[i]-'a'];
    }
}

int distinctSubstring(string &word)
{
    int n = word.length();
    Node* root = new Node();

    int count=0;

    for(int i=0; i<n; i++)
    {
        string temp;

        for(int j=i; j<n; j++)
        {
            temp += word[j];
            fun(root, temp, count);
        }
    }

    return count;
}