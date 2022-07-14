class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";
        char prev=chars[0];
        int count = 1;
        // if prev!=curr, add {char+count} to ans. else increase count.
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
        // to add the last character's count.
        if(count!=1){
            ans += prev + to_string(count);
        }
        else {
            ans += prev;
        }
        // chars.resize(ans.length());
        // for(int i=0;i<ans.length();i++){
        //     chars[i] = ans[i];
        // }
        chars.clear();
        for(int i=0;i<ans.length();i++){
            chars.push_back(ans[i]);
        }
        return chars.size();
    }
};