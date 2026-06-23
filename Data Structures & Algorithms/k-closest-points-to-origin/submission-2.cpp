class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>q;

        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int dis=pow(x,2) + pow(y,2);
            q.push({dis,points[i]});
        }

        while(k!=0){
            ans.push_back(q.top().second);
            q.pop();
            k--;
        }
        return ans;
    }
};
