class Solution {
public:
    bool canAliceWin(int n) {
        
        int st = 10;
        int moves = 0;
        while(n >= 0) {
            moves++;
            n = n - st;
            if(n < 0) {
                
                break;
            }
            st--;
        }
        if(moves % 2 == 0) {
            return true;
        }
        return false;

    }
};