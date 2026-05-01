class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        

        int n = nums.size();
        int sum = 0;

        int last_val = 0;

       for(int i = 0;i<n;i++)
       {
            sum += nums[i];
            last_val = last_val + i * nums[i];
       }

       int max_val = last_val;

       for(int i = 1 ;i<=n-1;i++)
       {

        last_val = (last_val + sum -nums[n-i]*n);
        
        max_val = max(max_val,last_val);
       }

       return max_val;

       

    }
};