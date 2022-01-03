class Solution {
public:
    int minSubArrayLen(long target, vector<int>& nums) {
        int start=-1;
        long total=0;
        int n=nums.size();
        int mincount=n+1;
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
            if(total<target)
            {
                continue;
            }
            if(total==target)
            {
                mincount=min(mincount,i-start);
                continue;
            }
            mincount=min(mincount,i-start);
            while(start<i && total>target)
            {
                
                total=total-nums[++start];  
                if(total>=target)
                    mincount=min(mincount,i-start);
            }
            
        }
        
        return mincount>n?0:mincount;
    }
};
/*
7
[2,3,1,2,4,3]
4
[1,4,4]
11
[1,1,1,1,1,1,1,1]
8
[1,1,1,1,1,1,1,1]
7
[1,1,1,1,1,1,1,1]
1
[1]
1
[5]
*/