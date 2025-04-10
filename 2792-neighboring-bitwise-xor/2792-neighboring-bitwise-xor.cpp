class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        bool xor_ = false;
        for(auto x : derived)
        {
            xor_ = xor_ ^ x;
        }

        return xor_ == 1? 0:1;
        
    }
};