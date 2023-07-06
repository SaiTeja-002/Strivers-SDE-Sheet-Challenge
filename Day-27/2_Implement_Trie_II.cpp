#include <bits/stdc++.h>

struct TrieNode
{
    TrieNode *children[26];
    int cp=0;
    int end=0;
    TrieNode()
    {
        for(int i=0; i<26; i++)
            children[i]=NULL;

        cp=0;
        end=0;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string& key)
    {
        TrieNode *cur = root;

        for(int i=0; i<key.length(); i++)
        {
            if(!cur->children[key[i]-'a'])
                cur->children[key[i]-'a'] = new TrieNode();
            
            cur = cur->children[key[i]-'a'];
            cur->cp += 1;
        }

        cur->end += 1;
    }

    int countWordsEqualTo(string& key)
    {
        TrieNode *cur = root;

        for(int i=0; i<key.length(); i++)
        {
            if(!cur->children[key[i]-'a'])
                return 0;
            cur = cur->children[key[i]-'a'];
        }

        return cur->end;   
    }

    int countWordsStartingWith(string& key)
    {
        TrieNode *cur = root;
        for(int i=0; i<key.length(); i++)
        {
            if(!cur->children[key[i]-'a'])
                return 0;
            
            cur = cur->children[key[i]-'a'];
        }

        return cur->cp;
    }

    void erase(string& word)
    {
        TrieNode *cur = root;

        for(int i=0; i<word.length(); i++)
        {
            cur = cur->children[word[i]-'a'];
            cur->cp -= 1;
        }

        cur->end -= 1;
    }
};