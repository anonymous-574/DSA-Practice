/*
Megh Doshi
Exp 2B
Div A Batch C
2023300052
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator<(const Point& p) const { 
        return x < p.x || (x == p.x && y < p.y); 
    }
    bool operator==(const Point& p) const { 
        return x == p.x && y == p.y; 
    }
};

inline int orientation(const Point& p1, const Point& p2, const Point& p3) {
    long long val = (long long)(p2.y - p1.y) * (p3.x - p2.x) -
                   (long long)(p3.y - p2.y) * (p2.x - p1.x);
    return (val == 0) ? 0 : (val > 0 ? 1 : -1);
}

vector<Point> bruteForceHull(vector<Point>& points) {
    vector<Point> hull;
    int n = points.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = points[j].y - points[i].y;
            int b = points[i].x - points[j].x;
            int c = a * points[i].x + b * points[i].y;
            int pos = 0, neg = 0;

            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    int side = a * points[k].x + b * points[k].y - c;
                    if (side > 0) pos++;
                    if (side < 0) neg++;
                }
            }
            if (pos == 0 || neg == 0) {
                hull.push_back(points[i]);
                hull.push_back(points[j]);
            }
        }
    }
    sort(hull.begin(), hull.end());
    hull.erase(unique(hull.begin(), hull.end()), hull.end());
    return hull;
}

vector<Point> mergeHulls(vector<Point>& hull1, vector<Point>& hull2) {
    if (hull1.empty()) return hull2;
    if (hull2.empty()) return hull1;

    // Find the rightmost point of hull1
    int rightMost = 0;
    for (int i = 1; i < hull1.size(); i++) {
        if (hull1[i].x > hull1[rightMost].x)
            rightMost = i;
    }

    // Find the leftmost point of hull2
    int leftMost = 0;
    for (int i = 1; i < hull2.size(); i++) {
        if (hull2[i].x < hull2[leftMost].x)
            leftMost = i;
    }

    vector<Point> mergedHull;
    
    // Find upper tangent
    int upperA = rightMost;
    int upperB = leftMost;
    bool upperFound = false;
    
    while (!upperFound) {
        upperFound = true;
        
        // Move counterclockwise on hull1 while it improves the tangent
        while (orientation(hull2[upperB], hull1[upperA], 
               hull1[(upperA + 1) % hull1.size()]) > 0) {
            upperA = (upperA + 1) % hull1.size();
        }
        
        // Move clockwise on hull2 while it improves the tangent
        while (orientation(hull1[upperA], hull2[upperB], 
               hull2[(upperB + hull2.size() - 1) % hull2.size()]) < 0) {
            upperB = (upperB + hull2.size() - 1) % hull2.size();
            upperFound = false;
        }
    }
    
    // Find lower tangent
    int lowerA = rightMost;
    int lowerB = leftMost;
    bool lowerFound = false;
    
    while (!lowerFound) {
        lowerFound = true;
        
        // Move clockwise on hull1 while it improves the tangent
        while (orientation(hull2[lowerB], hull1[lowerA], 
               hull1[(lowerA + hull1.size() - 1) % hull1.size()]) < 0) {
            lowerA = (lowerA + hull1.size() - 1) % hull1.size();
        }
        
        // Move counterclockwise on hull2 while it improves the tangent
        while (orientation(hull1[lowerA], hull2[lowerB], 
               hull2[(lowerB + 1) % hull2.size()]) > 0) {
            lowerB = (lowerB + 1) % hull2.size();
            lowerFound = false;
        }
    }
    
    // Construct the merged hull
    int i = upperA;
    mergedHull.push_back(hull1[upperA]);
    while (i != lowerA) {
        i = (i + 1) % hull1.size();
        mergedHull.push_back(hull1[i]);
    }
    
    i = lowerB;
    mergedHull.push_back(hull2[lowerB]);
    while (i != upperB) {
        i = (i + 1) % hull2.size();
        mergedHull.push_back(hull2[i]);
    }
    
    return mergedHull;
}

vector<Point> divideConquerHull(vector<Point>& points) {
    if (points.size() <= 5)
        return bruteForceHull(points);

    vector<Point> left(points.begin(), points.begin() + points.size()/2);
    vector<Point> right(points.begin() + points.size()/2, points.end());

    vector<Point> leftHull = divideConquerHull(left);
    vector<Point> rightHull = divideConquerHull(right);

    return mergeHulls(leftHull, rightHull);
}

vector<Point> grahamScan(vector<Point>& points) {
    if (points.size() < 3) return points;
    
    sort(points.begin(), points.end());
    vector<Point> hull;
    
    for (const auto& p : points) {
        while (hull.size() >= 2 && 
               orientation(hull[hull.size()-2], hull.back(), p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }
    
    size_t t = hull.size();
    for (int i = points.size()-2; i >= 0; i--) {
        while (hull.size() >= t && 
               orientation(hull[hull.size()-2], hull.back(), points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }
    
    hull.pop_back();
    return hull;
}

template<typename Func>
double measureTime(Func f, vector<Point>& points, int iterations = 100) {
    double totalTime = 0;
    for(int i = 0; i < iterations; i++) {
        vector<Point> points_copy = points;
        auto start = high_resolution_clock::now();
        f(points_copy);
        auto end = high_resolution_clock::now();
        totalTime += duration_cast<microseconds>(end - start).count();
    }
    return totalTime / iterations;  // Return average time in microseconds
}

vector<Point> generateRandomPoints(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);
    
    vector<Point> points;
    points.reserve(n);
    for (int i = 0; i < n; ++i) {
        points.emplace_back(dis(gen), dis(gen));
    }
    return points;
}

void writePointsToFile(const string& filename, 
                      const vector<Point>& original,
                      const vector<Point>& hull) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file << "Original Points:\n";
    for (const auto& p : original) {
        file << p.x << " " << p.y << "\n";
    }

    file << "\nConvex Hull:\n";
    for (const auto& p : hull) {
        file << p.x << " " << p.y << "\n";
    }
}

void performTimingAnalysis(const string& filename, 
                          const vector<Point>& points) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file << fixed << setprecision(2);
    file << "Points BruteForce(us) DivideConquer(us) GrahamScan(us)\n";
    
    for (int n = 4; n <= 100; n++) {
        vector<Point> samplePoints(points.begin(), points.begin() + n);
        
        double timeBF = measureTime(bruteForceHull, samplePoints);
        double timeDC = measureTime(divideConquerHull, samplePoints);
        double timeGS = measureTime(grahamScan, samplePoints);

        file << n << " " << timeBF << " " << timeDC << " " << timeGS << "\n";
    }
}

int main() {
    const int NUM_POINTS = 100;
    
    try {
        vector<Point> points = generateRandomPoints(NUM_POINTS);
        vector<Point> hull = grahamScan(points);
        
        writePointsToFile("points.txt", points, hull);
        performTimingAnalysis("timing.txt", points);
        
        cout << "Convex hull written to points.txt\n"
             << "Timing results written to timing.txt\n"
             << "Use timing.txt to plot complexity comparisons\n";
             
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
/*
Python code to display the hull
import matplotlib.pyplot as plt

# Original points
original_points = [
    (0, 53), (0, 85), (1, 97), (3, 24), (6, 50), (7, 25), (9, 33), (12, 62),
    (13, 19), (13, 84), (14, 45), (14, 85), (17, 40), (18, 13), (20, 13),
    (21, 26), (22, 17), (22, 34), (28, 56), (32, 45), (33, 48), (33, 58),
    (33, 77), (34, 6), (34, 34), (34, 35), (35, 5), (35, 90), (36, 42),
    (37, 99), (39, 42), (40, 35), (41, 1), (44, 81), (45, 26), (45, 33),
    (45, 41), (46, 58), (46, 96), (49, 9), (49, 30), (50, 28), (51, 55),
    (52, 88), (53, 32), (54, 15), (55, 71), (57, 92), (58, 34), (58, 63),
    (59, 56), (60, 0), (60, 77), (61, 16), (63, 56), (65, 28), (66, 17),
    (67, 70), (69, 41), (70, 0), (72, 48), (73, 46), (73, 56), (73, 89),
    (74, 2), (74, 84), (75, 100), (76, 50), (76, 70), (77, 7), (77, 11),
    (77, 48), (77, 65), (78, 32), (78, 66), (79, 15), (79, 20), (79, 70),
    (80, 38), (83, 67), (84, 14), (84, 49), (84, 71), (86, 43), (88, 42),
    (88, 94), (89, 6), (89, 20), (89, 96), (89, 98), (91, 84), (92, 35),
    (92, 67), (93, 1), (93, 17), (93, 85), (96, 99), (98, 58), (98, 96),
    (99, 44)
]

# Convex hull points (in order)
convex_hull = [
    (0, 53), (0, 85), (1, 97), (37, 99), (75, 100), (96, 99), (98, 96),
    (98, 58), (93, 1), (70, 0), (60, 0), (41, 1), (18, 13), (3, 24)
]

# Create a new figure with a specified size
plt.figure(figsize=(10, 8))

# Scatter plot for original points
x_orig, y_orig = zip(*original_points)
plt.scatter(x_orig, y_orig, color='blue', s=30, alpha=0.6, label='Original Points')

# Plot convex hull
x_hull, y_hull = zip(*(convex_hull + [convex_hull[0]]))  # Adding first point to close the hull
plt.plot(x_hull, y_hull, 'r-', linewidth=2, label='Convex Hull')
plt.scatter(x_hull, y_hull, color='red', s=50, zorder=5)  # Highlight hull vertices

# Labels and legend
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Convex Hull Visualization')
plt.legend()
plt.grid(True, alpha=0.3)

# Set axis limits with a small margin
margin = 2
plt.xlim(min(x_orig) - margin, max(x_orig) + margin)
plt.ylim(min(y_orig) - margin, max(y_orig) + margin)

# Make the plot aspect ratio equal
plt.axis('equal')

# Show plot
plt.show()
*/

/*
Python code to display the graph
import matplotlib.pyplot as plt
import numpy as np

# Data processing function to clean up zeros and outliers
def clean_data(points, values, window_size=3):
    # Replace zeros with neighboring averages
    cleaned = np.array(values, dtype=float)
    for i in range(len(cleaned)):
        if cleaned[i] == 0:
            # Find nearest non-zero values
            left = i - 1
            right = i + 1
            while left >= 0 and cleaned[left] == 0:
                left -= 1
            while right < len(cleaned) and cleaned[right] == 0:
                right += 1
                
            # Calculate replacement value
            if left >= 0 and right < len(cleaned):
                cleaned[i] = (cleaned[left] + cleaned[right]) / 2
            elif left >= 0:
                cleaned[i] = cleaned[left]
            elif right < len(cleaned):
                cleaned[i] = cleaned[right]
            else:
                cleaned[i] = np.mean([x for x in cleaned if x > 0])
    
    # Apply moving average to smooth out spikes
    smoothed = np.zeros_like(cleaned)
    for i in range(len(cleaned)):
        start = max(0, i - window_size//2)
        end = min(len(cleaned), i + window_size//2 + 1)
        smoothed[i] = np.mean(cleaned[start:end])
    
    return smoothed

# Original data
data = '''Points BruteForce(us) DivideConquer(us) GrahamScan(us)
4 0.00 0.00 0.00
5 0.00 0.00 0.00
6 0.00 0.00 0.00
7 0.00 157.59 0.00
8 0.00 0.00 0.00
9 0.00 0.00 0.00
10 0.00 0.00 0.00
11 0.00 0.00 0.00
12 91.13 0.00 20.06
13 0.00 20.03 0.00
14 30.05 0.00 20.04
15 0.00 20.03 20.03
16 20.02 20.03 0.00
17 20.05 20.02 17.44
18 20.07 20.03 0.00
19 40.06 20.02 0.00
20 40.06 17.44 20.04
21 40.06 20.03 0.00
22 57.49 0.00 20.03
23 60.09 20.03 20.02
24 52.52 40.05 0.00
25 80.11 40.06 0.00
26 100.14 37.49 0.00
27 80.12 37.46 20.05
28 100.15 37.46 0.00
29 120.17 57.53 20.03
30 100.33 0.00 70.63
31 150.71 20.03 20.03
32 157.65 40.06 0.00
33 195.36 40.06 20.03
34 177.66 37.47 20.04
35 260.64 57.53 0.00
36 318.06 138.14 20.10
37 491.06 80.19 37.64
38 398.63 57.58 0.00
39 296.61 158.12 0.00
40 470.43 0.00 0.00
41 637.95 0.00 0.00
42 474.31 0.00 0.00
43 636.07 0.00 0.00
44 794.13 0.00 0.00
45 612.44 128.72 52.20
46 788.75 85.13 0.00
47 527.49 156.51 0.00
48 1124.84 138.06 20.10
49 811.93 157.95 20.05
50 1049.44 95.38 40.08
51 929.27 0.00 159.76
52 1025.78 97.69 0.00
53 1303.81 119.59 20.08
54 1095.52 179.76 40.32
55 1343.08 178.06 40.10
56 1314.31 158.96 0.00
57 1414.92 0.00 160.71
58 1426.44 220.28 20.05
59 1319.28 0.00 0.00
60 1449.07 218.22 40.22
61 2085.66 0.00 0.00
62 1663.41 60.10 17.45
63 1139.60 239.13 20.02
64 1948.57 137.72 0.00
65 2668.35 138.18 20.05
66 2133.99 168.59 60.21
67 2859.70 236.20 60.25
68 3407.06 186.43 40.11
69 3572.08 192.15 40.18
70 3043.88 80.18 0.00
71 2553.87 117.62 0.00
72 2744.30 120.32 37.53
73 2850.14'''

# Parse data
lines = data.strip().split('\n')[1:]
points = []
brute_force = []
divide_conquer = []
graham_scan = []

for line in lines:
    if len(line.split()) >= 4:
        p, bf, dc, gs = map(float, line.split())
        points.append(p)
        brute_force.append(bf)
        divide_conquer.append(dc)
        graham_scan.append(gs)

# Clean and smooth the data
cleaned_bf = clean_data(points, brute_force, window_size=5)
cleaned_dc = clean_data(points, divide_conquer, window_size=5)
cleaned_gs = clean_data(points, graham_scan, window_size=5)

# Create the plot
plt.figure(figsize=(12, 8))

# Plot cleaned data
plt.plot(points, cleaned_bf, 'r-', label='Brute Force', linewidth=2)
plt.plot(points, cleaned_dc, 'g-', label='Divide & Conquer', linewidth=2)
plt.plot(points, cleaned_gs, 'b-', label='Graham Scan', linewidth=2)

# Customize the plot
plt.title('Algorithm Time Complexity Comparison (Cleaned Data)', fontsize=14)
plt.xlabel('Number of Points', fontsize=12)
plt.ylabel('Time (microseconds)', fontsize=12)
plt.grid(True, alpha=0.3)
plt.legend(fontsize=10)

# Use logarithmic scale for y-axis
plt.yscale('log')
plt.ylim(bottom=1)  # Set minimum y value to 1 for better visualization

# Add gridlines
plt.grid(True, which="both", ls="-", alpha=0.2)d

# Adjust layout
plt.tight_layout()

# Show the plot
plt.show()
*/