// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> res;
    void parenthesis(string str, int n, int left, int right,int cost)
    {
        int strlength=left+right;
        if(strlength==n*2)
        {
            res.push_back(str);
            return;
        }
        if(left<n)
            parenthesis(str+'(', n, left+1, right,cost+1);
        if(right<n && cost>0)
            parenthesis(str+')', n, left, right+1,cost-1);
        
    }
    vector<string> AllParenthesis(int n) 
    {
        parenthesis("", n, 0,0,0);
        return res;
        // Your code goes here 
    }
};

// { Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n); 
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<"\n";
    }
    return 0; 
} 
  // } Driver Code Ends