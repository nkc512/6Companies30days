// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int mod(int x)
    {
        if(x<0)
            return -x;
        return x;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    int max1=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        max1=max(max1,arr[i]);
	    }
	    int half=sum/2;
	    if(max1>half)
	    {
	        return mod(sum-max1*2);
	    }
	    sort(arr,arr+n);
	    vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1,false));
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum/2;j++)
	        {
	            if(j==0)
	                dp[i][j]=true;
	            else if(i==0)
	                dp[i][j]=false;
	            else if(arr[i-1]>j)
	                dp[i][j]=dp[i-1][j];
	            else
	                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
	        }
	    }
	    max1=0;
	    for(int i=0;i<=sum/2;i++)
	    {
	        if(dp[n][i])
	            max1=i;
	    }
	    return mod(sum-2*max1);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends