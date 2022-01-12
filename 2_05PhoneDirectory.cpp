// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

struct Tree{
    set<pair<char,Tree *>> vec;
    bool isEnd;
};
class Solution{
public:
    Tree *treehead;
    void preorder(Tree *tr)
    {
        
        if(tr==nullptr)
        {
            return;
        }
        //cout<<"5 reach\n";
        std::set<std::pair<char, Tree*> >:: iterator it ;
        std::set<std::pair<char, Tree*> > vec=tr->vec;
        for (it = vec.begin(); it != vec.end(); ++it)
        {
            //cout<<it->first<<"\t";
            preorder(it->second);
        }
    }
    void traverse(Tree *tr, string str, set<string>& vec2)
    {
        if(tr->isEnd)
            vec2.insert(str);
        std::set<std::pair<char, Tree*> >:: iterator it ;
        std::set<std::pair<char, Tree*> > vec=tr->vec;
        
        for (it = vec.begin(); it != vec.end(); ++it)
        {
            traverse(it->second,str+it->first, vec2);
        }   
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        treehead= new Tree();
        
        treehead->isEnd=false;
        Tree *treecn=treehead;
        
        for(int i=0;i<n;i++)
        {
            
            string str=contact[i];
            treecn=treehead;
            
            for(int j=0;j<str.length();j++)
            {
                std::set<std::pair<char, Tree*> >:: iterator it ;
                std::set<std::pair<char, Tree*> > vec=treecn->vec;
                bool found=false;
                for (it = vec.begin(); it != vec.end(); ++it)
                {
                    if (it->first == str[j])
                    {
                        treecn=it->second;
                        found=true;
                        if(str.length()==(j+1))
                            treecn->isEnd=true;
                        break;
                    }
                }
                if(!found)
                {
                    Tree *nn=new Tree();
                    nn->isEnd=false;
                    if(str.length()==(j+1))
                        nn->isEnd=true;
                    treecn->vec.insert(make_pair(str[j],nn));
                    treecn=nn;
                }    
            }
        }
        //preorder(treehead);
        //cout<<"\n";
        vector<vector<string>> res;
        
        // code here
        string current="";
        treecn=treehead;
        for(int i=0;i<s.length();i++)
        {
            std::set<std::pair<char, Tree*> >:: iterator it ;
            std::set<std::pair<char, Tree*> > vec=treecn->vec;
            bool found=false;
            set<string> vec2;
            for(it=vec.begin();it!=vec.end();it++)
            {
                if (it->first == s[i])
                {
                    current=s.substr(0,i+1);
                    traverse(it->second,current, vec2);

                    vector<string> vec3;
                    for(auto it:vec2)
                    {
                        vec3.push_back(it);
                    }
                    res.push_back(vec3);
                    //traverse(treecn);
                    treecn=it->second;
                    found=true;
                }
            }
            if(!found)
            {
                for(int j=i;j<s.length();j++)
                {
                    res.push_back({"0"});
                }
                break;
            }
            
        }
        return res;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        //cout<<"n:"<<n<<"\n";
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        //ob.check();
        //ob.displayContacts(n, contact, s);
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends