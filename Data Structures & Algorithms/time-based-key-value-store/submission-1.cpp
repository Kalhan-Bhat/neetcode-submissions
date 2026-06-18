class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<int,string>>> mpp;
    void set(string key, string value, int timestamp) {
       
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end()){
            return "";
        }
        else{
            vector<pair<int,string>> v = mpp[key];
                int l=0;
                int r=v.size()-1;
                string ans;
                while(l<=r){
                    int mid= l+ (r-l)/2;
                    if(v[mid].first<=timestamp){
                        ans=v[mid].second;
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
                return ans;
           
        }

        return "";
    }
};
