//https://leetcode.com/problems/rectangle-area/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1=(C-A)*(D-B);
        int area2=(G-E)*(H-F);

        if(A>=G || B>=H || C<=E || D<=F) return area1+area2;            
        else return area1-(min(C, G)-max(A, E))*(min(D, H)-max(B, F))+area2;
    }
};