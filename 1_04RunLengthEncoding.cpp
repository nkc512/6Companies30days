// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here
  string res="";
  int count=1;
  for(int i=1;i<src.length();i++)
    {
        if(src[i]==src[i-1])
            count++;
        else
        {
            res+=src[i-1];
            res+=to_string(count);
            count=1;
        }
    }
    res+=src[src.length()-1];
    res+=to_string(count);
    return res;
}     
 
