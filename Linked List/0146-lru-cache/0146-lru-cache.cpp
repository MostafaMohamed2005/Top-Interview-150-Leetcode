class LRUCache {
public:
    int cnt = 0;
    unordered_map<int,pair<int,list<int>::iterator>>m;
    list<int>l;
    LRUCache(int capacity) {
        cnt = capacity;
    }
    
    int get(int key) {
        if(!m.contains(key))
        return -1;
        else{
            int value = m[key].first;
            l.erase(m[key].second);
            l.push_back(key);
            auto it = l.end();
            it--;
            m[key].second = it;
            return value;
        }
    }
    
    void put(int key, int value) {
        if(!m.contains(key)){
            if(!cnt){
                int ke = l.front();
                m.erase(ke);
                l.erase(l.begin());
            }else{
                cnt--;
            }

            l.push_back(key);
            auto it = l.end();
            it--;
            m[key] = {value,it};
        }else{
            l.erase(m[key].second);
            l.push_back(key);
            auto it = l.end();
            it--;
            m[key]= {value,it};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */