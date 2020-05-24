

class Solution {
public:
    static int count(vector<vector<int>>points, double x, double y, int r) {
        int ans = 0;
        for (auto point : points) {
            double dx = x - point[0];
            double dy = y - point[1];
            if (dx * dx + dy * dy <= r * r + 1e-8) {
                ans++;
            }
        }
        return ans;
    }
    int numPoints(vector<vector<int>>& points, int r) {
        int n = points.size();
        if (n == 1) {
            return 1;
        }
        int ans = count(points, points[0][0], points[0][1], r);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                double dx = points[i][0] - points[j][0];
                double dy = points[i][1] - points[j][1];
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    continue;
                }
                if(dx*dx+dy*dy>4.0*r*r)
                    continue;
                double midx = (points[i][0] + points[j][0]) / 2.0;
                double midy = (points[i][1] + points[j][1]) / 2.0;
                double dis = sqrt(dx * dx + dy * dy);
                double cosx = dx/dis;
                double sinx = dy/dis;
                double h = sqrt(r * r - dis / 2 * dis / 2);
                double rx = midx - sinx * h;
                double ry = midy + cosx * h;
                int cnt = count(points, rx, ry, r);
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
