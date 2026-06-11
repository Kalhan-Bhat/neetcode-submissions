class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        vector<pair<int,int>> ans;
        for(auto& s: mpp){
            ans.push_back({s.second,s.first});
        }

        sort(ans.rbegin(),ans.rend());
        vector<int> fans;
        for(int i=0;i<k;i++){
            fans.push_back(ans[i].second);
        }

        return fans;
    }
};
