#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& a) {
    int count[3] = {0, 0, 0};

    for (int i = 0; i < (int)a.size(); i++) {
        count[a[i]] = count[a[i]] + 1;
    }

    int index = 0;

    for (int color = 0; color < 3; color++) {
        for (int j = 0; j < count[color]; j++) {
            a[index] = color;
            index++;
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
        countingSort(a);

        cout << "Output: ";
        printVector(a);
        cout << endl << endl;
    }

    return 0;
}
