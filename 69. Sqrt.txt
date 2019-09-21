https://leetcode.com/problems/sqrtx/

class Solution {
public:
    
    int newton(double x, double g){   // Метод Ньютона
        if(abs(g*g - x) <= 0.00001){
            return g;
        }
        
        double ng = g - (g*g - x)/(2*g);
        return newton(x, ng);
    }
    
    int mySqrt(int x) { 
        return newton(x,1);
    }
};