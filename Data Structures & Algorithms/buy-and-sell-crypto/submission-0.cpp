class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int cost=prices[0];
        for(int i=1;i<prices.size();i++){
            int profit=prices[i]-cost;
            cost=min(cost,prices[i]);
            maxi=max(maxi,profit);
        }      
    return maxi;  
    }
};
