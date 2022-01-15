// { Driver Code Starts
//Initial Template for C



#include<stdio.h>

 // } Driver Code Ends
//User function Template for C


void rotate(int n,int a[][n])
{
    //code here
    for(int y=0;y<(n/2)+n%2;y++)
    {
        for(int x=0;x<n/2;x++)
        {
            int temp=a[y][x];
            a[y][x]=a[x][n-1-y];
            a[x][n-1-y]=a[n-1-y][n-1-x];
            a[n-1-y][n-1-x]=a[n-1-x][y];
            a[n-1-x][y]=temp;
        }
    }
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d",&t); 
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }
        rotate(n,a);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}

  // } Driver Code Ends