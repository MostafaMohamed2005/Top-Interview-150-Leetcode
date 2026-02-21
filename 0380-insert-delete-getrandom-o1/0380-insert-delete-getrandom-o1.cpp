class RandomizedSet {

public:
    unordered_map<int,pair<int,int>>m;
    vector<int>key;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(!m[val].first){
            key.push_back(val),m[val].second = key.size()-1;
            m[val].first=1;
            return true;
        }else{
            m[val].first=1;
            return false;
        }
    }
    
    bool remove(int val) {
        if(m[val].first){
            m[val].first = 0;
            int pos = m[val].second;
            if(pos != key.size()-1){
                swap(key[pos],key[key.size()-1]);
                key.pop_back();
                m[key[pos]].second = pos; 
            }else{
                key.pop_back();
            }
            return true;
        }
        else{
            return false;
        }
    }
    
    /*
        2  
    */
    int getRandom() {
        int random = rand()%key.size();
        return key[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */