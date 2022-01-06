// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        stack<int> stk;
        string res="";
        int num=1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='D')
                stk.push(num++);
            else
            {
                char ch=num+48;
                res+=ch;
                while(!stk.empty())
                {
                    ch=stk.top()+48;
                    stk.pop();
                    res+=ch;
                }
                num++;
            }
        }
        stk.push(num);
        while(!stk.empty())
        {
            char ch=stk.top()+48;
            stk.pop();
            res+=ch;
        }
        return res;
        
        
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends