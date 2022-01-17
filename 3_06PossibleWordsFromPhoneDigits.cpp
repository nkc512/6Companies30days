// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    char charpossible(int n,int index)
    {
        if(n<=7)
        {
            return (n-2)*3+index+97;
        }
        if(n==8)
        {
            return 116+index;
        }
        return 119+index;
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> vec={""};
        for(int i=0;i<N;i++)
        {
            vector<string> vec2=vec;
            vector<string> vec3=vec;
            char ch=charpossible(a[i],0);
            for(int j=0;j<vec2.size();j++)
            {
                vec3[j]=vec2[j]+ch;
            }
            
            vec.clear();
            vec.insert(vec.end(),vec3.begin(),vec3.end());
            ch=charpossible(a[i],1);
            vec3=vec2;
            
            for(int j=0;j<vec2.size();j++)
            {
                vec3[j]=vec2[j]+ch;
            }
            
            vec.insert(vec.end(),vec3.begin(),vec3.end());
            ch=charpossible(a[i],2);
            vec3=vec2;
            
            for(int j=0;j<vec2.size();j++)
            {
                vec3[j]=vec2[j]+ch;
            }
            
            vec.insert(vec.end(),vec3.begin(),vec3.end());
            
            if(a[i]==7||a[i]==9)
            {
                ch=charpossible(a[i],3);
                vec3=vec2;
                for(int j=0;j<vec2.size();j++)
                {
                    vec3[j]=vec2[j]+ch;
                }    
                vec.insert(vec.end(),vec3.begin(),vec3.end());
            }
        }
        sort(vec.begin(),vec.end());
        
        return vec;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends