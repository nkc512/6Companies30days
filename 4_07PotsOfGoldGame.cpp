// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    int maxCoins(vector<int>&vec,int n)
    {
	    //Write your code here
	    vector<vector<int>> dp(n,vector<int>(n,0));
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0,j=k;j<n;j++,i++)
	        {
	            if(k==0)
	                dp[i][j]=vec[i];
	            else if(k==1)
	                dp[i][j]=max(vec[i],vec[j]);
	           else
	                dp[i][j]=max(
	                vec[i]+min(dp[i+1][j-1],dp[i+2][j]),
                    vec[j]+min(dp[i+1][j-1],dp[i][j-2]));
	        }
	    }
	    return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends