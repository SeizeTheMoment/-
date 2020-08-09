class Solution {
public:
    string getter(int n)
    {
        if(n==1)
            return "0";
        string str = getter(n-1);
        string tmp = str;
        for(int i=0;i<tmp.length();i++)
        {
            if(tmp[i]=='0')
                tmp[i] = '1';
            else tmp[i] = '0';
        }
        reverse(tmp.begin(),tmp.end());
        return str+'1'+tmp;
    }
    char findKthBit(int n, int k) {
        string ans = getter(n);
        return ans[k-1];
    }
};
