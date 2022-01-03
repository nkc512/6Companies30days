// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long product=1;
        int count=0;
        int total=0;
        int prev=-1;
        for(int i=0;i<n;i++)
        {
            //cout<<i<<":i\t";
            product=product*a[i];
            //cout<<product<<":product\n";
            if(product<k)
            {
                count++;
                total+=(i-prev);
                //cout<<i-prev<<":i-prev1"<<i<<"\n";
                //cout<<total<<":total1 i:"<<i<<"\n";
            }
            else
            {
                prev++;
                if(prev>=n)
                    break;
                product=product/a[prev];
                while(prev<=i && product>=k)
                {
                    product=product/a[++prev];
                    //prev++;
                    //cout<<product<<":product2\n";
                    
                }
                if(prev<=i)
                {
                    //cout<<i-prev<<":i-prev2"<<i<<"\n";
                    total+=(i-prev);
                }
                //else
                //    cout<<"no add"<<i<<"\n";
                if(product<1)
                {
                    product=1;
                }
                
                //cout<<total<<":total2 i:"<<i<<"\n";
            }
            //cout<<total<<"\n";
        }
        return total;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends