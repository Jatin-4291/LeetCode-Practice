// Last updated: 8/30/2025, 1:21:38 PM
class Spreadsheet {
public:
    vector<vector<int>> x;
    
    Spreadsheet(int rows) { 
        x.resize(rows, vector<int>(26, 0)); // Initialize rows x 26 matrix
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A'; // Column as index (A = 0, B = 1, ...)
        int row = stoi(cell.substr(1)) - 1; // Convert "1" to index 0
        x[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        x[row][col] = 0;
    }
    int getCellValue(string s){
        if(!isdigit(s[0])){
        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;
        return x[row][col];
        }else{
            return stoi(s);
        }
    }
    int getValue(string formula) {
        if (formula[0] != '=') return stoi(formula);
        
        formula = formula.substr(1);
        size_t plusPos = formula.find('+'); 
        
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);
        return getCellValue(left) + getCellValue(right);
    }
};