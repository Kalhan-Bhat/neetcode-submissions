class Solution {
public:
    string minWindow(string s, string t) {
       
       vector<int> hash(256,0);
       for(int i=0;i<t.size();i++){
            hash[t[i]]++;
       }

       int l=0;
       int r=0;
       int len=INT_MAX;
       int idx=-1;
        int count=0;
       while(r<s.size()){
            if(hash[s[r]]>0){
                count++;
            }
            hash[s[r]]--;

            while(count==t.size()){
                if(r-l+1<len){
                    len=r-l+1;
                    idx=l;
                }

                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count--;
                    
                }
                l++;
            }
            r++;
       }

       if(idx==-1){
        return "";
       }

       else{
        return s.substr(idx,len);
       }
    }
};
