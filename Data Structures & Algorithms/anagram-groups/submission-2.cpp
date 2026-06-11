class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(int i=0;i<strs.size();i++){
            string sorted=strs[i];
            sort(sorted.begin(),sorted.end());
            mpp[sorted].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto& s : mpp){
            ans.push_back(s.second);
        }
        return ans;
    }
};
