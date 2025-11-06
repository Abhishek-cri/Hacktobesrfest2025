#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int currentSum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++) {
        currentSum += arr[i];

        if(currentSum > maxSum)
            maxSum = currentSum;

        if(currentSum < 0)
            currentSum = 0; 
    }

    cout << "Maximum Subarray Sum is: " << maxSum << endl;
    return 0;
}
