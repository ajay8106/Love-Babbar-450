/*
    link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    also refer to 26_sell_...twice.cpp
*/


// ----------------------------------------------------------------------------------------------------------------------- //
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int local = 0, global = 0;
    for (int i = 1;i < n;i++) {
        /*
            if the loss is going negative then make it 0 either continue with the profit as higher as possible.
        */
        local = max(0, local += prices[i] - prices[i - 1]);
        global = max(local, global);
    }
    return global;
}


// More easy

int maxProfit(vector<int>& prices) {
       int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }



//  More easy

int maxProfit(vector<int>& prices) {
        int pricesSize = prices.size();
        int minPricePos = 0,maxProfit = 0;
    for(int i = 1;i<pricesSize;i++)
    {
        if(prices[i] - prices[minPricePos] > maxProfit)
            maxProfit = prices[i] - prices[minPricePos] ;
        else if(prices[i] - prices[minPricePos] < 0)
            minPricePos = i;
    }
    return maxProfit;
    }






