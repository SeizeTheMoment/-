const double PI = 3.1415926;
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int ans = 0;
        vector<double> angles;
        int x = location[0];
        int y = location[1];
        for(auto point : points)
        {
            int dx = point[0] - x;
            int dy = point[1] - y;
            if(dx==0&&dy==0)
                ans++;
            else
                angles.emplace_back(atan2(dy,dx));
        }
        sort(angles.begin(),angles.end());
        int n = angles.size();
        for(int i=0;i<n;i++)
            angles.emplace_back(angles[i]+2*PI);
        //int add = 0;
        int res = 0;
        double angg = angle*PI/180;
        for(int i=0,j=0;i<angles.size();i++)
        {
            while(j<angles.size()&&(fabs(angles[j]-angles[i]-angg)<1e-8||angles[j]-angles[i]<angg))
                j++;
            res = max(j-i+ans,res);
        }
        return res;

    }
};
