class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int N = arr.size();
        int ans = 0;
        for(int i=0;i<N-1;i++)
        {
            int left = 0;
            for(int j=i+1;j<N;j++)
            {
                left = left^arr[j-1];
                int right = 0;
                for(int k=j;k<N;k++)
                {
                    right = right^arr[k];
                    if(left==right)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
