class Solution {
public:
        vector<vector<vector<vector<int>>>> dp;
         int mod;
    int solve(int n, int index, int prev1,int prev2,int prev3)
    {
        if(index == n)
        return 1;

        if(dp[index][prev1][prev2][prev3] != -1)
        {
            return dp[index][prev1][prev2][prev3];
        }

        int ans  = 0;
        for(int col1 = 1;col1 <= 3;col1++)
        {
            if(col1 == prev1)
            continue;

            for(int col2 = 1;col2 <= 3;col2++)
            {
                if(col2 == prev2 || col2 == col1)continue;

                for(int col3 = 1;col3 <= 3;col3++)
                {
                    if(col3  == prev3 || col3 == col2)
                    continue;

                    ans = (ans + solve(n,index+1,col1, col2,col3) % mod) % mod;
                }

            }
        }

        return dp[index][prev1][prev2][prev3] = ans;
    }
    int numOfWays(int n) {

         mod = 1000000007;

        dp.resize(
            n, vector<vector<vector<int>>>(
                   4, vector<vector<int>>(4, vector<int>(4, -1))));



        return solve(n,0,0,0,0) % mod;


       // return 0;
        
    }
};