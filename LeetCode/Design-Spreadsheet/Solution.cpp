#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    int rows;
    vector<vector<int>> grid; // rows x 26

    // Helper: parse a token (either int or cell reference)
    int getTokenValue(const string &token) {
        // Case 1: Integer
        if (isdigit(token[0])) {
            return stoi(token);
        }
        // Case 2: Cell reference like "A1"
        char col = token[0]; // 'A' - 'Z'
        int colIndex = col - 'A';
        int rowIndex = stoi(token.substr(1)) - 1; // 1-indexed → 0-indexed
        if (rowIndex < 0 || rowIndex >= rows) return 0; // safety
        return grid[rowIndex][colIndex];
    }

public:
    Spreadsheet(int r) {
        rows = r;
        grid.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        char col = cell[0];
        int colIndex = col - 'A';
        int rowIndex = stoi(cell.substr(1)) - 1;
        grid[rowIndex][colIndex] = value;
    }
    
    void resetCell(string cell) {
        char col = cell[0];
        int colIndex = col - 'A';
        int rowIndex = stoi(cell.substr(1)) - 1;
        grid[rowIndex][colIndex] = 0;
    }
    
    int getValue(string formula) {
        // format "=X+Y"
        string expr = formula.substr(1); // remove '='
        int plusPos = expr.find('+');
        string left = expr.substr(0, plusPos);
        string right = expr.substr(plusPos + 1);

        int val1 = getTokenValue(left);
        int val2 = getTokenValue(right);
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
