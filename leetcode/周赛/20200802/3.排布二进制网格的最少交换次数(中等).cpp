class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<int> zerocnt;
        zerocnt.resize(N);
        for(int i=0;i<N;i++)
        {
            int k = 0;
            for(int j=N-1;j>=0;j--)
            {
                if(grid[i][j] == 0)
                    k++;
                else
                    break;
            }
            zerocnt[i] = k;
        }
        int ans = 0;
        for(int i=0; i<N-1; i++)
        {
            if(zerocnt[i]>=N-i-1)
                continue;
            int j;
            for(j=i+1;j<N;j++)
            {
                if(zerocnt[j]>=N-i-1)
                {
                    break;
                }
            }
            if(j==N)
                return -1;
            while(j>i)
            {
                int temp = zerocnt[j-1];
                zerocnt[j-1] = zerocnt[j];
                zerocnt[j] = temp; 
                j--;
                ans++;
            }
        }
        return ans;
    }
};
