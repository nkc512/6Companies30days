// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
#define MOD 1000000007
class Solution{
    public:
    long long count=0;
    /* // TLE
    void combinations(vector<int>& vec, int index,int len, long long currsum, long long target)
    {
        //cout<<currsum<<":currsum\t"<<index<<":index\n";  
        //cout<<index<<"\t"<<vec[index]<<"\n"; 
        if(currsum==target)
        {
            count++;
            count=count%MOD;
            return;
        }
        if((currsum+vec[index])%MOD>target)
            return;
        //cout<<index<<"\t";
        if(index<=(len-1))
        {
            combinations(vec, index+1,len, currsum, target);
            combinations(vec, index+1,len, (currsum+vec[index])%MOD, target);               
        }
    }*/
    int power(int num,int x)
    {
        int ans=num;
        for(int i=0;i<(x-1);i++)
        {
            ans=(ans*num)%MOD;
        }
        return ans;
    }
    int numOfWays(int n, int x)
    {

        vector<int> vec(1,0);
        int i=1;
        while(i<=n)
        {
            int num=power(i,x);
            if(num<=n)
                vec.push_back(num);
            else
                break;
            i++;
        }
        int len=vec.size();
        int arr[len+1][n+1]={0};
        for(int i=0;i<=len;i++)
        {
            arr[i][0]=1;
        }
        for(int i=0;i<=len;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0)
                    arr[i][j]=1;
                else if(i==0)
                    arr[i][j]=0;
                else
                {
                    arr[i][j]=arr[i-1][j];
                    if(j>=vec[i-1])
                        arr[i][j]=(arr[i][j]+arr[i-1][j-vec[i-1]])%MOD;
                }
            }
        }
        return arr[len][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends