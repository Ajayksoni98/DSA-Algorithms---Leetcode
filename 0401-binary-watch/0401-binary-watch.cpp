class Solution {
public:

unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
    int is_pos(int hour, int min, int turnedOn) {
        
        if(hour ==0 && min == 0 && turnedOn > 0)return false;
        turnedOn -= countSetBits(hour);
        turnedOn -= countSetBits(min);

        cout<<hour<<" "<<min<<" "<<countSetBits(hour)<<" "<<countSetBits(min)<<" "<<turnedOn<<endl;
        return turnedOn != 0 ? 0 : 1;
    }
    vector<string> readBinaryWatch(int turnedOn) {

        if (turnedOn >= 9)
            return vector<string>();

        string cur = "";
        vector<string> res;

        for (int i = 0; i <= 11; i++) {
            for (int j = 0; j <= 59; j++) {
                if (is_pos(i, j, turnedOn)) {

                    string cur = "";

                        cur += to_string(i);
                    

                    cur += ":";

                    if (j >= 0 && j <= 9) {
                        cur += '0';
                        cur += to_string(j);
                    } else {
                        cur += to_string(j);
                    }
                    res.push_back(cur);
                }
            }
        }

        return res;
    }
};