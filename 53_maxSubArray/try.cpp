#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> vec;
    int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int tempSum, maxSum, tempSumIter;

    for (int i = 0; i < 9; i++) {
        vec.push_back(a[i]);
    }

    cout << "The vector is: " << endl;
    maxSum = tempSum = vec[0];
    for (int j = 1; j < int(vec.size()); j++) {
        // cout << vec[j] << endl;
        tempSumIter = tempSum + vec[j];
        if (vec[j] < tempSumIter) {
            tempSum = tempSumIter;
        }
        else {
            tempSum = vec[j];
        }
        
        if (tempSum > maxSum) {
            maxSum = tempSum;
        }
        cout << vec[j] << " The max sum is: " << maxSum << " The temp sum is: " << tempSum << endl;
    }

    cout << "The max sum is: " << maxSum << endl;

    return 0;

}