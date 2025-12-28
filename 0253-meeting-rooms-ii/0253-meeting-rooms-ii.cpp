class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& interval) {

        int n = interval.size();

        sort(interval.begin(),interval.end());

        priority_queue<int,vector<int>,greater<int>> busy;

    
      busy.push(interval[0][1]);

        
        for (int i = 1; i < interval.size(); i++) {

            if (busy.top() <= interval[i][0]) {
                busy.pop();
                busy.push(interval[i][1]);
            } else {
                busy.push(interval[i][1]);
            }            
        }

        return busy.size();


       
        
    }
};