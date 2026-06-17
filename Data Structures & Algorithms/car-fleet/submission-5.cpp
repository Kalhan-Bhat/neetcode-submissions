class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,int>> st;
        vector<pair<int,int>> p;

        for(int i=0;i<position.size();i++){
            p.push_back({position[i],speed[i]});
        }
        int count=1;
        sort(p.rbegin(),p.rend());
        double prevtime=(double)(target-p[0].first)/p[0].second;

        for(int i=1;i<p.size();i++){
            double current=(double)(target-p[i].first)/p[i].second;
            if(current>prevtime){
                count++;
                prevtime=current;
            }
        }

        return count;
    }
};
