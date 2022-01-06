class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res=0;
        int previndex=0;
        int arrsize=arr.size();
        int i=0;
        while(i<(arrsize-1))
        {
            if(arr[i]==arr[i+1])
            {
                
                previndex=++i;
            }
            else if(arr[i]>arr[i+1])
            {
                int j=i+1;
                while(j<(arrsize-1) && arr[j]>arr[j+1])
                {
                    j++;
                }
                
                if(arr[previndex]>=arr[previndex+1])
                {
                    previndex=j;
                }
                res=max(res,j-previndex+1);
                i=j;
                previndex=j;
            }
            else
                i++;
        }
        if(res<3)
            res=0;
        
        return res;
    }
};
/*
[2,1,4,7,3,2,5]
[2,2,2]
[2,1,4,7,3,2,5]
[8,7,6,5,4,3,3,2,3,2,3,4,3,2,3,1,4,4,1,2,4,3,3,2,5,1]
[1,2,1]
[1,2,4,5,1]
[1,2,3,2,1]
[1,2,3,4,5]
[5,4,3,2,1]
[5]
[0]
[1,1,0,0,1,0]
*/