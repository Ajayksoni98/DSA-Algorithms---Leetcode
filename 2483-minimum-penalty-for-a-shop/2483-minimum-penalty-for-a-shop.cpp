class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int pre = 0, suf = count(customers.begin(), customers.end(), 'Y');
        int ans = pre + suf, time = 0;
        for(int i = 0; i < n; i++) {
            pre += (customers[i] == 'N');
            suf -= (customers[i] == 'Y');
            if(ans > pre + suf) {
                ans = pre + suf;
                time = i+1;
            }
        }
        return time;
    }
};