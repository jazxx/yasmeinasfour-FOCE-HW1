#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compareFrequency(pair<int, int> x, pair<int, int> y) {
    if (x.second != y.second) {
        return x.second > y.second;
    }

    return x.first < y.first;
}

vector<int> topKFrequent(const vector<int>& a, int k) {
    if (a.empty() || k == 0)
        return {};

    unordered_map<int, int> freq;

    for (int i = 0; i < (int)a.size(); i++) {
        freq[a[i]] = freq[a[i]] + 1;
    }

    vector<pair<int, int>> pairs;

    for (pair<const int, int> item : freq) {
        pairs.push_back(make_pair(item.first, item.second));
    }

    sort(pairs.begin(), pairs.end(), compareFrequency);

    vector<int> result;

    for (int i = 0; i < k; i++) {
        result.push_back(pairs[i].first);
    }

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

int main() {
    vector<vector<int>> testNums;
    vector<int> testK;

    testNums.push_back({1, 1, 2, 2, 3});
    testK.push_back(2);

    testNums.push_back({5, 5, 5});
    testK.push_back(1);

    testNums.push_back({4, 4, 2, 2, 1});
    testK.push_back(2);

    testNums.push_back({});
    testK.push_back(0);

    for (int i = 0; i < (int)testNums.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  nums = ";
        printVector(testNums[i]);
        cout << ", k = " << testK[i] << endl;

        cout << "Output: ";
        printVector(topKFrequent(testNums[i], testK[i]));
        cout << endl << endl;
    }

    return 0;
}
