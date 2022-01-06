// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	
	ull getNthUglyNo(int n) {
	    if(n==1)
	    return 1;
	    vector<ull> vec(n+1,0ULL);
	    vec[0]=1;
	    vector<ull> index(3,0);
	    vector<ull> values(3,0ULL);
	    vector<ull> ugly(3);
	    ugly[0]=2ULL;
	    ugly[1]=3ULL;
	    ugly[2]=5ULL;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<3;j++)
	        {
	            values[j]=vec[index[j]]*ugly[j];
	        }
	        vec[i]=*min_element(values.begin(),values.end());
	        for(int j=0;j<3;j++)
	        {
	            if(vec[i]==values[j])
	            {
	                index[j]++;
	                
	            }
	        }
	    }
	    return vec[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends