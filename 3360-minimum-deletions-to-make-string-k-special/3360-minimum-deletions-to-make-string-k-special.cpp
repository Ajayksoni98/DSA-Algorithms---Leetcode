class Solution {
public:
    int minimumDeletions(string word, int k) {

        int n = word.size();

        unordered_map<char,int> mp;

        for(int i = 0;i<n;i++)
        {
            mp[word[i]]++;
        }

        int ans = INT_MAX;;

        for(auto x : mp)
        {
            char fixed_char = x.first;
            int freq = x.second;

            int to_del = 0;

            for(auto y : mp)
            {

                if(freq > y.second)
                {
                    to_del += y.second;
                }
                else if(freq + k < y.second)
                {
                    to_del = to_del + (y.second - freq -k);
                }

            }

            ans = min(ans,to_del);

        
        }

        return ans;


        
    }
};