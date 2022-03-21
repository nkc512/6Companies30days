typedef priority_queue<pair<double,int>,vector<pair<double,int>>, greater<pair<double,int>>> MinHeap;
class Solution {
public:
    double dijkstra(vector<vector<pair<double,int>>> adjacent, int n,int start, int end)
    {
        MinHeap minHeap;
        minHeap.push({-1,start});
        vector<double> prob(n,0);
        vector<bool> visited(n,false);
        prob[start]=-1; // Probability will increase as -1 < -0.8 < -0.3
        
        while(!minHeap.empty())
        {
            
            auto [curProb, curNode]=minHeap.top();
            minHeap.pop();
            
            if(curNode==end)
                break;
            if(visited[curNode]) continue;
            
            visited[curNode]=true;
            for(auto &[nextProb, nextNode]: adjacent[curNode])
            {
                double nextDist=curProb*nextProb;
                
                if(!visited[nextNode] and prob[nextNode]>nextDist)
                {
                    minHeap.push({prob[curNode]*nextProb,nextNode});
                    prob[nextNode]=prob[curNode]*nextProb;
                }
            }
        }
        if(prob[end]==0)
            return 0;
        return -prob[end];
        
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // adjacent list row, (succProb,col)
        vector<vector<pair<double,int>>> adjacent(n);
        
        for(int i=0;i<succProb.size();i++)
        {
            adjacent[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adjacent[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        
        return dijkstra(adjacent, n, start, end);
    }
};