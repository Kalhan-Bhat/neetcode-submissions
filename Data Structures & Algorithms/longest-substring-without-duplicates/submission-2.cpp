class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int maxi=0;
        unordered_map<char,int> mpp;
        while(r<s.size()){
            if(mpp.find(s[r])!=mpp.end()){
                l=max(l,mpp[s[r]]+1);
            }
            mpp[s[r]]=r;
            r++;
            maxi=max(maxi,r-l);

        }
        return maxi;
    }
};


