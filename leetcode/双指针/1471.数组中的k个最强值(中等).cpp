class Solution {
public:
    
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int N = arr.size();
        int mid = arr[(N-1)/2];
        vector<int> ans;
        ans.resize(k);
        int ind = 0;
        int le = 0;
        int ri = arr.size()-1;
        for(int i = 0; i < k; i++)
        {
            if(mid-arr[le]>arr[ri]-mid)
            {
                ans[ind++] = arr[le++];
            }
            else{
                ans[ind++] = arr[ri--];
            }
        }
        return ans;
    }
};