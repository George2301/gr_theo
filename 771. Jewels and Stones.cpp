//https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int k = 0;
        for (int n = 0; n < size(S); n++){
            for (int i = 0; i < size(J); i++){
                if (J[i] == S[n]){
                    k++;
                }
            }
        }
        return k;
    }
};