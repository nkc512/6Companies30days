// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string s="";
        while(n)
        {
            int temp=n%26;
            //cout<<n<<":n\t"<<temp<<"\n";
            if(temp==0)
            {
                temp=26;
                n=n-1;
            }
            char ch=temp+64;
            s=ch+s;
            n=n/26;
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long int n; cin >> n;
        Solution ob;
        cout << ob.colName (n) << '\n';
    }
}
  // } Driver Code Ends