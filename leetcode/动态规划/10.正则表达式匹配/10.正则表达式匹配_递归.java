class Solution {
    //非*时，则继续后移
    // 遇到*时，i,j
    // p[j + 1] == "*"时 有两种情况
    // 1.当s[i] == p[j]， 则有
    // 1.1 *号匹配0次
    // 1.2 *号匹配n次
    // 2.当s[i] != p[j]，则只有 
    // *匹配0次  *匹配0次则i不动，j向后移2个单位
    // basecase：i == s.length   判断 后面的是否.*成对出现，若是则true，若否则false
    //           j == p.length   判断 i == s.length
    char s[];
    char p[];
    boolean dp(int i, int j) {
        if(i == s.length) {
            int pLength = p.length;
            if((pLength - j) % 2 == 0) {
                while(j < pLength) {
                    if(p[j + 1] ==  '*')
                        j += 2;
                    else return false;
                }
                return true;
            } else {
                return false;
            }
        }
        if(j == p.length) {
            return i == s.length;
        }
        if(s[i] == p[j] || p[j] == '.')
        {
            if(j + 1 < p.length && p[j + 1] == '*')
            {
                return dp(i, j + 2) || dp(i + 1, j);
            } else {
                return dp(i + 1, j + 1);
            }
        } 
        else {
            if(j + 1 < p.length && p[j + 1] == '*')
            {
                return dp(i, j + 2);
            } else {
                return false;
            }
        }
    }
    public boolean isMatch(String s, String p) {
        this.s = s.toCharArray();
        this.p = p.toCharArray();
        return dp(0, 0);
    }
}