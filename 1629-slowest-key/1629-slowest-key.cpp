class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxTime = releaseTimes[0];
        char maxChar = keysPressed[0];
        for(int i=1;i<releaseTimes.size();i++){
            if(releaseTimes[i]-releaseTimes[i-1] > maxTime){
                maxTime = releaseTimes[i]-releaseTimes[i-1];
                maxChar = keysPressed[i];
            }
            else if(releaseTimes[i]-releaseTimes[i-1]==maxTime){
                if(keysPressed[i] > maxChar){
                    maxChar = keysPressed[i];
                }
            }
        }
        return maxChar;
    }
};