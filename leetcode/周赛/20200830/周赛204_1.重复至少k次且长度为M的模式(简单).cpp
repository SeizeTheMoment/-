class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int N = arr.size();
        for(int i = 0; i + k * m <= N; i++)
        {
            bool flag = true;
            for(int j = i; j < i + k * m; j++)
            {
                if(arr[j] != arr[i + (j-i) % m]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return true;
        }
        return false;
    }
};