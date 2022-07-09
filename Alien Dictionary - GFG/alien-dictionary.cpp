// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    // adj[currNode] stores the characters bigger than currNode
    // if a < b, then adj[a] = {b}
    unordered_map<char, vector<char>> adj;
    
    // visited[i]   = 0 -> not visited
    //              = 1 -> visited in current traversals
    //              = 2 -> visited in previous traversals
    vector<int> visited;
    
    string topo;
    
    bool isCycle = false;
    
    bool invalidOrder = false;
    
    void dfs(char curr){
        // current node is added to visited list
        visited[curr] = 1;
        for(auto i:adj[curr]){
            if(visited[i]==0){
                dfs(i);
            }
            else if(visited[i]==1){
                isCycle = true;
            }
        }
        // since no cycles found for curr, visited[curr] = 2
        visited[curr] = 2;
        topo.push_back(curr);
    }
    
    void compareStrings(string &a, string &b){
        int p=0;
        // find first different character
        while(p < min(a.length(),b.length())){
            if(a[p]==b[p]){
                p++;
            }
            else {
                // if we dont reach end, it means the characters differ. add the successor to adj[curr]
                adj[a[p]].push_back(b[p]);
                break;
            }
        }
        
        // if one string is prefix of another, check if smaller length one is first
        if(p==min(a.length(),b.length())){
            if(a.length() > b.length()){
                invalidOrder = true;
            }
        }
    }
    
    string findOrder(string dict[], int N, int K) {
        // initiate all parent nodes with 0 children
        for(int i=0;i<K;i++){
            adj['a'+i] = {};
        }
        
        // modify adjacency list by finding parent and child after comparing adjacent strings
        for(int i=1;i<N;i++){
            compareStrings(dict[i-1], dict[i]);
        }
        
        // initialise all nodes as unvisited
        visited.resize(128,0);
        
        // perform topological sort using DFS. add a character only after all its children are added
        for(auto it:adj){
            char ch = it.first;
            if(visited[ch]==0){
                dfs(ch);
            }
        }
        
        // if there is cycle in graph or the given ordering is not correct, return empty string
        if(isCycle==true || invalidOrder==true){
            return "";
        }
        
        reverse(topo.begin(), topo.end());
        // cout<<topo<<"\n";
        return topo;
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
        //	cout<<p1<<" "<<p2<<endl;
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