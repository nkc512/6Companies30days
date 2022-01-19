// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void dfs(std::vector<std::set<int>> &direction, std::vector<int> &visit, int current,std::vector<int> &res)
    {
        visit[current]=2;
        for(int i: direction[current])
        {
            if(visit[i]==0)
                dfs(direction, visit, i, res);
        }
        res.push_back(current);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        //cout<<"24\n";
        std::vector<std::set<int>> direction(26);
        vector<bool> available(26,false);
        int count=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<dict[i].length();j++)
            {
                if(!available[dict[i][j]-'a'])
                {
                    available[dict[i][j]-'a']=true;
                    count++;
                    if(count==K)
                    {
                        i=N;
                        break;
                    }
                }

            }
        }
        //cout<<"44\n";
        for(int i=0;i<N-1;i++)
        {
            int j=i+1;
            int k=0;
            int minlen=min(dict[i].length(),dict[j].length());
            //cout<<dict[i]<<":access\n";
            while(k<minlen)
            {
                
                if(dict[i][k]!=dict[j][k])
                {
                    set<int> sets=direction[dict[j][k]-'a'];
                    if(find(sets.begin(),sets.end(),dict[i][k]-'a')==sets.end())
                    {
                        direction[dict[j][k]-'a'].insert(dict[i][k]-'a');
                    }
                    break;
                }
                k++;
            }
        
        }
        //cout<<"66\n";
        vector<int> visit(26,0);
        std::vector<int> res;
        for(int i=0;i<26;i++)
        {
            if(visit[i]==0 && available[i])
            {
                dfs(direction, visit, i, res);
            }
        }
        //reverse(res.begin(), res.end());
        string str="";
        for(int i=0;i<res.size();i++)
        {
            char ch=res[i]+'a';
            str+=ch;
        }
        //cout<<str<<"\n";
        return str;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //  cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends