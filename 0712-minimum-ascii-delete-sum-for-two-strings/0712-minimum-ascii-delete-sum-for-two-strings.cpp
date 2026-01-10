class Solution {
public:

    int m = 0;
    int n = 0;

    vector<vector<int>> dp;

    int solve(string &s1, string &s2,int i,int j)
    {

        if( i == m && j == n) return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if( i == m)
        return s2[j] + solve(s1,s2,i,j+1);
        else if (j==n)
        return s1[i] + solve(s1,s2,i+1,j);

        if(s1[i] == s2[j])
        {
            return dp[i][j] =  solve(s1,s2,i+1,j+1);
        }
        else
        {
            int x =  min(s1[i] + solve(s1,s2,i+1,j), s2[j] + solve(s1,s2,i,j+1));
            int y = s1[i] + s2[j] + solve(s1,s2,i+1,j+1);

            return dp[i][j] =  min(x,y);
        }

        return 0;

        
    }
    int minimumDeleteSum(string s1, string s2) {
        m = s1.size();
        n = s2.size();

        dp.resize(m+1,vector<int>(n+1,-1));
        return solve(s1,s2,0,0);
        
    }
};