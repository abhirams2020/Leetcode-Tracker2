class Solution {
public:
    string intToRoman(int num) {
        vector<int> integer = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans;
        for(int i=0;i<integer.size();i++){
            while(num>=integer[i]){
                ans += roman[i];
                num -= integer[i];
            }
        }
        return ans;
    }
};