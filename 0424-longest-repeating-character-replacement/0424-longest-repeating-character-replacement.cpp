class Solution {
public:
    int solve(string& s, int k, char c) {
        int n = s.size();

        int i = 0;
        int j = 0;

        int len = 0;

        while (j < n) {
            if (s[j] == c) {
                j++;
            } else if (s[j] != c && k > 0) {
                k--;
                j++;
            } else {
                len = max(len, j - i);

                if (s[i] != c) {
                    k++;
                    i++;
                } else {
                    i++;
                }
            }
        }

        if(k==0 || j == n)
        {
            len = max(len,j-i);
        }

        return len;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();

        

        int max_len = INT_MIN;

        for (int i = 0; i < 26; i++) {
            cout<<solve(s,k,'A'+ i)<<endl;
            max_len = max(max_len, solve(s, k, 'A' + i));
        }
        return max_len;
    }
};