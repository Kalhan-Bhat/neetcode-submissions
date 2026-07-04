class Solution {
public:
    void f(vector<int> temp,int i,vector<vector<int>>& ans,vector<int>& nums){

        if(i>nums.size()-1){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        f(temp,i+1,ans,nums);
        temp.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        f(temp,idx,ans,nums);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        f(temp,0,ans,nums);

        return ans;


    }
};
