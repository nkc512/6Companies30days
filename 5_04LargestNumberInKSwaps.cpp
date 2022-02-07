// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    string maxv;
    void permutation(string& str, int index,int end,int k, string& prev)
    {
        
        if(k<=0)
            return;
        string temp=str;
        char chstart=str[index];
        char ch=str[index];
        bool chg=false;
        for(int i=end-1;i>index;i--)
        {
            if(str[index]<str[i] && str[i]>=ch && str[i]!=chstart)
            {
                chg=true;
                ch=str[i];
                swap(str[index],str[i]);
                if(str>maxv)
                {
                    maxv=str;    
                }
                //cout<<k<<"\t"<<temp<<"\t"<<str<<"\n";
                permutation(str, index+1,end,k-1,temp);
                swap(str[index],str[i]);

                //ch=str[i]; 
            }
        }
        if(!chg && index<end)
        {
            permutation(str, index+1,end,k,temp);
        }
        
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        //cout<<str<<":found\n";
        maxv=str;
        permutation(str, 0,str.length(),k, str);
        return maxv;
       // code here.
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends