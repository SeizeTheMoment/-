class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i = 0;
        int wins = 0;
        int N = arr.size();
        while(wins<k&&i<N)
        {
            if(arr[i]>arr[i+1])
            {
                wins++;
                arr[i+1] = arr[i];
            }
            else wins = 1;
            i++;
        }
        return arr[i];
    }
};
