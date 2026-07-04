class Solution {
public:

    void f ( int open,int close,int n,string& temp,vector<string>& ans){
       
        if(open==close && close==n){
            ans.push_back(temp);
        }

        if(open<n){
        temp+='(';
        f(open+1,close,n,temp,ans);
        temp.pop_back();
        }
        if(close<open){
            temp+=')';
            f(open,close+1,n,temp,ans);
            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
       f(0,0,n,temp,ans);

       return ans;
    }
};
