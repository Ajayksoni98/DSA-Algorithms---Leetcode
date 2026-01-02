class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int maxval = 0;

        int count = 0;

        for(int i=0;i<nums.size();i++)
        {

            if(nums[i] == 0)
            {
                maxval = max(maxval,count);
                count = 0;
            }
            else
            count++;

        }
         maxval = max(maxval,count);

        return maxval;
        
    }
};