// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string str)
    {
        // your code here
        string str2="";
        for(int i=0; i < str.length(); i++)
        {
            // Convert to lowercase if its
            // an uppercase character
            if (str[i]>='A' && str[i]<='Z')
            {
                str[i]=str[i]+32;
     
                // Print space before it
                // if its an uppercase character
                if (i != 0)
                    str2+=' ';
     
                // Print the character
                str2+=str[i];
            }
     
            // if lowercase character
            // then just print
            else
                str2+=str[i];
        }
        return str2;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends