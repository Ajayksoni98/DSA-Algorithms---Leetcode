class Solution {
public:

    int res = 0;
    int n = 0;

    void get_xor(vector<int> &temp)
    {
        int ans = 0;
        for(auto x : temp)
        {
            ans ^= x;
           // cout<<x<<" ";
        }
       // cout<<endl;

        res = res + ans;
    }
    void solve(vector<int> &nums,int index,vector<int> &temp)
    {

       // cout<<index<<endl;
       if(temp.size() >= 1)
        get_xor(temp);


        for(int i = index;i<n;i++)
        {

            temp.push_back(nums[i]);
            solve(nums,i+1,temp);
            temp.pop_back();

        }


    }
    int subsetXORSum(vector<int>& nums) {

         n = nums.size();

        vector<int> temp;
     
        solve(nums,0,temp);
        return res;
        
    }
};