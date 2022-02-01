class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int hi=weights[0],low=weights[0],mid;
        int weightslen=weights.size();
        
        for(int i=1;i<weightslen;i++)
        {
            low=max(low,weights[i]);
            hi+=weights[i];
        }
        while(hi>low)
        {
            mid=(hi+low)/2;
            int sum=0;
            int count=0;
            for(int i=0;i<weightslen;i++)
            {
                if((sum+weights[i])>mid)
                {
                    sum=weights[i];
                    count++;
                    if(count>days)
                        break;
                }
                else
                    sum+=weights[i];
            }
            if(count<days)
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