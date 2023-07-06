/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct TrieNode
{
    TrieNode* child[26];
    bool isEnd;
    TrieNode()
    {
        for(int i=0; i<26; i++)
            child[i] == NULL;

        isEnd = false;
    }
};


class Trie {
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++)
        {
            int index = word[i]-'a';

            if(!cur->child[index])
                cur->child[index] = new TrieNode();
            
            cur = cur->child[index];
        }

        cur->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode* cur = root;

        for(int i=0; i<word.size(); i++)
        {
            int index = word[i]-'a';

            if(!cur->child[index])
                return false;
            
            cur = cur->child[index];
            
        }

        return cur->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode* cur = root;

        for(int i=0; i<prefix.size(); i++)
        {
            int index = prefix[i]-'a';
        
            if(!cur->child[index])
                return false;
            
            cur = cur->child[index];
        }

        return true;
    }
};