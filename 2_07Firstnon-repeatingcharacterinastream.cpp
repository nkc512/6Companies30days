// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
		    // Code here
		    vector<int> visit(26,0);
		    queue<char> q;
		    string res="";
		    for(int i=0;i<str.length();i++)
		    {
		        if(visit[str[i]-97]==0)
		        {
		            q.push(str[i]);
		        }
		        visit[str[i]-97]+=1;
		        while(!q.empty() && visit[q.front()-97]>1)
	                q.pop();
	            if(q.empty())
	            {
	                res+="#";
	            }
	            else
	                res+=q.front();
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends