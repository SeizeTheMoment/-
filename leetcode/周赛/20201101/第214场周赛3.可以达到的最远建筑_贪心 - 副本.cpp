class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int N = heights.size();
        priority_queue<int, vector<int>, greater<int>> que;
        int sumH = 0;
        for(int i=1;i<N;i++)
        {
            int delta = heights[i] - heights[i-1];
            if(delta > 0)
                que.push(delta);
            if(que.size()>ladders)
            {
                sumH += que.top();
                que.pop();
            }
            if(sumH > bricks)
                return i-1;
        }
        return N - 1;
    }
};
