// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
        // code here
        if(n<=2)
            return n;
        vector<vector<int>> dp(n,vector<int> (n,2));
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=i;
        }
        int maxv=2;
        
        for(int j=n-2;j>0;j--)
        {
            int k=j+1;
            int i=j-1;
            while(i>=0 && k<= n-1)
            {
                if(arr[i]+arr[k]<2*arr[j])
                {
                    k++;
                }
                else if(arr[i]+arr[k]>2*arr[j])
                {
                    dp[i][j]=2;
                    i--;
                }
                else
                {
                    dp[i][j] =dp[j][k]+1;
                    maxv=max(maxv,dp[i][j]);
                    i--;
                    k++;
                }
            }
        }
        return maxv;
    }
};
/*
3
14
2 4 6 8 10 12 14 6 4 8 10 12 14 16
5
2 4 6 8 10
6
1 7 10 13 14 19
*/

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends