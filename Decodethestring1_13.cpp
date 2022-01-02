// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<pair<int,int>> stk;
        int i=0;
        int num=0;
        while(i<s.length())
        {
            if(s[i]>=48 and s[i]<=57)
            {
                num=num*10+s[i]-48;
            }
            else if(s[i]=='[')
            {
                stk.push(make_pair(num,i));
                num=0;
            }
            else if(s[i]==']')
            {
                //cout<<i<<":i s.length()-i:"<<s.length()-i<<"\n";
                int remain=s.length()-i;
                pair<int,int> pr=stk.top();
                stk.pop();
                string multiply="";
                string ref=s.substr(pr.second+1,i-pr.second-1);
                //cout<<ref<<":ref\n";
                for(int j=0;j<pr.first;j++)
                {
                    multiply=multiply+ref;
                }
                int numlen=to_string(pr.first).length();
                s=s.substr(0,pr.second-numlen)+multiply+s.substr(i+1);
                i=s.length()-remain;
                //i=remain;
                //cout<<i<<":i s.length()-i:"<<s.length()-i<<"\n";
            }
            //cout<<s<<":s\n";
            i++;
        }
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends