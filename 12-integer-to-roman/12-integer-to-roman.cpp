class Solution {
public:
    unordered_map<int,string> mp = {{1,"I"}, 
                                    {4,"IV"},
                                    {5,"V"}, 
                                    {9,"IX"},
                                    {10,"X"}, 
                                    {40,"XL"}, 
                                    {50,"L"}, 
                                    {90,"XC"}, 
                                    {100,"C"}, 
                                    {400,"CD"}, 
                                    {500,"D"}, 
                                    {900,"CM"},
                                    {1000,"M"}};
    
    string reduce(int &num, int k){
        string ans;
        while(num>=k){
            ans += mp[k];
            num -= k;
        }
        return ans;
    }
    
    string intToRoman(int num) {
        string s = to_string(num);
        int len = s.length();
        string ans =    reduce(num,1000) + reduce(num,900) + reduce(num,500) + reduce(num,400) + 
                        reduce(num,100) + reduce(num,90) + reduce(num,50) + reduce(num,40) + 
                        reduce(num,10) + reduce(num,9) + reduce(num,5) + reduce(num,4) + reduce(num,1);
        return ans;
    }
};