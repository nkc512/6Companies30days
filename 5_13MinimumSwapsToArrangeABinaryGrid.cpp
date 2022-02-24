class Solution {
public:
    
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> vec(grid.size(),0);
        int gridlen=grid.size();
        int count=0;
        for(int i=0;i<gridlen;i++)
        {
            int sum=0;
            for(int j=gridlen-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                    sum++;
                else
                    break;
            }
            vec[i]=sum;
        }
        int k=gridlen-1;
        //cout<<"reach1\n";
        for(int i=0;i<gridlen;i++)
        {
            //cout<<"reach2\n";
            if(vec[i]<k)
            {
                //cout<<"reach3\n";
                int j=i+1;
                while(j<gridlen && vec[j]<k)
                {
                    j++;
                }
                //cout<<"reach4:"<<j<<"\n";
                if(j==gridlen)
                    return -1;
                
                for(int l=j;l>i;l--)
                {
                    swap(vec[l],vec[l-1]);
                    count++;
                }
                
            }
            //cout<<"reach5\n";
            k--;
        }
        
        
        /*
        for(int i=0;i<gridlen;i++)
        {
            bool temp=false;   
            for(int j=0;j<gridlen-i-1;j++)
            {
                if(vec[j]<(gridlen-j-1))
                    temp=true;
                if(vec[j]<vec[j+1] && temp)
                {
                    swap(vec[j],vec[j+1]);
                    count++;
                }
            }
        }
        for(int i=0;i<gridlen;i++)
        {
            if(vec[i]<(gridlen-i-1))
                return -1;
        }*/
        /*
        vector<pair<int,int>> vec2(gridlen);
        
        
        for(int i=0;i<gridlen;i++)
        {
            vec2[i]={vec[i],i};
        }
        sort(vec2.begin(),vec2.end(),greater<>());
        cout<<"before\n";
        for(int i=0;i<gridlen;i++)
        {
            cout<<vec2[i].first<<"\t"<<vec2[i].second<<"\n";    
        }
        cout<<"\n";        
        for(int i=0;i<gridlen;i++)
        {
            if(vec2[i].first<(gridlen-i-1))
                return -1;
            
            if(vec2[i].second!=i)
            {
                //cout<<vec2[i].second<<"\t"<<i<<"\n";
                count+=vec2[i].second-vec2[vec2[i].second].second;
                swap(vec2[i].second,vec2[vec2[i].second].second);
                
                i--;
            }
        }
        
        cout<<"after\n";
        for(int i=0;i<gridlen;i++)
        {
            cout<<vec2[i].first<<"\t"<<vec2[i].second<<"\n";    
        }
        cout<<"\n";
        */
        return count;
        
    }
};
/*
[[1,0,0,0,0,0],[0,0,0,1,0,0],[0,0,0,1,0,0],[0,1,0,0,0,0],[0,0,1,0,0,0],[0,0,0,0,0,1]]
[[0,0,1],[1,1,0],[1,0,0]]
[[1,0,0],[1,1,0],[1,1,1]]
[[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
[[0,0,1],[1,1,0],[1,0,0]]
[[0,0,1],[1,1,0],[1,0,1]]
[[0,0,1],[1,0,0],[0,0,0]]
[[0,0,0],[1,0,0],[1,0,0]]
[[0,0,0],[1,0,0],[0,0,0]]
[[0,0,0],[0,0,0],[0,0,0]]
[[1,1,1],[1,1,0],[1,1,0]]
[[1,0,0],[1,1,0],[0,0,1]]
[[1,1],[1,0]]
[[1,1],[0,0]]
[[1,0],[0,0]]
[[1]]
[[0]]
*/