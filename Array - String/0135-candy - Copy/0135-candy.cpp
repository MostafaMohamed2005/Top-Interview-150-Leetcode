class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0,le = 1,n = ratings.size(),asc_le = 0;
        bool desc = false,asc=false;
        for(int i=1 ; i <n ; i++){
            if(!desc && !asc){
                if(ratings[i] > ratings[i-1])
                asc = true,asc_le = le = 2;
                else if(ratings[i] < ratings[i-1])
                desc = true,le = 2;
                else
                ans++,le = 1,asc_le = 0;
            }else if(desc){
                if(ratings[i] < ratings[i-1])
                le++;
                else if(ratings[i] == ratings[i-1]){
                    ans += (le*(le+1))/2;
                    if(asc_le)
                    ans += max(0,le +1 - asc_le);
                    asc_le = 0;
                    le = 1;
                    desc = false;
                }
                else{
                    ans += (le*(le+1))/2;
                    ans--;
                    if(asc_le)
                    ans += max(0,le  +1 - asc_le);
                    asc_le = 0;
                    le = 2;
                    desc = false,asc = true;
                }
            }else{
                if(ratings[i] > ratings[i-1])
                le++;
                else if(ratings[i] == ratings[i-1]){
                    ans += (le*(le+1))/2;
                    asc_le = 0;
                    le = 1;
                    asc = false;
                }else{
                    ans += (le*(le+1))/2;
                    asc_le = le;
                    le = 1;
                    asc = false,desc = true;
                }
            }
        }

        if(le > 0)
        ans += (le*(le+1))/2;
        if(asc_le && desc)
        ans += max(0,le +1 - asc_le),asc_le = 0;
        return ans;
    }
};