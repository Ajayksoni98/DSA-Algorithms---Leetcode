class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int n = tops.size();

        unordered_map<int,int> tp;
        unordered_map<int,int> bt;

        for(int i = 0;i<tops.size();i++)
        {
            tp[tops[i]]++;
            bt[bottoms[i]]++;
        }

        int ans = INT_MAX;

        for(int i = 1;i<7;i++)
        {
            int count1 = 0;
            for(int j = 0;j<n;j++)
            {
                if(tops[j] == i)
                {
                    continue;
                }
                else if(bottoms[j] == i)
                {
                    count1++;
                }
                else
                    {
                        count1 = -1;
                        break;
                    }
            }

            if(count1 != -1)
            {
                ans = min(ans,count1);
            }
            cout<<i<<" "<<count1<<endl;

            count1 = 0;
            for(int j = 0;j<n;j++)
            {
                if(bottoms[j] == i)
                {
                    continue;
                }
                else if(tops[j] == i)
                {
                    count1++;
                }
                else
                    {
                        count1 = -1;
                        break;
                    }
            }

             if(count1 != -1)
            {
                ans = min(ans,count1);
            }



        }

        return ans == INT_MAX?-1:ans;
        
        
    }
};