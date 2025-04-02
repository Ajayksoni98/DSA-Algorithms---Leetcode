class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {


        int n  = s.length();

        vector<int> diff;

        diff.resize(n+1,0);

        for(int i = 0;i<shifts.size();i++)
        {
            int left = shifts[i][0];
            int right = shifts[i][1];
            int  dir = shifts[i][2];

            if(dir == 0)
            {
                diff[left]+= (-1);
                diff[right+1] +=1;
            }
            else
            {
                diff[left]+=1;
                diff[right+1]-=1;
            }
        }


        for(int i = 1;i<n;i++)
        {
            diff[i] = diff[i] + diff[i-1];
        }

        string ans = "";

        for(int i = 0;i<n;i++)
        {

            cout<<(s[i]-97)+diff[i]<<endl;

            int x = ((s[i]-97)+diff[i])%26;

            if(x < 0)
            {
                x = 122 + x - 97 +1;
            }
          
            ans +=  'a' + x ;
        }

        return ans;
    }
};