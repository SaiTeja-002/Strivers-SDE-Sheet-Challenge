#include<bits/stdc++.h>

class LFUCache
{
    int capacity;
    int minFreq;

    unordered_map<int, pair<int, int>> keyVal;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int cap) 
    {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key) 
    {
        if (keyVal.find(key) == keyVal.end())
            return -1;

        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;

        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();

        if(freqList[minFreq].empty())
            minFreq++;

        return keyVal[key].first;
    }

    void put(int key, int value) 
    {
        if(capacity == 0)
            return;

        if(keyVal.find(key) != keyVal.end()) 
        {
            keyVal[key].first = value;
            get(key);

            return ;
        }

        if(keyVal.size() == capacity) 
        {
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);

            freqList[minFreq].pop_front();
            pos.erase(delKey);
        }

        keyVal[key] = {value, 1};
        freqList[1].push_back(key);
        
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};
