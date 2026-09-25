#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long squaredDistance(const vector<int>& p) {
    long long x = p[0];
    long long y = p[1];

    return x * x + y * y;
}

bool compareByDistance(const vector<int>& a, const vector<int>& b) {
    return squaredDistance(a) < squaredDistance(b);
}

vector<vector<int>> kClosestSort(vector<vector<int>> points, int k) {
    sort(points.begin(), points.end(), compareByDistance);

    vector<vector<int>> result;

    for (int i = 0; i < k; i++) {
        result.push_back(points[i]);
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
        printPoints(kClosestSort(testPoints[i], testK[i]));
        cout << endl << endl;
    }

    return 0;
}
