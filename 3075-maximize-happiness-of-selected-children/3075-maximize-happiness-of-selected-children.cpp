class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

       long long int count = 0;
        long long  diff = 0;

        int n = happiness.size();


        priority_queue<int> pq;
        for(auto x : happiness)
        {
            pq.push(x);
        }

        long long ans = 0;

        while(!pq.empty() && count < k)
        {
            if(pq.top() - diff <=0)
            {
                break;
            }

            int x = pq.top();
            pq.pop();

            ans += x;
            ans -= diff;

            diff++;
            count++;

        }
        return ans;
        
    }
};