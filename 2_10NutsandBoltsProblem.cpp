// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    static bool compare(const char &ch, const char &ch2)
    {
        int val1=9;
        int val2=9;
        if(ch=='!')
            val1=1;
        else if(ch=='#')
            val1=2;
        else if(ch=='$')
            val1=3;
        else if(ch=='%')
            val1=4;
        else if(ch=='&')
            val1=5;
        else if(ch=='*')
            val1=6;
        else if(ch=='@')
            val1=7;
        else if(ch=='^')
            val1=8;
        else
            val1=9;
        if(ch2=='!')
            val2=1;
        else if(ch2=='#')
            val2=2;
        else if(ch2=='$')
            val2=3;
        else if(ch2=='%')
            val2=4;
        else if(ch2=='&')
            val2=5;
        else if(ch2=='*')
            val2=6;
        else if(ch2=='@')
            val2=7;
        else if(ch2=='^')
            val2=8;
        else
            val2=9;    
        return val1<val2;
        
    }
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    sort(nuts,nuts+n,compare);
	    //int j=0;
	    for(int i=0;i<n;i++)
	    {
	        bolts[i]=nuts[i];
	        
	    }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends