class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Initialize the result vector to store Pascal's triangle
        vector<vector<int>> triangle;
      
        // Add the first row [1] to the triangle
        triangle.push_back(vector<int>(1, 1));
      
        // Generate remaining rows (from row 2 to numRows)
        for (int rowIndex = 0; rowIndex < numRows - 1; ++rowIndex) {
            // Create a new row for the current level
            vector<int> currentRow;
          
            // First element of each row is always 1
            currentRow.push_back(1);
          
            // Calculate middle elements by summing adjacent elements from previous row
            for (int colIndex = 1; colIndex < triangle[rowIndex].size(); ++colIndex) {
                int sum = triangle[rowIndex][colIndex - 1] + triangle[rowIndex][colIndex];
                currentRow.push_back(sum);
            }
          
            // Last element of each row is always 1
            currentRow.push_back(1);
          
            // Add the completed row to the triangle
            triangle.push_back(currentRow);
        }
      
        return triangle;
    }
};