// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    // Code here
    vector<int> vec;
    int strlength=str.length();
    for(int i=1;i<=6;i++)
    {
        vec.clear();
        int k=i;
        int l=-1;
        int num=0;
        int count=0;
        int temp=0;
        for(int j=0;j<strlength;j++)
        {
            num=num*10+str[j]-48;
            if((j-l)==k)
            {
                if(num==(pow(10,k)-1))
                    k++;
                if((j+1)<strlength && str[j+1]=='0')
                {
                    num=num*10;
                    k++;
                    j++;
                }
                vec.push_back(num);
                l=j;
                num=0;
                int m=vec.size()-1;
                if(m>0)
                {
                    int diff=vec[m]-vec[m-1];
                    if(diff==2)
                    {
                        temp=vec[m]-1;
                        count++;
                        if(count>=2)
                            break;
                    }
                    if(diff>2 || diff<1)
                    {
                        count=2;
                        break;
                    }
                }
            }
            
            
        }
        
        if(count==1)
        {
            return temp;
        }
    }
    return -1;
}