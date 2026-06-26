class Solution {
public:

    void f(vector<int>& nums, int target, int i,int sum,vector<int> &temp,vector<vector<int>> &ans){
        if(i==nums.size() || sum>target){
            return;
        }

        if(sum==target){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        f(nums,target,i,sum+nums[i],temp,ans);
        temp.pop_back();
        f(nums,target,i+1,sum,temp,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp; 
        
        f(nums,target,0,0,temp,ans);
        return ans;
    }
};
