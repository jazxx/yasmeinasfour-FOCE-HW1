#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int kthLargest(const vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < (int)a.size(); i++) {
        heap.push(a[i]);

        if ((int)heap.size() > k) {
            heap.pop();
        }
    }

    return heap.top();
}

void printVector(vector<int> a) {
    cout << "[";

    for (int i = 0; i < (int)a.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << a[i];
    }

    cout << "]";
}

int main() {
    vector<vector<int>> testNums;
    vector<int> testK;

    testNums.push_back({1, 3, 9, 8, 7, 10, 13, 12});
    testK.push_back(2);

    testNums.push_back({5, 5, 4, 3});
    testK.push_back(2);

    testNums.push_back({7});
    testK.push_back(1);

    for (int i = 0; i < (int)testNums.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  nums = ";
        printVector(testNums[i]);
        cout << ", k = " << testK[i] << endl;

        cout << "Output: " << kthLargest(testNums[i], testK[i]) << endl << endl;
    }

    return 0;
}
