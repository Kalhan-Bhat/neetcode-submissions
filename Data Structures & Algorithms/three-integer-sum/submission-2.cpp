class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){continue;}
            int target=-nums[i];

            int l=i+1;
            int h=n-1;

            while(l<h){
                if(nums[l]+nums[h]>target){
                    h--;
                }
                else if(nums[l]+nums[h]<target){
                    l++;
                }
                else{
                    ans.push_back({-target,nums[l],nums[h]});
                    l++;
                    h--;

                     while(l < h && nums[l] == nums[l-1])
                        l++;

                    while(l < h && nums[h] == nums[h+1])
                        h--;
                }
            }

        }

        return ans;
    }
};
