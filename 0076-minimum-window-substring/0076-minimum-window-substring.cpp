class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,m=s.size(),n=t.size(),mi = 1e9,cur_l = 0,cur_cnt=0,cnt=0;
        int freq[300]={},cur_freq[300]={};

        for(int i=0 ; i < n ; i++){
            if(!freq[t[i]])
            cnt++;
            freq[t[i]]++;
        }

        while(l < m){
            //cout << l << " " << r << endl;
            if(m != r){
                cur_freq[s[r]]++;
                if(freq[s[r]] == cur_freq[s[r]])
                cur_cnt++;
            }

            if(r <= m-1)
            r++;

            while(cnt == cur_cnt){
                if(mi > (r - l))
                mi = r - l,cur_l = l;

                cur_freq[s[l]]--;
                if(freq[s[l]] > cur_freq[s[l]])
                cur_cnt--;

                l++;
                if(l > r)
                r = l;
            }

            if(r == m){
                cur_freq[s[l]]--;
                if(freq[s[l]] > cur_freq[s[l]])
                cur_cnt--;
                l++;
            }
            
        }

        if(mi == 1e9)
        return "";
        else
        return s.substr(cur_l,mi);
    }
};