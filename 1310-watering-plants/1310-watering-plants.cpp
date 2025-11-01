class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {

        int n = plants.size();
        int cur_cap = capacity;
        int total = 0;


        for(int i = 0;i<n;i++)
        {
            if(cur_cap >= plants[i])
            {
                total++;
                cur_cap -= plants[i];
            }
            else
            {
                cur_cap = capacity;
                cur_cap -= plants[i];
                total +=  (i)*2+1;
            }
        }

        return total;
        
    }
};