class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0; i < n ; i++)
        gas.push_back(gas[i]),cost.push_back(cost[i]);

        int cnt=0,sum = 0,index = 0;
        for(int i=0 ; i < 2*n ; i++){
            if(sum < 0)
            cnt = 0,sum = 0,index = i;
            if(cnt == n){
                return index;
            }
            sum += (gas[i] - cost[i]);
            cnt++;
        }

        return -1;
    }
};

/*

*/