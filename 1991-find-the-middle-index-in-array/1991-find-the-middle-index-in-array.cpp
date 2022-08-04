class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum=0,leftSum=0,rightSum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            sum-=nums[i];
            rightSum=sum;
            if(leftSum==rightSum) return i;
            leftSum+=nums[i];
        }
        return -1;
    }
};