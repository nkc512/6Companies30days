// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    int winner(string num1,string num2)
    {
        std::vector<int> v1(1,0);
        std::vector<int> v2(1,0);
        int val1=0;
        int j=0;
        for(int i=0;i<num1.length();i++)
        {
            if(num1[i]!='.')
                v1[j]=v1[j]*10+num1[i]-48;
            else
            {
                j++;
                v1.push_back(0);
            }

        }
        j=0;
        for(int i=0;i<num2.length();i++)
        {
            if(num1[i]!='.')
                v2[j]=v2[j]*10+num2[i]-48;
            else
            {
                j++;
                v2.push_back(0);
            }
        }
        j=0;
        while(j<v1.size() && j<v2.size())
        {
            if(v1[j]>v2[j])
                return 1;
            else if(v2[j]>v1[j])
                return 2;
            j++;
        }
        if(j<v1.size())
            return 1;
        return 2;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        string num1,num2;
        getline(cin >> ws,num1);
        getline(cin,num2);
        Solution obj;
        int result = obj.winner(num1,num2);
        cout<<"Input:"<<num1<<"\t"<<num2<<"\n";
        if(result==1)
            cout<<num1<<"\n";
        else
            cout<<num2<<"\n";
    }
    return 0;
}
  // } Driver Code Ends