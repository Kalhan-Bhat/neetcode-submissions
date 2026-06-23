class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> ans;
        vector<int> mp(26,0);
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]-'A']++;
        }
           
        priority_queue<int> q;

        for(auto f:mp){
            if(f>0){
                q.push(f);
            }
        }
        int time=0;
        while(!q.empty()){
            vector<int> temp;
            for(int i=0;i<=n;i++){ 
                if(!q.empty()){
                int freq=q.top();
                q.pop();
                freq--;
                temp.push_back(freq);
                }
            }

            for(auto f:temp){
                if(f>0){
                    q.push(f);
                }
            }

            if(q.empty()){
                time+=temp.size();
            }
            else{
                time+=n+1;
            }

        }

        return time;

    }
};
