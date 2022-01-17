// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	string str="1";
	vector<string> vec;
	vec.push_back(str);
	for(int i=2;i<=N;i++)
	{
	    int strlength=str.length();
	    int j=strlength-1;
	    bool change=false;
	    while(j>=0)
	    {
	        if(str[j]=='0')
	        {
	            str[j]='1';
	            int k=j+1;
	            while(k<strlength)
	            {
	                str[k]='0';
	                k++;
	            }
	            change=true;
	            break;
	        }
	        j--;
	        
	    }
	    if(!change)
	    {
	        str='1'+str;
	        int k=1;
	        while(k<=strlength)
            {
                str[k]='0';
                k++;
            }
	    }
	    vec.push_back(str);
	}
	return vec;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends