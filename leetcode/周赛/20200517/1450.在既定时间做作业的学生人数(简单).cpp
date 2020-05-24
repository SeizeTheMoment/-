class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int N = startTime.size();
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            if(queryTime>=startTime[i]&&queryTime<=endTime[i])
                ans++;
        }
        return ans;
    }
};
