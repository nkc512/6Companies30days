// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int lis(vector<int> vec)
    {
        int len=vec.size();
        if(len<=1)
            return len;
        vector<int> v;
        v.push_back(vec[0]);
        int j=0;
        for(int i=0;i<len;i++)
        {
            if(vec[i]>v[j])
            {
                v.push_back(vec[i]);
                j++;
            }
            else
            {
                int index=lower_bound(v.begin(),v.end(),vec[i])-v.begin();
                v[index]=vec[i];
            }
        }
        return v.size();
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int> v;
        for(int i=0;i<N;i++)
        {
            if(binary_search(B,B+M,A[i]))
                v.push_back(A[i]);
        }
        return M+N-2*lis(v);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends