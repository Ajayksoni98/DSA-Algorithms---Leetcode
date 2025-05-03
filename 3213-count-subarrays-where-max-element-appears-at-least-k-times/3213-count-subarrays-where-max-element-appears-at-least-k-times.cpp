class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        int maxval = *max_element(nums.begin(),nums.end());

        int i = 0;
        int j = 0;

        long long ans = 0;
        int count = 0;

        while(i<n)
        {

            while(count < k && j < n)
            {
                if(nums[j] == maxval)
                count++;

                j++;
            }

           // cout<<count<<" "<<j<<endl;

            // if( j == n && count < k)
            // return -1;

            if(count == k)
            {
                ans += (n - j+1);
            }

            if(nums[i] == maxval)
            {
                count--;
            }
            i++;

        }

        // if(j== n && count >= k)
        // {
        //     ans += 1;
        // }

        return ans;
    }
};