class Solution {
public:
    int mod = 0;
    int dp[1001][6][6][6][6][6];
    int solve(int m, int n, int index, int p1, int p2, int p3, int p4, int p5) {
        if (index == n)
            return 1;
        int ans = 0;

       

        


        if(dp[index][p1][p2][p3][p4][p5] != -1)
        {
        return dp[index][p1][p2][p3][p4][p5];
        }

        cout<<"solve below dp";


        for (int col1 = 1; col1 <= 3 ; col1++) {
            if (p1 == col1)
                continue;
                      if(m == 1){
                            ans = (ans + solve(m, n, index + 1, col1, 0,0,0,0) % mod) %mod;
                        }

            for (int col2 = 1; col2 <= 3  ; col2++) {
                if (col1 == col2 || p2 == col2)
                    continue;
                    if(m == 2){
                            ans = (ans + solve(m, n, index + 1, col1, col2, 0,0,0) % mod)%mod;
                        }


                for (int col3 = 1; col3 <= 3 ; col3++) {
                    if (col2 == col3 || p3 == col3)
                        continue;
                        if(m == 3){
                            ans = (ans + solve(m, n, index + 1, col1, col2, col3,
                                              0, 0) %mod)%mod;
                        }
    

                    for (int col4 = 1; col4 <= 3; col4++) {
                        if (col3 == col4 || p4 == col4)
                            continue;
                            
                            if(m == 4){
                            ans = (ans + solve(m, n, index + 1, col1, col2, col3,
                                              col4,0) %mod)%mod;
                        }
                            

                        for (int col5 = 1; col5 <= 3 ; col5++) {
                            if (col4 == col5 || p5 == col5)
                                continue;
                            if(m == 5){
                            ans = (ans + solve(m, n, index + 1, col1, col2, col3,
                                              col4, col5) %mod)%mod;
                        }
                        }
                    }
                }
            }
        }
        return dp[index][p1][p2][p3][p4][p5] =   ans % mod;
    }
    int colorTheGrid(int m, int n) { 

        mod = 1000000007;


        memset(dp, -1, sizeof(dp));

       // cout<<"here"<<dp[0].size();

 
       return solve(m, n, 0, 0, 0, 0, 0, 0);

    }
};