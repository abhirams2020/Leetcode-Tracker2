class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";
        char prev=chars[0];
        int count = 1;
        // cout<<"Hi0\n";
        for(int i=1;i<chars.size();i++){
            if(chars[i]!=prev){
                if(count!=1){
                    ans += prev + to_string(count);
                }
                else {
                    ans += prev;
                }
                prev = chars[i];
                count = 1;
            }
            else {
                count++;
            }
        }
        // cout<<"Hi\n";
        if(count!=1){
            ans += prev + to_string(count);
        }
        else {
            ans += prev;
        }
        // chars.clear();
        chars.resize(ans.length());
        // cout<<"Hi2\n";
        for(int i=0;i<ans.length();i++){
            chars[i] = ans[i];
        }
        // cout<<ans<<"\n";
        return chars.size();
    }
};