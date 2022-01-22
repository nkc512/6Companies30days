// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string,int> mp;
        string res=arr[0];
        int maxc=1;
        mp[arr[0]]=1;
        for(int i=1;i<n;i++)
        {
            if(mp.find(arr[i])==mp.end())
            {
                mp[arr[i]]=1;
            }
            else
            {
                mp[arr[i]]+=1;
                
            }
            if(mp[arr[i]]>maxc)
            {
                maxc=mp[arr[i]];
                res=arr[i];
            }
            else if(mp[arr[i]]==maxc && arr[i].compare(res)<0)
            {
                //cout<<"res:"<<res<<"\n";
                res=arr[i];
            }
        }
        
        return {res,to_string(maxc)};
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends