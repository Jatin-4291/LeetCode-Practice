// Last updated: 8/30/2025, 1:22:38 PM
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int height1 = 0, height2 = 0;
        int tempBlue = blue, tempRed = red;
        int j = 1;

        // Case 1: Start with blue
        while ((j % 2 == 1 && tempBlue >= j) || (j % 2 == 0 && tempRed >= j)) {
            if (j % 2 == 1) {
                tempBlue -= j;  // Use blue on odd heights
            } else {
                tempRed -= j;   // Use red on even heights
            }
            height1++;
            j++;
        }

        // Reset values for the second case
        tempBlue = blue;
        tempRed = red;
        j = 1;

        // Case 2: Start with red
        while ((j % 2 == 1 && tempRed >= j) || (j % 2 == 0 && tempBlue >= j)) {
            if (j % 2 == 1) {
                tempRed -= j;  // Use red on odd heights
            } else {
                tempBlue -= j; // Use blue on even heights
            }
            height2++;
            j++;
        }

        return max(height1, height2);
    }
};
