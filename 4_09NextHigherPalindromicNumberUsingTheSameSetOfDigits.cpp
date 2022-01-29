// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string str) { 
        //complete the function here
        
        int slen=str.length();
        int i=0;
        if(str[0]=='0')
            return "-1";
        
        int slen2=slen/2;
        bool update=false;
        bool req=false;
        int index=-1;
        if(slen%2==1)
            slen2--;
        //cout<<"original  :"<<str<<"\n";
        while((slen2-i-1)>=0){
            //cout<<str[slen2-i]<<"\t"<<str[slen2-i-1]<<"\n";
            if(str[slen2-i]>str[slen2-i-1])
            {
                index=slen2-i;
                req=true;
                break;
            }
            i++;
        }
        if(req)
        {
            
            char ch=str[index-1];
            char ch2=str[index];
            //cout<<index<<":reach1\n";
            int index2=index;
            for(int i=index+1;i<=slen2;i++)
            {
                //cout<<str[i]<<"\t"<<ch<<"\t"<<ch2<<"\n";
                if(str[i]>ch && str[i]<ch2)
                {
                    //cout<<"reachswap:"<<str[i]<<"\t"<<ch2<<"\n";
                    ch2=str[i];
                    index2=i;
                    
                    
                }
            }
            str[index2]=str[index-1];
            str[index-1]=ch2;
            if(slen%2==1)
                slen2++;
            sort(str.begin()+index,str.begin()+slen2);
            
            for(int i=index-1;i<slen2;i++)
            {
                str[slen-i-1]=str[i];
            }
            return str;
        }
        

        return "-1";
    }
};
/*
454321123454
11
35453
1
0110
67893211239876
6789321239876

*/
// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends