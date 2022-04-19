class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(); //vertical
        int n=heights[0].size(); // horizontal
        vector<vector<int>> reach(m,vector<int>(n,0));
        vector<vector<int>> res;

        stack<pair<int,int>> pacific;
        
        for(int i=0;i<n;i++){
            pacific.push({0,i});
        }
        for(int i=1;i<m;i++)
        {
            pacific.push({i,0});
        }
        while(!pacific.empty())
        {
            auto [row,column]=pacific.top();
            pacific.pop();
            reach[row][column]=1;
            int heightcurr=heights[row][column];
            
            if(row>0 && reach[row-1][column]==0 && heightcurr<=heights[row-1][column])
            {
                pacific.push({row-1,column});
                
            }
            if((row+1)<m && reach[row+1][column]==0 && heightcurr<=heights[row+1][column])
            {
                pacific.push({row+1,column});
                
            }
            if(column>0 && reach[row][column-1]==0 && heightcurr<=heights[row][column-1])
            {
                pacific.push({row,column-1});
                
            }
            if((column+1)<n && reach[row][column+1]==0 && heightcurr<=heights[row][column+1])
            {
                pacific.push({row,column+1});
                
            }
        }
        stack<pair<int,int>> atlantic;
        vector<vector<int>> reach2(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            atlantic.push({i,n-1});
        }
        for(int i=0;i<(n-1);i++){
            atlantic.push({m-1,i});
        }
        while(!atlantic.empty())
        {
            auto [row,column]=atlantic.top();
            atlantic.pop();
            auto heightcurr=heights[row][column];
            reach2[row][column]=1;            
            if(row>0 && reach2[row-1][column]==0 && heightcurr<=heights[row-1][column])
            {
                atlantic.push({row-1,column});
            }
            if((row+1)<m && reach2[row+1][column]==0 && heightcurr<=heights[row+1][column])
            {
                atlantic.push({row+1,column});
            }
            if(column>0 && reach2[row][column-1]==0 && heightcurr<=heights[row][column-1])
            {
                atlantic.push({row,column-1});
            }
            if((column+1)<n && reach2[row][column+1]==0 && heightcurr<=heights[row][column+1])
            {
                atlantic.push({row,column+1});
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(reach[i][j] && reach2[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};