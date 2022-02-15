class Solution {
public:
    void traverse(vector<vector<int>>& adjacent, int index, vector<int> &visited)
    {
        if(visited[index]==1)
            return;
        visited[index]=2;
        for(int i:adjacent[index])
        {
            if(visited[i]!=1 && visited[i]!=2)
            {
                traverse(adjacent, i, visited);
            }
        }
        visited[index]=1;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int isConnectedSize=isConnected.size();
        vector<vector<int>> adjacent(isConnectedSize);
        int count=0;
        for(int i=0;i<isConnectedSize;i++)
        {
            for(int j=0;j<isConnectedSize;j++)
            {
                if(isConnected[i][j]==1)
                    adjacent[i].push_back(j);
            }
        }
        
        
        for(int i=0;i<isConnectedSize;i++)
        {
            if(visited[i]==0)
            {
                count++;
                traverse(adjacent, i, visited); 
            }
        }
        return count;

    }
};