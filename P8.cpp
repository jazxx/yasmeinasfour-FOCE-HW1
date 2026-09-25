#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareByFirstElement(const vector<int>& a, const vector<int>& b) {
    if (a.empty() && b.empty()) {
        return false;
    }

    if (a.empty()) {
        return true;
    }

    if (b.empty()) {
        return false;
    }

    return a[0] < b[0];
}

vector<int> mergeKArrays(vector<vector<int>> arrays) {
    vector<int> result;

    if (arrays.empty()) {
        return result;
    }

    sort(arrays.begin(), arrays.end(), compareByFirstElement);

    for (int i = 0; i < (int)arrays.size(); i++) {
        for (int j = 0; j < (int)arrays[i].size(); j++) {
            result.push_back(arrays[i][j]);
        }
    }

    sort(result.begin(), result.end());

    return result;
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

void printArrays(vector<vector<int>> arrays) {
    cout << "[";

    for (int i = 0; i < (int)arrays.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        printVector(arrays[i]);
    }

    cout << "]";
}

int main() {
    vector<vector<vector<int>>> tests;

    vector<vector<int>> test1;
    test1.push_back({1, 4, 5});
    test1.push_back({1, 3, 4});
    test1.push_back({2, 6});
    tests.push_back(test1);

    vector<vector<int>> test2;
    test2.push_back({});
    test2.push_back({1, 3});
    test2.push_back({});
    tests.push_back(test2);

    vector<vector<int>> test3;
    test3.push_back({});
    test3.push_back({});
    tests.push_back(test3);

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printArrays(tests[i]);
        cout << endl;

        cout << "Output: ";
        printVector(mergeKArrays(tests[i]));
        cout << endl << endl;
    }

    return 0;
}
