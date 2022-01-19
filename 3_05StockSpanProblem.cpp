// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int,int>> stk;
       vector<int> vec(n);
       for(int i=0;i<n;i++)
       {
           while(!stk.empty() && stk.top().first<=price[i])
           {
               stk.pop();
           }
           int val=-1;
           if(!stk.empty())
           {
               val=stk.top().second;
           }
           
           //cout<<stk.size()<<"\t"<<price[i]<<"\n";
           stk.push({price[i],i});
            vec[i]=val;
       }
       for(int i=0;i<n;i++)
       {
           vec[i]=i-vec[i];
       }
       return vec;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends