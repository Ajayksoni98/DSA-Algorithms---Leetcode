class Solution {
public:
bool check(string s)
{
    bool flag = false;
    if(s[s.length()-1] == '1')flag = true;

    bool flag2 = true;
    for(int i = s.length()-2;i>=0;i--)
    {
        if(s[i] != '0'){flag2 = false;break;}
    }
    return flag & flag2;
}
    int numSteps(string s) {

        int n = s.length();
        int count = 0;

        while(!check(s))
        {
            if(s[s.length() -1 ] == '0')
            {
                s = s.substr(0,s.length()-1);
                count++;
            }
            else
            {
                for(int i = s.length()-1;i>=0;i--)
                {
                    //cout<<i<<" ";
                    if(s[i] == '1')
                    {

                        if(i !=  0)
                        s[i] = '0';
                        else
                        {
                            s[i] = '0';
                            s = '1' + s;
                        }
                    }
                    else
                    {
                        s[i] = '1';
                        break;
                    }
                }
                count++;
            }
            cout<<endl<<count<<" "<<s;

        }
        return count;
    }
};