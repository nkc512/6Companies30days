class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        stack<vector<int>> stk;
        vector<int> vec(2);
        int height=grid.size();
        int width=grid[0].size();
        int count=0;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(grid[i][j]==2)
                {
                    stk.push({i,j});
                    grid[i][j]=0;
                }    
                else if(grid[i][j]==1)
                {
                    grid[i][j]=1000;
                    count++;
                }
                else
                    grid[i][j]=-1;
            }
        }
        if(count==0)
            return 0;
        if(stk.empty())
            return -1;
        while(!stk.empty())
        {
            vec=stk.top();
            int y=vec[0];
            int x=vec[1];
            int level1=grid[y][x]+1;
            stk.pop();
            
            if(y>0 && grid[y-1][x]!=-1 && grid[y-1][x]>level1)
            {
                grid[y-1][x]=level1;
                stk.push({y-1,x});
            
            }
            if(y<(height-1) && grid[y+1][x]!=-1  && grid[y+1][x]>level1)
            {
                grid[y+1][x]=level1;
                stk.push({y+1,x});
            }
            if(x<(width-1) && grid[y][x+1]!=-1 && grid[y][x+1]>level1)
            {
                grid[y][x+1]=level1;
                stk.push({y,x+1});
            }
            if(x>0 && grid[y][x-1]!=-1 && grid[y][x-1]>level1)
            {
                grid[y][x-1]=level1;
                stk.push({y,x-1});
            }
        }
        int time=0;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(grid[i][j]==1000)
                    return -1;
                time=max(time,grid[i][j]);
                //cout<<grid[i][j]<<"\t";
            }
            //cout<<"\n";
        }
        return time;
    }
};
/*
[[2,1,1],[1,1,1],[0,1,2]]
[[2,1,1],[1,1,0],[0,1,1]]
[[2,1,1],[0,1,1],[1,0,1]]
[[0,2]]
[[2,1,1],[1,0,0],[1,1,1]]
[[2,1,1],[1,0,0],[1,1,0]]
[[2,1,1],[1,0,0],[1,2,0]]
[[2,1,1],[1,2,0],[1,1,0]]
[[2,2,2],[2,2,0],[2,2,0]]
[[1,1,1],[1,1,0],[1,0,0]]
[[1,1,1],[1,2,0],[1,0,0]]
[[2,1,2],[1,2,0],[1,0,0]]
[[0]]
[[1]]
[[2]]
[[2,1],[1,2]]
[[2,1,0]]
[[2,0,1]]
[[2],[0],[1]]
*/