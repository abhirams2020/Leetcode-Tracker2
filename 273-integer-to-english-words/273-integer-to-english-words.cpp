class Solution {
public:
    
    vector<string> LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> THOUSANDS = {"", "Thousand", "Million", "Billion"};

    string helper(int num) {
        // if num = 0, return ""
        // 1 to 19 is special range. call function LESS_THAN_2
        // for 2 digit numbers from 2, call TENS[i} + helper(next single digit)
        // for 3 digit numbers, call HUNDREDS[i} + "Hundred" + helper(next 2 digits)
        if(num >= 100){
            return LESS_THAN_20[num/100] + " Hundred " + helper(num%100);
        }
        else if(num >= 20){
            return TENS[num/10] + " " + helper(num%10);
        }
        else if(num >= 1){
            return LESS_THAN_20[num] + " ";
        }
        else { // if num == 0
            return "";
        }
    }
    
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        int i=0;
        string words;
        // take first 3 digits from num and if its more than 0, call helper to get name of the 3 digit and add thousands[i]
        while(num > 0){
            if(num%1000 != 0){
                // each time last 3 digit is taken and added to beginning of words if not zero
                words = helper(num%1000) + THOUSANDS[i] + " " + words;
            }
            num = num / 1000;
            i++;
        }
        // remove unwanted whitespace at end
        while(words[words.size()-1] == ' '){
            words.pop_back();
        }
        return words;
    }
};