// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void isConnected(vector<int> adjacent[], int current, vector<int>& visit,int c,int d)
    {
        if(visit[current]==1 || visit[current]==2)
            return;
        
        visit[current]=2;
        for(int i=0;i<adjacent[current].size();i++)
        {
            if((current==c && adjacent[current][i]==d)|| (current==d && adjacent[current][i]==c))
                continue;
            if(visit[adjacent[current][i]]==1 || visit[adjacent[current][i]]==2)
                continue;
            isConnected(adjacent, adjacent[current][i], visit,c,d);
        }
        visit[current]=1;
        
    }
	
    int isBridge(int V, vector<int> adjacent[], int c, int d) 
    {
        // Code here
        if(c>d)
        {
            int temp=c;
            c=d;
            d=temp;
        }
        vector<int> visit(V,0);
        
        isConnected(adjacent, c, visit,1000000,1000000);
        
        for(int i=0;i<V;i++)
        {
            //cout<<i<<"\t"<<visit[i]<<"\n";
            if(visit[i]==0)
            {
                visit[i]=1;
                //cout<<i<<":found\n";
            }
            else
            {
                visit[i]=0;
            }
            
        }
        isConnected(adjacent, c, visit,c,d);
        for(int i=0;i<V;i++)
        {
            //cout<<i<<"\t"<<visit[i]<<"\n";
            if(visit[i]==0)
            {
                return 1;
            }
            
        }
        return 0;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends