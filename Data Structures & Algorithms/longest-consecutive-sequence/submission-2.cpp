class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ans;
    
        for(int i=0;i<nums.size();i++){
           ans.insert(nums[i]);
        }
        int maxi=0;
        int cnt;
        for(auto& it : ans){

            if(ans.find(it-1)==ans.end()){
                cnt=1;
                int x=it;
                while(ans.find(x+1)!=ans.end()){
                    cnt++;
                    x=x+1;
                }
                maxi=max(maxi,cnt);
            }
            

        }
        return maxi;


    }
};
