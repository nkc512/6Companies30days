// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        
        for(int i=0;i<9;i++)
        {
            int nums1[10]={0};
            int nums2[10]={0};
            for(int j=0;j<9;j++)
            {
                int val=mat[i][j];
                if(val!=0 && nums1[val]!=0)
                {
                    return 0;
                }
                nums1[val]=1;
                val=mat[j][i];
                if(val!=0 && nums2[val]!=0)
                {
                    return 0;
                }
                nums2[val]=1;
                
                if(i%3==0 && j%3==0)
                {
                    int nums[10]={0};
                
                    for(int k=i;k<i+3;k++)
                    {
                        for(int l=j;l<j+3;l++)
                        {
                            val=mat[k][l];
                            if(val!=0 && nums[val]!=0)
                            {
                                return 0;
                            }
                            nums[val]=1;
                        }
                    }    
                }
                
                
            }
        }
        
        return 1;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends