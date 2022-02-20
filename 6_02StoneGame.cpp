class Solution {
public:
    /*
    int dp(vector<int>& piles, int i, int j)
    {
        if(j<=i)
            return 0;
        return max(
            min(dp(piles,i+1,j-1) + piles[j], dp(piles,i+2,j)+piles[i+1])+piles[i],
            min(dp(piles,i+1,j-1) + piles[i], dp(piles,i,j-2)+piles[j-1])+piles[j]
        );
    }
    */
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        int pilelen=piles.size();
        vector<vector<int>> matrix(pilelen,vector<int>(pilelen,0));
	    
        for(int k=0;k<pilelen;k++)
        {
            
            for(int i=0,j=k;j<pilelen;i++,j++)
            {
                if(k==0)
                    matrix[i][j]=piles[i];
                else if(k==1)
                    matrix[i][j]=max(piles[i],piles[j]);
                else
                    matrix[i][j]=max(
                    piles[i]+min(matrix[i+1][j-1],matrix[i+2][j]),
                    piles[j]+min(matrix[i+1][j-1],matrix[i][j-2]));
            }
        }
        
        for(int i=0;i<pilelen;i++)
        {
            sum+=piles[i];
        }
        return matrix[0][pilelen-1]*2>sum;
    }
};