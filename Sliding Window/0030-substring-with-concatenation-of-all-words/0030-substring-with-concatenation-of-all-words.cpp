class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>freq;
        int n = words.size(),word_size = words[0].size();
        vector<int>ans;
        for(int i=0 ; i < n ; i++){
            freq[words[i]]++;
        }

        int unique_words = freq.size();

        for(int i=0 ; i < word_size ; i++){
            unordered_map<string,int>window;
            int current_unique_words = 0;
            int l = i, r = i,words_cnt = 0;
            while(true){
                
                if(r + word_size - 1 >= s.size())
                break;

                if(words_cnt == n){
                    string cur_s = s.substr(l,word_size);
                    if(window[cur_s] == freq[cur_s])
                    current_unique_words--;
                    window[cur_s]--;
                    if(window[cur_s] == freq[cur_s])
                    current_unique_words++;
                    l += word_size;
                }
                else
                words_cnt++;

                string cur_s = s.substr(r,word_size);
                if(window[cur_s] == freq[cur_s])
                current_unique_words--;
                window[cur_s]++;
                if(window[cur_s] == freq[cur_s])
                current_unique_words++;
                r += word_size;

                if(current_unique_words == unique_words)
                ans.push_back(l);
            }
        }

        return ans;
    }
};
