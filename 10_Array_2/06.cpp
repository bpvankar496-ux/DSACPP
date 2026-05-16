//trapping rainwater
//METHOD 1
// for every building:
//     left maximum find karo
//     right maximum find karo
//     min(left,right)-height
#include <iostream>
using namespace std;

int trap(int arr[], int n) {
    int water = 0;

    for(int i = 0; i < n; i++) {

        int leftMax = 0;
        for(int j = i; j >= 0; j--) {
            if(arr[j] > leftMax) {
                leftMax = arr[j];
            }
        }

        int rightMax = 0;
        for(int j = i; j < n; j++) {
            if(arr[j] > rightMax) {
                rightMax = arr[j];
            }
        }

        int currWater = min(leftMax, rightMax) - arr[i];

        if(currWater > 0) {
            water += currWater;
        }
    }

    return water;
}

int main() {
    int arr[] = {5,4,5,8,4,9,12};
    int n = 7;

    cout << "Water trapped = " << trap(arr, n);

    return 0;
}

//METHOD 2
#include <iostream>
using namespace std;

int trap(int *heights, int n) {
    int leftMax[20000], rightMax[20000];
    leftMax[0] = heights[0];
    rightMax[n-1] = heights[n-1];

    for(int i=1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], heights[i-1]);
    }

    for(int i=n-2; i>=0; i--) {
        rightMax[i] = max(rightMax[i+1], heights[i+1]);
    }

    int waterTrapped = 0;
    for(int i=0; i<n; i++) {
        int currWater = min(leftMax[i], rightMax[i]) - heights[i];
        if(currWater > 0) {
            waterTrapped += currWater;
        }
    }

    cout << "water trapped = " << waterTrapped << endl;
    return waterTrapped;
}

int main() {
    int heights[7] = {5, 4, 5 ,8 ,4 ,9 ,12};
    int n = sizeof(heights) / sizeof(int);

    trap(heights, n);
    return 0;
}


//METHOD 3

#include <iostream>
using namespace std;

int trap(int arr[], int n) {
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while(left < right) {

        if(arr[left] < arr[right]) {
            if(arr[left] >= leftMax) {
                leftMax = arr[left];
            } else {
                water += leftMax - arr[left];
            }
            left++;
        }
        else {
            if(arr[right] >= rightMax) {
                rightMax = arr[right];
            } else {
                water += rightMax - arr[right];
            }
            right--;
        }
    }

    return water;
}

int main() {
    int arr[] = {5,4,5,8,4,9,12};
    int n = 7;

    cout << "Water trapped = " << trap(arr, n);

    return 0;
}

// ANS:=
// Water trapped = 5