// Last updated: 8/30/2025, 1:24:26 PM
#include <unordered_map>
#include <set>
using namespace std;

class NumberContainers {
public:
    unordered_map<int, int> indexToNumber; // Stores {index -> number}
    unordered_map<int, set<int>> numberToIndices; // Stores {number -> set of indices}

    NumberContainers() {}

    void change(int index, int number) {
        // If index already exists, remove it from previous number's index set
        if (indexToNumber.count(index)) {
            int oldNumber = indexToNumber[index];
            numberToIndices[oldNumber].erase(index);
            if (numberToIndices[oldNumber].empty()) {
                numberToIndices.erase(oldNumber);
            }
        }
        
        // Update index to new number
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    
    int find(int number) {
        // If number exists, return the smallest index
        if (numberToIndices.count(number) && !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin(); // Smallest index
        }
        return -1;
    }
};
