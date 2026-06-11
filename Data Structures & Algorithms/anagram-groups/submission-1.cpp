class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;

        for(const auto& s:strs){
            string sorted=s;
            sort(sorted.begin(),sorted.end());
            mpp[sorted].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto& s : mpp){
            ans.push_back(s.second);
        }
        return ans;
    }
};
