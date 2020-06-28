class Solution {
public:
    //yi+yj+|xi-xj| = xj + yj + yi - xi; (i<j)
    //即对于每一个xj+yj找到最大的yi-xi即可
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> que;
        int res = INT_MIN, j = 1;
        for(int i = 0; i < points.size(); i ++){
            while(j < points.size() && points[j][0] - points[i][0] <= k){
                //压入{xj+yj, xj}
                que.push(make_pair(points[j][0]+points[j][1],points[j][0]));
                j ++;
            }
            while(!que.empty()){
                //如果xj<=xi
                if(que.top().second <= points[i][0])
                    que.pop();
                else{
                    //res = max(res, yi-xi+yj+xj)
                    res = max(res, points[i][1] - points[i][0] + que.top().first);
                    break;
                }
            }
        }
        return res;
    }
};
