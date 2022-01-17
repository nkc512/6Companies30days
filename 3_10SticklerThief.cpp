// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n==1)
            return arr[0];
        if(n==2)
            return max(arr[0],arr[1]);
        // Your code here
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=arr[0];
        dp[2]=arr[1];
        for(int i=3;i<=n;i++)
        {
            dp[i]=max(dp[i-2]+arr[i-1],dp[i-3]+arr[i-1]);
        }
        return max({dp[n],dp[n-1],dp[n-2]});
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends