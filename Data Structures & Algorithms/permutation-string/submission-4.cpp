class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        if(s1.size()>s2.size()){
            return false;
        }
        vector<int> freq1(26,0);
        for(int i=0;i<n;i++){
            freq1[s1[i]-'a']++;
        }
        vector<int> freq2(26,0);
         for(int i=0;i<n;i++){
            freq2[s2[i]-'a']++;
        }
        int r=n;
        int l=0;
         if(freq1==freq2){
                return true;
            }
        while(r<s2.size()){
            freq2[s2[l]-'a']--;
            freq2[s2[r]-'a']++;
            r++;
            l++;
            if(freq1==freq2){
                return true;
            }
        }

        return false;
    }
};
