class Solution {
public:
    int find(vector<int>&nums,int left,int right,int target,bool flag)
    {

        int n = nums.size();

        while(left <= right)
        {
            int mid = left + (right - left ) /2;


            if(nums[mid] == target)
            {
                if(!flag)
                {
                    if(mid == 0 || nums[mid-1] != target)
                        return mid;
                    else
                        right = mid -1;
                }
                else
                {
                    if(mid == n-1 || nums[mid+1] != target)
                    {
                        return mid;
                    }
                    else 
                        left = mid +1;
                }
            }
            else if(nums[mid] < target)
            {
                left = mid+1;
            }
            else
            right = mid -1;
        }

        return -1;

    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        int left = 0;
        int right = n-1;

        int start = find(nums,0,n-1,target, false);

        int end = find(nums,0,n-1,target,true);
        

        return {start,end};
    }
};