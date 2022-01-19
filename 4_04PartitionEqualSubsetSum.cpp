// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if((sum&1)==1)
            return 0;
        sort(arr,arr+N);
        vector<vector<bool>> vec(N+1,vector<bool>(sum/2+1,false));
        
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=sum/2;j++)
            {
                if(j==0)
                    vec[i][j]=true;
                else if(i==0)
                    vec[i][j]=false;
                else if(arr[i-1]>j)
                    vec[i][j]=vec[i-1][j];
                else
                    vec[i][j]=vec[i-1][j] || vec[i-1][j-arr[i-1]];
                //cout<<vec[i][j]<<"\t";
            }
            //cout<<"\n";
        }
        if(vec[N][sum/2])
            return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends