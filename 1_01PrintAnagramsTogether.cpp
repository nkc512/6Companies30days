// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> res;
        vector<string> vec;
        for(int i=0;i<string_list.size();i++)
        {
            string str=string_list[i];
            sort(str.begin(),str.end());
            auto it=find(vec.begin(),vec.end(),str);
            if(it!=vec.end())
            {
                int index=it-vec.begin();
                res[index].push_back(string_list[i]);
            }
            else
            {
                vec.push_back(str);
                res.push_back({string_list[i]});
            }
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
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends