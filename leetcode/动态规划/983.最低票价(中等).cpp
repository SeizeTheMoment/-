class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int duration[3] = {1, 7, 30};
        vector<int> dp;
        int lastday = days[days.size()-1];
        int firstday = days[0];
        dp.resize(lastday+1);
        fill(dp.begin(),dp.end(),0x3f3f3f3f);
        fill(dp.begin(),dp.begin()+firstday,0);
        for(int i=0;i<3;i++)
            dp[firstday] = min(dp[firstday],costs[i]);
        for(int i=1;i<days.size();i++)
        {
            int nowday = days[i];
            for(int day=days[i-1]+1;day<nowday;day++)
                dp[day] = dp[days[i-1]];
            for(int j=0;j<costs.size();j++)
            {
                if(nowday-duration[j]>=1)
                    dp[nowday] = min(dp[nowday],dp[nowday-duration[j]]+costs[j]);
                else dp[nowday] = min(dp[nowday],dp[0]+costs[j]);
            }
        }
        return dp[lastday];
    }
};