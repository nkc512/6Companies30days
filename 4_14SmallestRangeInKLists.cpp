// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
typedef pair<int,int> pr;
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          vector<int> indices(k,0);
          priority_queue<pr,vector<pr>, greater<pr>> pq;
          
          int maxv=KSortedArray[0][0];
          for(int i=0;i<k;i++)
          {
              pq.push({KSortedArray[i][0],i});
              maxv=max(maxv,KSortedArray[i][0]);
          }
          int j=k;
          pr res={pq.top().first,maxv};
          int range=maxv-pq.top().first;
          
          while(!pq.empty() || range!=0)
          {
            pr pi=pq.top();
            pq.pop();
            int col=indices[pi.second];
            int row=pi.second;
            //cout<<vec[0]<<"\t"<<vec[1]<<"\t"<<vec[2]<<":vec\n";
            if((maxv-pi.first)<range)
            {
                range=maxv-pi.first;
                res={pi.first,maxv};
                
            }
            col=col+1;
            indices[pi.second]++;
            if(col==n)
                break;
            maxv=max(maxv,KSortedArray[row][col]);
            
            pq.push({KSortedArray[row][col],row});
            
          }
          return res;
    }
};
/*
4 3
1 2 7 9
5 6 8 10
4 5 7 12
4 3
1 10 10 11
5 10 10 12
4 5 9 12
*/

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends