class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            if (price < minPrice)
                minPrice = price;
            else
                maxProfit = max(maxProfit, price - minPrice);
        }
        
        return maxProfit;    
        /*
        int maxx=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                int proff=prices[j]-prices[i];
                maxx=max(maxx,proff);
            }
        }

        return maxx;
        */
    }
};