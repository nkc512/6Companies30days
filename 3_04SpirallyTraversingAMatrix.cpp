// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> vec;
        int up=0,left=0, right=c-1, down=r-1;
        int iteration=min(r,c)/2+min(r,c)%2;
        int dir=0;
        while(up<=down && left<=right)
        {
            if(dir==0)
            {
                for(int j=left;j<=right;j++)
                {
                    vec.push_back(matrix[up][j]);
                }
                up++;       
            }
            else if(dir==1)
            {
                for(int j=up;j<=down;j++)
                {
                    vec.push_back(matrix[j][right]);
                }
                right--;
            }
            else if(dir==2)
            {
                for(int j=right;j>=left;j--)
                {
                    vec.push_back(matrix[down][j]);
                }
                down--;
            }
            else
            {
                for(int j=down;j>=up;j--)
                {
                    vec.push_back(matrix[j][left]);
                }
                left++;    
            }
            dir=(dir+1)%4;
            
        }
        return vec;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends