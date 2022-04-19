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
    map<int,int> mp;
    int len;
    int getElement(MountainArray &mountainArr, int index)
    {
        if(mp.find(index)==mp.end())
        {
            mp[index]=mountainArr.get(index);
        }
        return mp[index];
    }
    int findMid(MountainArray &mountainArr, int length)
    {
        int start=0;
        int end=length;
        while(start<end)
        {
            int mid=(start+end)/2;
            if((mid+1)>=length)
                return mid;
            if(getElement(mountainArr, mid)<getElement(mountainArr, mid+1))
            {
                start=mid+1;
            }
            else
                end=mid;
        }
        return start;
    }
    int binary_search(int target, MountainArray &mountainArr, int start, int end, int ascend)
    {
        while(start<end)
        {
            int mid=(start+end)/2;
            if(getElement(mountainArr, mid)==target)
            {
                return mid;
            }
            if(ascend)
            {
                if(getElement(mountainArr, mid)<target)
                {
                    start=mid+1;
                }
                else
                    end=mid-1;
            }
            if(!ascend)
            {
                if(getElement(mountainArr, mid)<target)
                {
                    end=mid-1;
                }
                else
                    start=mid+1;
            }
        }
        return start;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len=mountainArr.length();
        this->len=len;
        int mid=findMid(mountainArr, len-1);
        int res=binary_search(target,mountainArr, 0, mid, true);
        if(getElement(mountainArr, res)==target)
            return res;
        res=binary_search(target,mountainArr, mid+1, len-1, false);
        if(getElement(mountainArr, res)==target)
            return res;
        return -1;
    }
};
/*
[1,2,3,5,3]
0
[1,2,3,4,5,3,1]
3
[0,1,2,4,2,1]
3
[1,2,3,4,5,3,1]
1
[0,1,2,4,2,1]
1
[1,2,3,4,5,3,1]
2
[0,1,2,4,2,1]
2
[1,2,3,4,5,3,1]
4
[0,1,2,4,2,1]
4
[1,2,3,4,5,3,1]
5
[0,1,2,4,2,1]
5
[1,5,2]
2
[1,5,2]
1
[1,5,2]
5
[1,5,2]
3
[1,5,2]
5
[1,23,2]
2
[1,23,2]
23
[1,23,2]
1
[1,23,2]
1
[1,23,24,2]
24
[1,23,24,2]
23
[1,25,24,2]
25
[1,25,24,2]
24
[1,25,24,2]
2

*/