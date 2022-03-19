// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}


 // } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        
        int a=INT_MAX, b=INT_MAX;
        int a_new=INT_MAX;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<a)
            {
                if(b==INT_MAX)
                    a=arr[i];
                else
                    a_new=arr[i];
            }
                
            else if(arr[i]<b && (arr[i]>a || arr[i]>a_new))
            {
                if(a_new!=INT_MAX)
                {
                    a=a_new;
                    a_new=INT_MAX;
                }
                b=arr[i];
                
            }
            else if(arr[i]>b)
            {
                //cout<<a<<"\t"<<b<<"\t"<<arr[i];
                return {a,b,arr[i]};
            
            }
            //cout<<a<<"\t"<<b<<"\n";
        }
        
        return {};
    }
};
/*
5
4 7 2 5 8
5
1 2 1 1 3
3
1 1 3
5
4 7 1 2 6
23
48 43 60 2 93 93 30 100 26 47 25 2 49 34 42 58 47 16 73 16 11 6 91
*/

// { Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}  // } Driver Code Ends