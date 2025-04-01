class Solution {
public:
    int n = 0;

    vector<long long int> dp;
    long long solve(vector<vector<int>> &questions,int index)
    {
        if(index >= n)return 0;

        if(dp[index] != -1)
        return dp[index];

        return dp[index] = max((long long )questions[index][0] + (long long )solve(questions,index + questions[index][1]+1), (long long)solve(questions,index+1) );
    }
    long long mostPoints(vector<vector<int>>& questions) {


        n = questions.size();
        dp.resize(n,-1);

        return solve(questions,0);
        
    }
};