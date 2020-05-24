struct Point {
	double x, y;
	Point() {}
	Point(double tx, double ty) { x = tx; y = ty; }
};
const double eps = 1e-10;
class Solution {
public:
    double dist(Point p1,Point p2) {
	    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }

    Point GetCircleCenter(Point p1, Point p2, double r) {
	    Point mid = Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	    double angle = atan2(p1.x - p2.x, p2.y - p1.y);
	    double d = sqrt(r*r - pow(dist(p1, mid), 2));
	    return Point(mid.x + d*cos(angle), mid.y + d*sin(angle));
    }
    
    int numPoints(vector<vector<int>>& points, int r) {
        int ans = 1;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                if(dist(Point(1.0 * points[i][0], 1.0 * points[i][1]), 
                        Point(1.0 * points[j][0], 1.0 * points[j][1])) > 2.0*r)
                    continue;
                Point center = GetCircleCenter(
                               Point(1.0 * points[i][0], 1.0 * points[i][1]), 
                               Point(1.0 * points[j][0], 1.0 * points[j][1]), 
                               1.0 * r
                               );
                int cnt = 0;
				for(int k = 0; k < points.size(); ++k)
                    if(dist(center, Point(1.0 * points[k][0], 1.0 * points[k][1])) 
                       < 1.0*r + eps) 
                        cnt++;
				ans = max(ans,cnt);
            } 
        }
        return ans;
    }
};

作者：dqsjysgs
链接：https://leetcode-cn.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/solution/bao-li-mei-ju-by-dqsjysgs/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
