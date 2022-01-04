// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int i=0;
        int temp;
        int repeat=-1;
        int *arr2=new int[2];
        int j=0;
        while(i<n)
        {
            if(arr[i]!=arr[arr[i]-1] && arr[i]!=(i+1))
            {
                temp=arr[arr[i]-1];
                arr[arr[i]-1]=arr[i];
                arr[i]=temp;
            }
            else
                i++;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=(i+1))
            {
                arr2[0]=arr[i];
                arr2[1]=i+1;
                return arr2;
            }
        }
        return arr2;
    }
    /*
2
2 2
3
1 3 3
8
1 7 2 8 3 4 3 6
    */
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends