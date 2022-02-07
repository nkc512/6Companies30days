class Solution {
public:
    int power(int i)
    {
        return i*i;
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        map<int,int> mp;
        int sum=0;
        for(int i=0;i<points.size();i++)
        {
            mp.clear();
            for(int j=0;j<points.size();j++)
            {
                int sq=power(points[i][0]-points[j][0])+power(points[i][1]-points[j][1]);
                if(mp.find(sq)!=mp.end())
                {
                    mp[sq]++;
                }
                else
                    mp[sq]=1;
            }
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                sum+=(it->second)*(it->second-1);
            }
        }
        
        
        return sum;
    }
};