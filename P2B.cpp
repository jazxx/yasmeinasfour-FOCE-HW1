#include <iostream>
#include <vector>
using namespace std;

void dutchFlag(vector<int>& a) {
    int low = 0;
    int mid = 0;
    int high = (int)a.size() - 1;

    while (mid <= high) {
        if (a[mid] == 0) {
            int temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            int temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;
            high--;
        }
    }
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
    vector<vector<int>> tests;
    tests.push_back({2, 0, 2, 1, 1, 0});
    tests.push_back({0, 0, 1, 2, 2});
    tests.push_back({});

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printVector(tests[i]);
        cout << endl;

        vector<int> a = tests[i];
        dutchFlag(a);

        cout << "Output: ";
        printVector(a);
        cout << endl << endl;
    }

    return 0;
}
