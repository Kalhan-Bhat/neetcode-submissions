class Solution {
public:
    vector<vector<int>> ans;

    void f(vector<int> &nums,vector<vector<int>> &ans,int index){
        if(index>nums.size()-1){
            ans.push_back(nums);
        }
        int n=nums.size();
        for(int i=index;i<n;i++){

            swap(nums[i],nums[index]);
            f(nums,ans,index+1);
            swap(nums[i],nums[index]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums,ans,0);
        return ans;
    }
};
