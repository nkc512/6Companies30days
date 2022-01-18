// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void printParenthesis(int i, int j, vector<vector<int>>& bracket, char& name, string& str)
    {
        // If only one matrix left in current segment
        if (i == j)
        {
            str+=name;
            name++;
            return;
        }

        str+="(";
        // Recursively put brackets around subexpression
        // from i to bracket[i][j].
        printParenthesis(i, bracket[i][j], bracket, name,str);

        // Recursively put brackets around subexpression
        // from bracket[i][j] + 1 to j.
        printParenthesis(bracket[i][j]+1, j, bracket, name,str);
        str+=")";
    }
    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<int>> c(n,std::vector<int>(n,0));
        vector<vector<int>> m(n,std::vector<int>(n,0));

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<(n-i);j++)
            {
                int iindex=j;
                int jindex=j+i;
                int minv=INT_MAX;
                for(int k=iindex;k<jindex;k++)
                {
                    int val=c[iindex][k]+c[k+1][jindex]+p[iindex-1]*p[k]*p[jindex];
                    if(val<minv)
                    {
                        c[iindex][jindex]=val;
                        m[iindex][jindex]=k;
                        minv=val;
                    }
                }
            }
        }
        char name='A';
        string str="";
        printParenthesis(1,n-1,m,name,str);
        return str;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends