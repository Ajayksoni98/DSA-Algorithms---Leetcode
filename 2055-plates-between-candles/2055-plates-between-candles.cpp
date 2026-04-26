class Solution {
public:
    void print_array(vector<int> &left_array)
    {
        for(int i = 0;i<left_array.size();i++)
        {
            cout<<left_array[i]<<" ";

        }
        cout<<endl;
    }
    void solve(string &s,vector<int> &left_plates,vector<int> &right_plates)
    {
        int n = s.length();

        stack<int> st;

        int i = 0;
        while(i < n)
        {
            if(s[i] == '|')
            {
                right_plates[i] = i;
                i++;
            }
            else
            {
                while(i< n && s[i] == '*')
                {
                    st.push(i);
                    i++;
                }

                while(i < n && !st.empty())
                {
                    right_plates[st.top()] = i;
                    st.pop();
                }
                if(i == n)
                {
                    while(st.empty())
                    {
                        right_plates[st.top()] = -1;
                        st.pop();
                    }
                    break;
                }
            }
        }

       print_array(right_plates);
        i = s.length()-1;
        while(i >= 0)
        {
            if(s[i] == '|')
            {
                left_plates[i] = i;
                i--;
            }
            else
            {
                while(i >= 0 && s[i] == '*')
                {
                    st.push(i);
                    i--;
                }

                while(i >=0  && !st.empty())
                {
                    left_plates[st.top()] = i;
                    st.pop();
                }
                if(i < 0)
                {
                    while(st.empty())
                    {
                        left_plates[st.top()] = -1;
                        st.pop();
                    }
                    break;
                }
                
            }
        }
        print_array(left_plates);
    }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        

        int n = s.length();
        vector<int> ans;

        vector<int> plates(n,0);
        for(int i = 0;i<n;i++)
        {
            if(s[i] == '*')
            {
                if(i == 0)
                plates[i] = 1;
                else
                plates[i]= plates[i-1] + 1;
            }
            else {
            if(i == 0)
            {
                plates[i] = 0;
            }
            else
                plates[i] = plates[i-1];
            }
        }

      //  print_array(plates);

        vector<int> left_plates(n,-1);
        vector<int> right_plates(n,n+1);

        solve(s,right_plates,left_plates);


        for(int i = 0;i<queries.size();i++)
        {
            int x = left_plates[queries[i][0]];
            int y = right_plates[queries[i][1]];

          //  cout<<x<<" "<<y<<endl;
           // cout<<plates[y]<<" "<<plates[x]<<endl;

            if(x < 0 || x > n || y < 0 || y > n)
            {
            ans.push_back(0);
            continue;
            }

            int val = (plates[y] - plates[x]) <= 0 ? 0 : (plates[y] - plates[x]);
            

            ans.push_back(val);
        }
        return ans;
    }
};