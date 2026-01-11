class Solution {
public:
    int m = 0;
    int n = 0;


    int largestRect(vector<int>& heights) {

        int n = heights.size();

        stack<int> s;

        vector<int>nextsmallest(n,n);
        vector<int>prevsmallest(n,-1);

        int ans = 0;

        for(int i =0;i<n;i++)
        {

            while(!s.empty() && heights[s.top()] > heights[i])
            {
                nextsmallest[s.top()] = i;
                s.pop();
            }
            s.push(i);

        }


 
        for(int i =n-1;i>=0;i--)
        {

            while(!s.empty() && heights[s.top()] > heights[i])
            {
                prevsmallest[s.top()] = i;
                s.pop();
            }
            s.push(i);

        }

        for(int i =0;i<n;i++)
        {
            ans = max(ans, (nextsmallest[i]  - prevsmallest[i] - 1 ) * heights[i]);
        }

        return ans;
        
    }


    void convert(vector<vector<char>> &matrix,vector<vector<int>> &res)
    {

        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i == 0)
                {
                    if(matrix[i][j] == '1')
                    {
                        res[i][j] = 1;
                    }
                    else
                    {
                        res[i][j] = 0;
                    }
                }
                else
                {
                    if(matrix[i][j] == '0')
                    {
                        res[i][j] = 0;
                    }
                    else
                    {
                        if(res[i-1][j] == 0)
                        {
                            res[i][j] = 1;
                        }
                        else
                        {
                            res[i][j]= res[i-1][j]+1;
                        }
                    }
                }

            }
        }

    }
    int maximalRectangle(vector<vector<char>>& matrix) {

         m = matrix.size();
         n = matrix[0].size();

         vector<vector<int>> res(m,vector<int>(n,0));


        convert(matrix,res);

        int ans = 0;

        for(int i = 0;i<m;i++)
        {
            ans = max(ans,largestRect(res[i]));

        }

        return ans;



        
    }
};