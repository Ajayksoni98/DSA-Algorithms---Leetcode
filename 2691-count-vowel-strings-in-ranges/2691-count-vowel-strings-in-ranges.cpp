class Solution {
public:

    set<char> st;

    bool check(string &word)
    {

        if(st.count(word[0]) == 1 && st.count(word[word.size()-1]))return true;
        return false;

    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int n = words.size();
        int q_size = queries.size();

        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');


        vector<int> prefix(n,0);
        for(int i = 0;i<n;i++)
        {

            bool flag = check(words[i]);

            if(i == 0)
            {
                if(flag)
                {
                    prefix[i] = 1;
                }
                
            }
            else
            {
                if(flag)
                prefix[i] = prefix[i-1] + 1;
                else
                prefix[i] = prefix[i-1];
            }

        }

        vector<int> ans;
        for(auto x : queries)
        {
            if(x[0] ==0)
            {
                ans.push_back(prefix[x[1]]);
            }else
            ans.push_back(prefix[x[1]] - prefix[x[0] -1]);

        }

        return ans;
        
    }
};