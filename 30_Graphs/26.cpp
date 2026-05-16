//  Flood Fill Algorithm
// Image ma connected cells ne navi color thi fill karo
#include <iostream>
#include <vector>
using namespace std;

void floodFillHelper(vector<vector<int>> &image, int row, int col,
                     int newColor, int oldColor) {
    // boundary check
    if (row < 0 || row >= image.size()) return;
    if (col < 0 || col >= image[0].size()) return;
    if (image[row][col] != oldColor) return;

    image[row][col] = newColor;

    // 4 directions
    floodFillHelper(image, row-1, col, newColor, oldColor); // up
    floodFillHelper(image, row+1, col, newColor, oldColor); // down
    floodFillHelper(image, row, col-1, newColor, oldColor); // left
    floodFillHelper(image, row, col+1, newColor, oldColor); // right
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int row,
                               int col, int newColor) {
    int oldColor = image[row][col];
    if (oldColor != newColor) {
        floodFillHelper(image, row, col, newColor, oldColor);
    }
    return image;
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int row = 1, col = 1, newColor = 2;
    vector<vector<int>> result = floodFill(image, row, col, newColor);

    for (auto row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    // 2 2 2
    // 2 2 0
    // 2 0 1
    return 0;
}

// ANS:=
// 2 2 2 
// 2 2 0 
// 2 0 1 