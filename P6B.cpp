#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long squaredDistance(const vector<int>& p) {
    long long x = p[0];
    long long y = p[1];

    return x * x + y * y;
}

vector<vector<int>> kClosestHeap(const vector<vector<int>>& points, int k) {
    priority_queue<pair<long long, int>> heap;

    for (int i = 0; i < (int)points.size(); i++) {
        long long distance = squaredDistance(points[i]);
        heap.push(make_pair(distance, i));

        if ((int)heap.size() > k) {
            heap.pop();
        }
    }

    vector<vector<int>> result;

    while (!heap.empty()) {
        pair<long long, int> top = heap.top();
        int index = top.second;

        result.push_back(points[index]);
        heap.pop();
    }

    return result;
}

void printPoints(vector<vector<int>> points) {
    cout << "[";

    for (int i = 0; i < (int)points.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << "[" << points[i][0] << "," << points[i][1] << "]";
    }

    cout << "]";
}

int main() {
    vector<vector<vector<int>>> testPoints;
    vector<int> testK;

    testPoints.push_back({{1, 3}, {-2, 2}, {2, 4}});
    testK.push_back(2);

    testPoints.push_back({{3, 4}});
    testK.push_back(1);

    testPoints.push_back({{1, 2}, {3, 4}});
    testK.push_back(0);

    for (int i = 0; i < (int)testPoints.size(); i++) {
        cout << "Test " << i + 1 << ":" << endl;

        cout << "Input:  points = ";
        printPoints(testPoints[i]);
        cout << ", k = " << testK[i] << endl;

        cout << "Output: ";
        printPoints(kClosestHeap(testPoints[i], testK[i]));
        cout << endl << endl;
    }

    return 0;
}
