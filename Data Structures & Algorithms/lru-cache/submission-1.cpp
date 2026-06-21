class LRUCache {
public:
    int n;
    vector<pair<int,int>> cache;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                pair<int,int> temp=cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                return temp.second;
            }
        }

        return -1;
    }
    
    void put(int key, int value) {
        
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                return;
            }
        }
        if(cache.size()==n){
            cache.erase(cache.begin());
        }
        cache.push_back({key,value});

    }
};
