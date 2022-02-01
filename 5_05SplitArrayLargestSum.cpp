class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int hi=nums[0],low=nums[0],mid;
        int numslen=nums.size();
        
        for(int i=1;i<numslen;i++)
        {
            low=max(low,nums[i]);
            hi+=nums[i];
        }
        while(hi>low)
        {
            mid=(hi+low)/2;
            int sum=0;
            int count=0;
            for(int i=0;i<numslen;i++)
            {
                if((sum+nums[i])>mid)
                {
                    sum=nums[i];
                    count++;
                    if(count>m)
                        break;
                }
                else
                    sum+=nums[i];
            }
            if(count<m)
            {
                hi=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
        
    }
};