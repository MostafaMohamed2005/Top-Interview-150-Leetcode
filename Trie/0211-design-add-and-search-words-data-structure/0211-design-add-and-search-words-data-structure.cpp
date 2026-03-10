class WordDictionary {
public:
    struct node{
        int exist[26]={};
        bool isWord = false;
    };

    vector<node>trie;
    WordDictionary() {
        trie.emplace_back();
    }
    
    void addWord(string word) {
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


    bool solve(int cur_level, string& word, int i){
        if(word.size() == i)
        return trie[cur_level].isWord;
        
        bool ans = false;
        int x = word[i]-'a';
        if(word[i] == '.'){
            for(int j=0 ; j < 26 ; j++){
                if(trie[cur_level].exist[j])
                ans |= solve(trie[cur_level].exist[j],word,i+1);
            }
        }else{
            if(trie[cur_level].exist[x])
            ans |= solve(trie[cur_level].exist[x],word,i+1);
        }

        return ans;
    }

    bool search(string word) {
        bool ans = solve(0,word,0);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */