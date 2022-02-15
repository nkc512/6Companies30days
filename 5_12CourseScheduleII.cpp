class Solution {
public:
    vector<int> res;
    void dfs(vector<vector<int>>& preq, int index, vector<int> &visit)
    {
        visit[index]=2;
        for(int i:preq[index])
        {
            if(visit[i]==0)
                dfs(preq, i, visit);
        }
        res.push_back(index);
    }
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
    bool isPossible(int N, vector<vector<int>>& adjacent()) {
	    // Code here
	    
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adjacent(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adjacent[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        res.clear();
        if(!isPossible(numCourses, adjacent))
        {
            return {};
        }
        vector<int> visit(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(visit[i]==0)
            {
                dfs(adjacent, i, visit);   
            }
        }
        return res;
    }
};