#include <iostream>
#include <vector>
using namespace std;

long long mergeAndCount(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;
    int i = low;
    int j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
            count = count + (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= high) {
        temp.push_back(a[j]);
        j++;
    }

    for (int t = 0; t < (int)temp.size(); t++) {
        a[low + t] = temp[t];
    }

    return count;
}

long long mergeCount(vector<int>& a, int low, int high) {
    if (low >= high) {
        return 0;
    }

    int mid = low + (high - low) / 2;

    long long count = 0;
    count = count + mergeCount(a, low, mid);
    count = count + mergeCount(a, mid + 1, high);
    count = count + mergeAndCount(a, low, mid, high);

    return count;
}

long long countInversions(vector<int> a) {
    if (a.empty()) {
        return 0;
    }

    return mergeCount(a, 0, (int)a.size() - 1);
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
    tests.push_back({2, 4, 1, 3, 5});
    tests.push_back({1, 2, 3, 4, 5});
    tests.push_back({5, 4, 3, 2, 1});
    tests.push_back({2, 2, 1});

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  ";
        printVector(tests[i]);
        cout << endl;

        cout << "Output: " << countInversions(tests[i]) << endl << endl;
    }

    return 0;
}
