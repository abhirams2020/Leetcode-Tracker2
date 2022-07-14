/*
// USING ANOTHER STRING TO STORE RESULT AND COPYING THAT TO CHARS
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
        
        // Replace chars with elements in ans
        chars.clear();
        for(int i=0;i<ans.length();i++){
            chars.push_back(ans[i]);
        }
        // chars.resize(ans.length());
        // for(int i=0;i<ans.length();i++){
        //     chars[i] = ans[i];
        // }
        return chars.size();
    }
};
*/

// CHANGING THE ARRAY IN PLACE USING FAST AND SLOW POINTER
class Solution {
public:
    int compress(vector<char>& chars) {
        // slow denotes position to add current char and its count
        // fast denotes position where we're checking if curr==prev
        int slow = 0, fast = 1;
        int count = 1;
        while(fast<=chars.size()){
            if(fast==chars.size() || chars[fast]!=chars[fast-1]){
                // add char + count to slow position and move  slow
                chars[slow] = chars[fast-1];
                slow++;
                if(count!=1){
                    for(auto c:to_string(count)){
                        chars[slow] = c;
                        slow++;
                    }
                }
                count = 1;
            }
            else {
                count++;
            }
            fast++;
        }
        // slow stores index to modify in array. we completed checking the array, slow=new array.size()
        return slow;
    }
};