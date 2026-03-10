class Solution {
public:
    int calculate(string s) {
        stack<char>st;

        for(int i=0 ; i < s.size() ; i++){
            if(s[i] == ' ')
            continue;

            if(s[i] == ')'){

                int sum = 0;
                while(!st.empty() && st.top() != '('){
                    long long x = 0,ten = 1;
                    while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                        x += (st.top()-'0')*ten;
                        ten *= 10;
                        st.pop();
                    }

                    int cnt=0;
                    if(!st.empty() && st.top() != '('){
                        while(!st.empty() && (st.top() == '-'||st.top() == '+')){
                            if(st.top() == '-')
                            cnt++;
                            st.pop();
                        }
                        if(cnt%2 == 1)
                        x = -x;
                    }
                    
                    sum += x;
                }

                //cout << sum << endl;
                st.pop();
                string x = to_string(sum);
                for(int j=0; j < x.size() ; j++)
                st.push(x[j]);
            }else
            st.push(s[i]);
        }

        int sum = 0;
        while(!st.empty()){
                long long x = 0,ten = 1;
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    x += (st.top()-'0')*ten;
                    ten *= 10;
                    st.pop();
                }

                if(!st.empty()){
                    int cnt = 0;
                    while(!st.empty() && (st.top() == '-'||st.top() == '+')){
                            if(st.top() == '-')
                            cnt++;
                            st.pop();
                        }
                        if(cnt%2 == 1)
                        x = -x;
                }
                
                sum += x;
        }

        return sum;
    }
};

/*
    1 - if space continue
    2 - ) -> erase until reach (
    3 - 
*/