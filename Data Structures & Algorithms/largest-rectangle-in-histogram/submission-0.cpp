class Solution {
public:
        vector<int> NSR(vector<int> heights){
            int n=heights.size();
            stack<int> st;
            vector<int> ans;
            for(int i=n-1;i>=0;i--){
                if(st.empty()){
                    ans.push_back(n);
                }

                else if (heights[st.top()]<heights[i]){
                    ans.push_back(st.top());
                }

                else if (heights[st.top()]>=heights[i]){
                    while(!st.empty() && heights[st.top()]>=heights[i]){
                        st.pop();
                    }

                    if(st.empty()){
                         ans.push_back(n);
                    }
                    else{
                         ans.push_back(st.top());
                    }
                }

                st.push(i);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }

        vector<int> NSL(vector<int>& heights){
            int n=heights.size();
            stack<int> st;
            vector<int> ans;
            for(int i=0;i<n;i++){
                if(st.empty()){
                    ans.push_back(-1);
                }

                else if (heights[st.top()]<heights[i]){
                    ans.push_back(st.top());
                }

                else if (heights[st.top()]>=heights[i]){
                    while(!st.empty() && heights[st.top()]>=heights[i]){
                        st.pop();
                    }

                    if(st.empty()){
                         ans.push_back(-1);
                    }
                    else{
                         ans.push_back(st.top());
                    }
                }

                st.push(i);
            }

            return ans;
        }
    int largestRectangleArea(vector<int>& heights) {    
             int n=heights.size();
             vector<int> a = NSL(heights);
             vector<int> b = NSR(heights);
              int maxi=INT_MIN;
             for(int i=0;i<n;i++){
                    int width=(b[i]-a[i])-1;
                   int area=heights[i]*width;
                      maxi=max(maxi,area);
      }
         return maxi;

    }
};
