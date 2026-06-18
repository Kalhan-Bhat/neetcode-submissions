class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int l=0;
        int ans=INT_MAX;
        int r=nums.size()-1;
        while(l<=r){

            if(nums[l]<nums[r]){
                ans=min(ans,nums[l]);
                break;
            }

            int mid=l + (r-l)/2;
            if(nums[mid]>=nums[l]){
                ans = min(ans, nums[l]);
                l=mid+1;
            }
            else{
                ans = min(ans, nums[mid]);
                r=mid-1;
            }

        }

        return ans;

    }
};
