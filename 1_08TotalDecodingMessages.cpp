// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    vector<int> dp(str.length()+1,0);
		    dp[0]=1;
		    if(str[0]=='0')
		        return 0;
		    int MAX=1000000007;
		    dp[1]=1;
		    int strlength=str.length();
		    for(int i=2;i<=str.length();i++)
		    {
		        char ch=str[i-1];
		        char ch1=str[i-2];
		        if(ch=='0' && (ch1=='0'||ch1>='3'))
		            return 0;
		        if(ch=='0' || ch1=='0'||((ch=='1'||ch=='2') && (i<strlength) && str[i]=='0'))
		        {
		            dp[i]=dp[i-1];
		        }
		        else if((ch<='6' && ch1<='2')||ch1=='1')
		        {
		            dp[i]=(dp[i-1]+dp[i-2])%MAX;
		        }
		        else
		        {
		            dp[i]=dp[i-1];
		        }
		        //cout<<dp[i]<<"\t"<<dp[i-1]<<"\n";
		    }
		    return dp[str.length()];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends