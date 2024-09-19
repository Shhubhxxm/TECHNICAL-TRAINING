#include <vector>
#include <iostream>

// Function to get the specific row from Pascal's Triangle
std::vector<int> getPascalsTriangleRow(int rowIndex) {
    std::vector<int> row(rowIndex + 1, 1);  // Initialize a vector with size rowIndex + 1, all elements set to 1

    for (int i = 1; i <= rowIndex; ++i) {
        for (int j = i - 1; j > 0; --j) {
            row[j] = row[j] + row[j - 1];
        }
    }
    
    return row;
}

// Function to print Pascal's Triangle up to the given row
void printPascalsTriangle(int rowIndex) {
    for (int i = 0; i <= rowIndex; ++i) {
        std::vector<int> row = getPascalsTriangleRow(i);
        
        // Print leading spaces for alignment
        for (int k = 0; k < rowIndex - i; ++k) {
            std::cout << "  ";
        }
        
        // Print each row
        for (int num : row) {
            std::cout << num << "   ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rowIndex = 5; // Example row index

    // Print Pascal's Triangle up to the row index
    std::cout << "Pascal's Triangle up to row " << rowIndex << ":\n";
    printPascalsTriangle(rowIndex);

    // Get and print the specific row
    std::vector<int> row = getPascalsTriangleRow(rowIndex);
    std::cout << "\nRow " << rowIndex << " of Pascal's Triangle: ";
    for (int num : row) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
