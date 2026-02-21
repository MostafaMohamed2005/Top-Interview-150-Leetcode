class Solution {
public:
    string simplifyPath(string path) {
        string ans = "/";
        int cnt = 0;
        bool word = false;
        for(int i=1 ; i < path.size() ; i++){
            

            if(path[i] == '/' ){
                    if(ans.back() != '/'){
                        //cout << i << " " << cnt << endl;
                        if(cnt >= 3 || !cnt || word)
                        ans += "/",word = false;
                        else if(cnt == 2){
                            for(int j=0 ; j < 3; j++)
                            ans.pop_back();
                            if(ans.empty())
                            ans = "/";
                            while(!ans.empty() && ans.back() != '/')
                            ans.pop_back();   
                        }
                        else
                        ans.pop_back();

                    }
            }
            else{
                ans += path[i];
                if(path[i] != '.')
                word = true;
            }

            cnt = (path[i] == '.' ? cnt + 1 : 0);
        }

        if(word)
        return ans;

        if(cnt == 2){
            for(int j=0 ; j < 3; j++)
            ans.pop_back();
            if(ans.empty())
            ans = "/";
            while(!ans.empty() && ans.back() != '/')
            ans.pop_back();
        }
        else if(cnt == 1)
        ans.pop_back(),ans.pop_back();
        
        if(ans.size() > 1 && ans.back() == '/')
        ans.pop_back();

        if(ans.empty())
        ans = "/";

        return ans;
    }
};