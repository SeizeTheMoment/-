class Solution {
public:
    int minFlips(string target) {
        int N = target.length();
        char prev = '0';
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            if(target[i]==prev)
                continue;
            else{
                ans++;
                prev = target[i];
            }
        }
        return ans;
    }
};
