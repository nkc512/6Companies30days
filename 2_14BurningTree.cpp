// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<Node*> vec;
    int times=0;
    int getHeight(Node* root)
    {
        if(root==nullptr)
            return 0;
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
    bool  preorder(Node* root, int target, vector<Node*> current)
    {

        if(root==NULL)
            return false;
        if(root->data==target)
        {
            current.push_back(root);
            vec=current;
            return true;
        }
        current.push_back(root);
        return preorder(root->right,target,current) || preorder(root->left,target,current);
    }
    
    int minTime(Node* root, int target) 
    {
        vector<Node*> vec2;
        preorder(root, target,vec2);
        int veclen=vec.size();
        
        int max1=getHeight(vec[veclen-1])-1;
        int k=1;

        for(int i=veclen-2;i>=0;i--)
        {
            Node * targetNode=vec[i+1];
            if(vec[i]->left==targetNode)
            {
                vec[i]->left=nullptr;
            }
            else
                vec[i]->right=nullptr;
            max1=max(max1,getHeight(vec[i])-1+k++);
        }

        return max1;
        // Your code goes here
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends