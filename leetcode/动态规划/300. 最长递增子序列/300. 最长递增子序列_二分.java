class Solution {
    public int lengthOfLIS(int[] nums) {
        int N = nums.length;
        int d[] = new int[N+1];
        int len = 1;
        d[len] = nums[0];
        for(int i = 1; i < N; i++){
            if(nums[i] > d[len]){
                d[++len] = nums[i];
            }
            else{
                //前闭后开
                int le = 1;
                int ri = len + 1;
                int pos = 0;
                //找到d[mid] < nums[i]， nums[i]替换掉d[mid] 
                while(le < ri){
                    int mid = (le + ri)/2;
                    if(d[mid] < nums[i]){
                        pos = mid;
                        le = mid + 1;
                    }
                    else{
                        ri = mid;
                    }
                }
                d[pos + 1] = nums[i];

            }
        }
        return len;
    }
}