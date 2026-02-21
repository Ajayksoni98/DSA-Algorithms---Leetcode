class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.size();
        int open = 0;
        int close = count(customers.begin(),customers.end(),'Y');

        int total_penalty = close;
       

        int min_hour = 0;
        int min_penalty = total_penalty;
        for(int i = 0;i<n;i++)
        {
            if(customers[i] == 'Y')
            {
                total_penalty-=1;

                
            }
            else
            {
                total_penalty++;
            }


                if(min_penalty > total_penalty)
                {
                    min_penalty = total_penalty;
                    min_hour = i+1;
                }
        }
        

        return min_hour;
    }
};