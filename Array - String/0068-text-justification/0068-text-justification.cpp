class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int index = 0,n = words.size();
        vector<string>ans;
        while(index != n){
            int size = 0,cnt = 0;
            vector<string>v;
            while(index != n && size + cnt + words[index].size() <= maxWidth){
                size += words[index].size();
                cnt++;
                v.push_back(words[index++]);
            }

            string s = "";
            int rest;
            if(cnt == 1){
                s += v[0];
                for(int i=0 ; i < maxWidth - size ; i++)
                s += " ";
                ans.push_back(s);
                continue;
            }

            if(index != n){
                int rest = (maxWidth - size)/(cnt-1);
                int mod = (maxWidth - size)%(cnt-1);

                for(int i=0 ; i < v.size()-1 ; i++){
                    s += v[i];
                    int cnt;
                    if(mod)
                    cnt = rest + 1,mod--;
                    else
                    cnt = rest;
                    for(int i=0 ; i < cnt ; i++)
                    s += " ";
                }
                s += v.back();
                ans.push_back(s);
            }else{
                for(int i=0 ; i < v.size()-1 ; i++){
                    s += v[i] + " ";
                }
                s += v.back();
                int cur_size = s.size();
                for(int i=0 ; i < maxWidth - cur_size ; i++)
                s += " ";
                ans.push_back(s);
            }
        }

        return ans;
    }
};