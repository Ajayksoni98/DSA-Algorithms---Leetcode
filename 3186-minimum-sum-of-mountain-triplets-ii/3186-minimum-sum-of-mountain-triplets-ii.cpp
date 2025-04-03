class Solution {
public:
    int minimumSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> leftmin(n,INT_MAX);

        vector<int> rightmin(n,INT_MAX);

        leftmin[0] = nums[0];
        leftmin[n-1] = nums[n-1];
        rightmin[n-1] = nums[n-1];
        int minval = INT_MAX;
        for(int i = 1;i<n-1;i++)
        {

            leftmin[i] = min(leftmin[i-1],nums[i]);
            rightmin[n-i-1] = min(rightmin[n-i],nums[n-i-1]);



        }

        for(int i = 1;i<n-1;i++)
        {
          if(leftmin[i-1] < nums[i] && rightmin[i+1] < nums[i])
            {
                minval = min(minval, leftmin[i-1] + nums[i] + rightmin[i+1]);
            }
        }

    

        return minval ==INT_MAX? -1: minval;
        
    }
};