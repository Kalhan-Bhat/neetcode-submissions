class Solution {
public:
    bool isPalindrome(string s) {
        string k;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                k+= tolower(s[i]);
            }
        }
        s=k;
        reverse(k.begin(),k.end());
        return k==s;
    }
};
