class Solution {
public:
    int minCost(int index,vector<int>& cost, vector<int>& dp){
        if(index<=1) return 0;
        if(dp[index] != -1) return dp[index];
        int left=minCost(index-1,cost,dp) + cost[index-1];
        int right= INT_MAX;
        if(index>1) right=minCost(index-2,cost,dp) + cost[index-2];
        return dp[index] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return minCost(cost.size(),cost,dp);
    }
};