//https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int k = 0;
        unsigned db = x ^ y;
        while(db){
            k++;
            db=(db)&(db - 1);
        }
        return k;
    }
};