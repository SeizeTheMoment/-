class Solution {
    /**
        f[i][j] 表s串到i位，p串到j位是否匹配
        base case f[0][0] = true f[0][j] = false
        state transfer:
            不考虑*号：f[i][j] = f[i - 1][j - 1]
            若前一个字符为*好
     */
    boolean f[][];
    char schar[];
    char pchar[];
    boolean judge(int i, int j)
    {
        if(i == 0)
            return false;
        if(schar[i - 1] == pchar[j - 1] || pchar[j - 1] == '.')
            return true;
        return false;
    }
    public boolean isMatch(String s, String p) {
        int sLength = s.length();
        int pLength = p.length();
        f = new boolean[sLength + 1][pLength + 1];
        schar = s.toCharArray();
        pchar = p.toCharArray();
        f[0][0] = true;
        //f[0][j] j为任意非0值时，都为false
        for(int i = 0; i <= sLength; i++)
        {
            for(int j = 1; j <= pLength; j++)
            {
                //第j个字符为*号时
                if(pchar[j - 1] == '*')
                {
                    //*匹配0次
                    f[i][j] |= f[i][j - 2];
                    //若第i个字符和*号前字符相匹配，则可以进行多次匹配
                    if(judge(i, j - 1)){
                        f[i][j] |= f[i - 1][j];
                    }
                } else {
                    if(judge(i, j)){
                        f[i][j] |= f[i - 1][j - 1];
                    }
                    else f[i][j] = false;
                }
            }
        }
        return f[sLength][pLength];
    }
}