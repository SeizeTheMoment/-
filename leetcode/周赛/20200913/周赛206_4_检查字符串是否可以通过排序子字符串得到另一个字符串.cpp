class Solution {
public:
    bool isTransformable(string s, string t) {
        stack<int> pos[10];
        int n = s.length();
        for(int i=0;i<n;i++)
            pos[s[i]-'0'].push(i);
        for(int i=n-1;i>=0;i--)
        {
            int c = t[i] - '0';
            //如果在s中没有这个数字
            if(pos[c].empty())
                return false;
            for(int j = c+1; j<10; j++)
            {
                if(!pos[j].empty()&&pos[c].top()<pos[j].top())
                    return false;
            }
            pos[c].pop();
        }
        return true;
    }
};
