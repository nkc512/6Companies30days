class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=piles[0],low=1,mid,count,sum;
        int pilelen=piles.size();
        for(int i=1;i<pilelen;i++)
        {
            high=max(high,piles[i]);
        }
        while(high>low)
        {
            mid=(low+high)/2;
            count=0;
            for(int i=0;i<pilelen;i++)
            {
                count+=piles[i]/mid;
                if(piles[i]%mid>0)
                {
                    count+=1;
                }
                if(count>h)
                    break;
                
            }
            if(count<=h)
            {
                high=mid;
            }
            else
                low=mid+1;
        }
        return high;
    }
};