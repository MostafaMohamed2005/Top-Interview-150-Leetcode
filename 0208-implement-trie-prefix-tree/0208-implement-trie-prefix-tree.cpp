class Trie {
public:
    struct node{
        int exist[26]={};
        bool isWord = false;
    };

    vector<node>trie;

    Trie() {
        trie.emplace_back();
    }
    
    void insert(string word) {
        int cur_level = 0;

        for(int i=0 ; i < word.size() ; i++){

            int x = word[i]-'a';

            if(!trie[cur_level].exist[x]){
                trie[cur_level].exist[x] = trie.size();
                cur_level = trie.size();
                trie.emplace_back();
            }else{
                cur_level = trie[cur_level].exist[x];
            }

            if(i == word.size()-1){
                trie[cur_level].isWord = true;
            }
        }
    }
    
    bool search(string word) {
        int cur_level = 0;

        for(int i=0 ; i < word.size() ; i++){
            int x = word[i]-'a';
            if(!trie[cur_level].exist[x])
            return false;
            
            cur_level = trie[cur_level].exist[x];

            if(i == word.size()-1 && !trie[cur_level].isWord)
            return false;
        }   

        return true;
    }
    
    bool startsWith(string prefix) {
        int cur_level = 0;

        for(int i=0 ; i < prefix.size() ; i++){
            int x = prefix[i]-'a';
            if(!trie[cur_level].exist[x])
            return false;
            
            cur_level = trie[cur_level].exist[x];
        }   

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */