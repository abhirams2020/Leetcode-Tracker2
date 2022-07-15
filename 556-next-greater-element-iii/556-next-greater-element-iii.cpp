class Solution {
public:
    int nextGreaterElement(int num) {
        string str = to_string(num);
        
        int n = str.length();
        
        int p = -1; // pivot element - first decreasing element from end
        
        for(int i=n-2;i>=0;i--){
            if(str[i]-'0'< str[i+1]-'0'){
                p = i;
                break;
            }
        }
        
        // no pivot element found
        if(p==-1){
            reverse(str.begin(),str.end());
            return -1; // num cannot have greater permutation
        }
        
        // first element to right of pivot just greater than it and swap them
        for(int i=n-1;i>p;i--){
            if(str[i]-'0' > str[p]-'0'){
                swap(str[i],str[p]);
                break;
            }
        }
        // reverse the string right to pivot
        reverse(str.begin()+p+1,str.end());
        // convert to long since number may be greater than INT_MAX
        long res = stol(str);
        
        if(res>INT_MAX){
            return -1;
        }
        return res;
    }
};