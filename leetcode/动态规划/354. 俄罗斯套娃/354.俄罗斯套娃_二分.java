class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        int N = envelopes.length;
        int d[][] = new int[N + 1][2];
        int len = 1;
        Arrays.sort(envelopes, (int[] o1, int[] o2) -> {
             if(o1[0] == o2[0])
                 return o2[1] - o1[1];
             return o1[0] - o2[0];
         });
        d[len] = envelopes[0];
        //递增
        //找位置的思想
        for(int i = 1;  i < N; i++)
        {
            if(d[len][1] < envelopes[i][1])
            {
                d[++len] = envelopes[i];
            }
            else {
                int le = 1;
                int ri = len + 1;
                //左闭右开 找位置
                int mid = (le + ri) / 2;
                int pos = 0;
                while(le < ri)
                {
                    mid = (le + ri) / 2;
                    //符合条件 则向右再找
                    if(d[mid][1] < envelopes[i][1])
                    {
                        pos = mid;
                        le = mid + 1;
                    }
                    else {
                        ri = mid;
                    }
                }
                d[pos + 1] = envelopes[i]; 
            }
        }
        return len;

    }
}