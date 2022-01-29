class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int gridlen=grid.size();
        stack<pair<int,int>> stk;
        bool temp=false;
        for(int i=0;i<gridlen;i++)
        {
            for(int j=0;j<gridlen;j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;
                    stk.push({i,j});
                }    
                else
                {
                    grid[i][j]=10000;
                    temp=true;
                }    
            }
        }
        if(!temp || stk.empty())
        {
            return -1;
        }
        while(!stk.empty())
        {
            pair<int,int> index=stk.top();
            stk.pop();
            int curr=grid[index.first][index.second];
            if(index.first>0 && (curr+1)<grid[index.first-1][index.second])
            {
                grid[index.first-1][index.second]=curr+1;
                stk.push({index.first-1,index.second});
            }
            if(index.first<(gridlen-1) && (curr+1)<grid[index.first+1][index.second])
            {
                grid[index.first+1][index.second]=curr+1;
                stk.push({index.first+1,index.second});
            }
            if(index.second>0 && (curr+1)<grid[index.first][index.second-1])
            {
                grid[index.first][index.second-1]=curr+1;
                stk.push({index.first,index.second-1});
            }
            if(index.second<(gridlen-1) && (curr+1)<grid[index.first][index.second+1])
            {
                grid[index.first][index.second+1]=curr+1;
                stk.push({index.first,index.second+1});
            }
        }
        int maxv=0;
        for(int i=0;i<gridlen;i++)
        {
            for(int j=0;j<gridlen;j++)
            {
                if(grid[i][j]>maxv)
                {
                    maxv=grid[i][j];
                }
            }
        }
        return maxv;
    }
};