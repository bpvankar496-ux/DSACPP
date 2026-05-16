//2D array
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "enter rows : ";
    cin >> rows;
    cout << "enter cols : ";
    cin >> cols;

    int* *matrix = new int*[rows];

    for(int i=0; i<rows; i++) {
        matrix[i] = new int[cols];
    }

    //data store
    int x = 1;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // memory free (important)
    for(int i=0; i<rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

//STL=library ch jya c++ mate prebuild code hse use kaari sky if jya sudhi intrveiwr jate  karva k to j jate...vector<vector<int>> aa method thi one line code thai jay

// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){

//     int rows, cols;
//     cout<<"Enter rows: ";
//     cin>>rows;
//     cout<<"Enter cols: ";
//     cin>>cols;

//     vector<vector<int>> matrix(rows, vector<int>(cols));

//     int x = 1;
//     for(int i=0; i<rows; i++){
//         for(int j=0; j<cols; j++){
//             matrix[i][j] = x++;
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// ANS:=
// enter rows : 3
// enter cols : 3
// 1 2 3
// 4 5 6
// 7 8 9