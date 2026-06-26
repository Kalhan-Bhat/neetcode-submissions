class Solution {
public:

     void f(vector<int>& nums, int target, int i,int sum,vector<int> &temp,vector<vector<int>> &ans){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        
        if(i==nums.size() || sum>target){
            return;
        }

        

        temp.push_back(nums[i]);
        
        
        f(nums,target,i+1,sum+nums[i],temp,ans);
        temp.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        f(nums,target,idx,sum,temp,ans);
        // we are allowed to take any times but we decide to not take then we should see then
        // is not the same elemetn present further so skip it as if not taking this and taking next same would result same


    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp; 
        sort(nums.begin(),nums.end());
        f(nums,target,0,0,temp,ans);
        return ans;
    }
};
