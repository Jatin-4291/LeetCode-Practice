// Last updated: 8/23/2025, 2:37:14 PM
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long k = 0;
        long long x=0;
        while (x < neededApples) {
            k++;
            x+=(12*k*k);
        }
        return 8 * k; 
    }
};