// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int num=0;
        bool neg=false;
        int i=0;
        if(str[0]=='-')
        {
            i++;
            neg=true;
            if(str.length()==1)
                return -1;
        }
        for(;i<str.length();i++)
        {
            if(str[i]<48||str[i]>57)
                return -1;
            num=num*10+str[i]-48;
        }
        if(neg)
            return -num;
        return num;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends