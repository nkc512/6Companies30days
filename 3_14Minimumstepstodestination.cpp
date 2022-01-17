// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D){
        // code here
        int num=0;
        int count=0;
        int i=1;
        while(num<D)
        {
            num+=i;
            count++;
            i++;
        }
        if((num-D)&1==0)
            return count;
        while((num-D)&1!=0)
        {
            num+=i;
            count++;
            i++;
        }
        return count;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends