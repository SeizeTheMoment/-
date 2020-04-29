/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int N = mountainArr.length();
        int le = 1;
        int ri = N-1;
        int mid = (le+ri)/2;
        int maxind = 0;
        while(le<ri)
        {
            mid = (le+ri)/2;
            int curval = mountainArr.get(mid);
            int leval = mountainArr.get(mid-1);
            int rival = mountainArr.get(mid+1);
            if(curval>=rival&&curval>=leval)
            {
                maxind = mid;
                break;
            }
            if(curval>=leval&&curval<=rival)
            {
                le = mid+1;
            }
            else if(curval<=leval&&curval>=rival)
            {
                ri = mid;
            }
        }
        le = 0;
        ri = maxind;
        int lepos = -1;
        int ripos = -1;
        while(le<ri)
        {
            mid = (le+ri)/2;
            if(mountainArr.get(mid)==target)
            {
                lepos = mid;
                break;
            }
            if(mountainArr.get(mid)<target)
            {
                le = mid+1;
            }
            else ri = mid;
        }
        if(lepos>=0)
        {
            return lepos;
        }
        le = maxind;
        ri = N;
        while(le<ri)
        {
            mid = (le+ri)/2;
            if(mountainArr.get(mid)==target)
            {
                ripos = mid;
                break;
            }
            if(mountainArr.get(mid)<target)
            {
                ri = mid;
            }
            else le = mid+1;
        }
        return ripos;
    }
};