class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int,int> m1;
        for(int i=0;i<arr.size();i++)
        {
            m1[arr[i]] = i+1;
        }
        for(auto piece : pieces)
        {
            int num = piece[0];
            int prev = m1[num];
            if(!prev)
                return false;
            for(int i=1;i<piece.size();i++)
            {
                num = piece[i];
                if(!m1[num]||m1[num]!=prev+1)
                    return false;
                prev = m1[num];
            }
        }
        return true;
    }
};
