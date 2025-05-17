class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int r = 0;
        int w = 0;
        int b = 0;

        for(int i = 0;i<n;i++)
        {
            if(nums[i] == 0)r++;
            else if(nums[i]== 1) w++;
            else
            b++;
        }
        int j = 0;
        while(r!=0)
        {
            nums[j] = 0;
            j++;
            r--;
        }
                while(w!=0)
        {
            nums[j] = 1;
            j++;
            w--;
        }
                while(b!=0)
        {
            nums[j] = 2;
            j++;
            b--;
        }
        
    }
};