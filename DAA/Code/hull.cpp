#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    // Cross product
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

//return based on x coordinate , else y coordinate
bool comparePoints(const Point& a, const Point& b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

// Monotone Chain Convex Hull (used in merge)
vector<Point> mergeHulls(Point pts[], int n) {
    sort(pts, pts + n, comparePoints);
    vector<Point> hull;

    // Lower hull
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && orientation(hull[hull.size()-2], hull[hull.size()-1], pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }

    // Upper hull
    int lowerSize = hull.size();
    for (int i = n - 2; i >= 0; --i) {
        while ((int)hull.size() > lowerSize && orientation(hull[hull.size()-2], hull[hull.size()-1], pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }

    if (!hull.empty()) hull.pop_back(); // Remove duplicate last point
    return hull;
}

vector<Point> divideAndConquer(Point points[], int n) {
    if (n <= 3) {
        return mergeHulls(points, n);
    }

    int mid = n / 2;

    vector<Point> leftHull = divideAndConquer(points, mid);
    vector<Point> rightHull = divideAndConquer(points + mid, n - mid);

    // Combine both hulls into one array
    vector<Point> combined = leftHull;
    for (int i = 0; i < rightHull.size(); ++i) {
        combined.push_back(rightHull[i]);
    }

    return mergeHulls(combined.data(), (int)combined.size());
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    Point* points = new Point[n];
    cout << "Enter points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points, points + n, comparePoints);

    vector<Point> convexHull = divideAndConquer(points, n);

    cout << "Divide and Conquer Convex Hull:\n";
    for (int i = 0; i < convexHull.size(); ++i) {
        cout << "(" << convexHull[i].x << ", " << convexHull[i].y << ")\n";
    }

    return 0;
}
