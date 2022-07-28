class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.length() || j<version2.length()){
            string v1,v2;
            // add all characters to string till '.' is reached
            while(i<version1.length() && version1[i]!='.'){
                v1 += version1[i];
                i++;
            }
            while(j<version2.length() && version2[j]!='.'){
                v2 += version2[j];
                j++;
            }
            // if version not empty, convert to int and compare
            int num1 = 0, num2 = 0;
            if(v1!=""){
                num1 = stoi(v1);
            }
            if(v2!=""){
                num2 = stoi(v2);
            }
            if(num1 < num2){
                return -1;
            }
            else if(num2 < num1){
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
};