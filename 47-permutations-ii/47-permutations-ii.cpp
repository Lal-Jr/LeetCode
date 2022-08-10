class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& ans,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        
        set<int> placed;
        for(int j=index;j<nums.size();j++){
            if(placed.count(nums[j]))
                continue;
            placed.insert(nums[j]);
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1);
            swap(nums[j],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums,ans,0);
        return ans;
    }
};