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
    
    unordered_set<char> visited;
    
    string topo;
    
    void dfs(char curr){
        visited.insert(curr);
        for(auto it:adj[curr]){
            if(visited.count(it)==0){
                dfs(it);
            }
        }
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
        
        // perform topological sort using DFS. add a character only after all its children are added
        for(auto it:adj){
            char k = it.first;
            if(visited.count(k)==0){
                dfs(k);
            }
        }
        
        reverse(topo.begin(), topo.end());
        
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