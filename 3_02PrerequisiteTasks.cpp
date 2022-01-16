// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isConnected(vector<vector<int>>& adjacent, int current, vector<int>& visit)
    {
        /*
        if(visit[current]==2)
            return true;
        */
        visit[current]=2;
        for(int i=0;i<adjacent[current].size();i++)
        {
            if(visit[adjacent[current][i]]==1)
                continue;
            if(visit[adjacent[current][i]]==2)
                return true;
            if(isConnected(adjacent, adjacent[current][i], visit))
            {
                return true;
            }
        }
        visit[current]=1;
        return false;
        
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adjacent(N);
	    int prelen=prerequisites.size();
	    for(int i=0;i<prelen;i++)
	    {
	        adjacent[prerequisites[i].first].push_back(prerequisites[i].second);
	    }
	    vector<int> visit(N,0);
	    for(int i=0;i<N;i++)
	    {
	        if(visit[i]==0)
	        {
	            if(isConnected(adjacent, i, visit))
                {
                    return false;
                }
	        }
	        
            
	    }
	    return true;
	}
};
/*

9
7
1 2
1 3
2 7
3 4
4 5
5 7
2 3
*/

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends