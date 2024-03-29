/*
// USING STRINGSTREAM
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        // add words to stringstream
        ss<<s;
        vector<string> v;
        string str;
        // read each word from stringstream
        while(ss>>str){
            v.push_back(str);
        }
        // reverse order of words
        reverse(v.begin(),v.end());
        // add each word to ans with space after it
        string ans;
        for(int i=0;i<v.size();i++){
            ans += v[i] + " ";
        }
        // remove last space
        ans.pop_back();
        
        return ans;
    }
};
*/

// FINDING EACH WORD AND ADD TO VECTOR
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        
        for(int i=0;i<s.length();){
            // if space, skip that index
            if(s[i]==' '){
                i++;
                continue;
            }
            // if we reach character, add are contiguous chars to a word and add to words[]
            string word;
            while(i<s.length() && s[i]!=' '){
                word.push_back(s[i]);
                i++;
            }
            words.push_back(word);
        }
        // add reverse words to ans with space in between
        string ans = "";
        for(int i=words.size()-1;i>=0;i--){
            ans += words[i] + " ";
        }
        ans.pop_back();
        return ans;
    }
};

/*
// IN PLACE SOLUTION O(1) SPACE
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int l=0,r=0;
        while(l<s.length()){
            // find starting point of word by moving to next character position
            while(l<s.length() && s[l]==' '){
                l++;
            }
            if(l==s.length()){
                break;
            }
            // find ending point of word by moving to next space position
            r = l;
            while(r<s.length() && s[r]!=' '){
                r++;
            }
            // important step : add the current word before the ans.
            ans = s.substr(l,r-l) + " " + ans;
            l = r;
        }
        ans.pop_back();
        return ans;
    }
};
*/