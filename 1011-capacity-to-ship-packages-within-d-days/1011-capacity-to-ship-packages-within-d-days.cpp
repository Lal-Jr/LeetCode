class Solution {
public:
    int isPossibleSol(vector<int>& weights, int days, int mid){
        int daysCount = 1, weightsCount = 0;
        int n = weights.size();
        
        for(int i=0; i<weights.size(); i++){
            if(weightsCount+weights[i]<=mid)
                weightsCount+=weights[i];
            else {
                daysCount++;
                weightsCount = 0;
                if(weightsCount+weights[i] > mid || daysCount > days)
                    return false;
                weightsCount+=weights[i];
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        
        int start = 0, end = sum, ans=0;
        int mid = start+(end-start)/2;
        
        while(start<=end){
            if(isPossibleSol(weights,days,mid)){
                ans = mid;
                end = mid-1;
            }
            else
                start = mid+1;
            mid = start+(end-start)/2;
        }
        
        return ans;
    }
};