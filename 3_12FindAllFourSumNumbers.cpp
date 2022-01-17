// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Your code goes here
        int arrlen=arr.size();
        sort(arr.begin(),arr.end());
        set<vector<int>> res1;
        for(int i=0;i<arrlen;i++)
        {
            for(int j=i+1;j<arrlen;j++)
            {
                int k=j+1;
                int l=arrlen-1;
                int sum=arr[i]+arr[j];
                int sum1=sum;
                while(k<l)
                {
                    sum1=sum+arr[k]+arr[l];
                    if(sum1==target)
                    {
                        res1.insert({arr[i],arr[j],arr[k],arr[l]});
                    }
                    if(sum1<target)
                        k++;
                    else
                        l--;
                }
            }
        }
        vector<vector<int>> res;
        for(vector<int> vec: res1)
        {
            res.push_back(vec);
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends