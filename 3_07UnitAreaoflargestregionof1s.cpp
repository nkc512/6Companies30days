// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int getCount(int i, int j, int m, int n,vector<vector<int>>& grid)
    {
        stack<pair<int,int>> stk;
        int count=1;
        stk.push(make_pair(i,j));
        grid[i][j]=2;
        while(!stk.empty())
        {
            pair<int,int> pr=stk.top();
            stk.pop();
            if((pr.first-1)>=0)
            {
                
                if(grid[pr.first-1][pr.second]==1)
                {
                    count++;
                    grid[pr.first-1][pr.second]=2;
                    stk.push(make_pair(pr.first-1,pr.second));
                }
                
                if((pr.second-1)>=0 && grid[pr.first-1][pr.second-1]==1)
                {
                    count++;
                    grid[pr.first-1][pr.second-1]=2;
                    stk.push(make_pair(pr.first-1,pr.second-1));
                }
                if((pr.second+1)<n && grid[pr.first-1][pr.second+1]==1)
                {
                    count++;
                    grid[pr.first-1][pr.second+1]=2;
                    stk.push(make_pair(pr.first-1,pr.second+1));
                }
            }
            if((pr.first+1)<m)
            {
                if(grid[pr.first+1][pr.second]==1)
                {
                    count++;
                    grid[pr.first+1][pr.second]=2;
                    stk.push(make_pair(pr.first+1,pr.second));
                }
                
                if((pr.second-1)>=0 && grid[pr.first+1][pr.second-1]==1)
                {
                    count++;
                    grid[pr.first+1][pr.second-1]=2;
                    stk.push(make_pair(pr.first+1,pr.second-1));
                }
                if((pr.second+1)<n && grid[pr.first+1][pr.second+1]==1)
                {
                    count++;
                    grid[pr.first+1][pr.second+1]=2;
                    stk.push(make_pair(pr.first+1,pr.second+1));
                }
            }
            if((pr.second-1)>=0 && grid[pr.first][pr.second-1]==1)
            {
                count++;
                grid[pr.first][pr.second-1]=2;
                stk.push(make_pair(pr.first,pr.second-1));
            }
            if((pr.second+1)<n && grid[pr.first][pr.second+1]==1)
            {
                count++;
                grid[pr.first][pr.second+1]=2;
                stk.push(make_pair(pr.first,pr.second+1));
            }
        
        }
        return count;
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        
        int max1=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    max1=max(max1,getCount(i,j,m,n,grid));
                }
            }
        }
        return max1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends