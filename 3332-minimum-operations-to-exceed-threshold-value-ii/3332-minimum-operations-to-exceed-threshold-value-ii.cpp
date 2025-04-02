class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int n = nums.size();

        priority_queue<long long ,vector<long long >,greater<long long>> pq;




        for(int i = 0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        
        int count = 0;
        while(pq.size() >1)
        {
            long long int x = pq.top();
            pq.pop();
           long long int y = pq.top();
            pq.pop();

            if(x >= k && y >=k)
            break;

            if(x < k || y < k)
            {
                pq.push((long long)(min(x,y) * 2 + (long long )max(x,y)));
                count++;
            }


            
        }

        return count;
        
    }
};