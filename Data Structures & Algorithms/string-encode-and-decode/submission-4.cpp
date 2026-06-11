class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto& it:strs){
            s+=to_string(it.size())+"#"+it;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){j++;}
            int length=stoi(s.substr(i,j-i));
            string temp=s.substr(j+1,length);
            ans.push_back(temp);
            i=j+1+length;

        }
        return ans;
    }
};
