#include <bits/stdc++.h> 

int findMinimumCoins(int amount) 
{
    int denominations[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int reqCoins=0;

    for(int i=8; i>=0; i--)
    {
        int coinCount = amount/denominations[i];

        reqCoins += coinCount;

        if(coinCount)   
            amount = (amount%denominations[i]);
    }

    return reqCoins;
}
