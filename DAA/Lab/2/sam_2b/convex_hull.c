#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Samarth Dave
// UID : 2023300039
// For c compile which doenst use chorono
#define MAX_POINTS 100

typedef struct {
    int x, y;
} Point;

// Stack structure for Graham's Scan
typedef struct {
    Point points[MAX_POINTS];
    int top;
} Stack;

// Stack operations
void push(Stack *s, Point p) {
    s->points[++(s->top)] = p;
}

void pop(Stack *s) {
    if (s->top >= 0) s->top--;
}

Point top(Stack *s) {
    return s->points[s->top];
}

Point nextToTop(Stack *s) {
    return s->points[s->top - 1];
}

// Function to swap two points
void swap(Point *a, Point *b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find orientation
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : -1;  // Clockwise or Counterclockwise
}

// Comparator function to sort points by x-coordinates
int compareX(const void *p1, const void *p2) {
    return ((Point *)p1)->x - ((Point *)p2)->x;
}

// Function to generate random points
void generateRandomPoints(Point points[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 100 + 1;
        points[i].y = rand() % 100 + 1;
    }
}

// *** BRUTE FORCE CONVEX HULL ***
void bruteForceConvexHull(Point points[], int n, FILE *file) {
    fprintf(file, "Brute Force Convex Hull:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int left = 0, right = 0;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    int o = orientation(points[i], points[j], points[k]);
                    if (o == -1) left++;
                    else if (o == 1) right++;
                }
            }
            if (left == 0 || right == 0) {
                fprintf(file, "(%d, %d)\n", points[i].x, points[i].y);
                fprintf(file, "(%d, %d)\n", points[j].x, points[j].y);
            }
        }
    }
}

// *** GRAHAM'S SCAN CONVEX HULL ***
void grahamScanConvexHull(Point points[], int n, FILE *file) {
    fprintf(file, "Graham's Scan Convex Hull:\n");

    int minY = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[minY].y || 
            (points[i].y == points[minY].y && points[i].x < points[minY].x)) {
            minY = i;
        }
    }
    swap(&points[0], &points[minY]);

    Stack hull;
    hull.top = -1;
    push(&hull, points[0]);
    push(&hull, points[1]);
    push(&hull, points[2]);

    for (int i = 3; i < n; i++) {
        while (hull.top >= 1 && orientation(nextToTop(&hull), top(&hull), points[i]) != -1)
            pop(&hull);
        push(&hull, points[i]);
    }

    for (int i = 0; i <= hull.top; i++) {
        fprintf(file, "(%d, %d)\n", hull.points[i].x, hull.points[i].y);
    }
}

// *** DIVIDE AND CONQUER CONVEX HULL ***
Point* mergeHulls(Point left[], int leftSize, Point right[], int rightSize, int *mergedSize) {
    Point *merged = (Point *)malloc((leftSize + rightSize) * sizeof(Point));
    int i = 0, j = 0, k = 0;

    while (i < leftSize) merged[k++] = left[i++];
    while (j < rightSize) merged[k++] = right[j++];

    *mergedSize = k;
    return merged;
}

Point* divideAndConquer(Point points[], int n, int *hullSize) {
    if (n <= 3) {
        *hullSize = n;
        return points;
    }

    int mid = n / 2;
    Point *leftHull, *rightHull;
    int leftSize, rightSize;

    leftHull = divideAndConquer(points, mid, &leftSize);
    rightHull = divideAndConquer(points + mid, n - mid, &rightSize);

    return mergeHulls(leftHull, leftSize, rightHull, rightSize, hullSize);
}

void computeConvexHull(Point points[], int n, FILE *file) {
    qsort(points, n, sizeof(Point), compareX);

    int hullSize;
    Point *hull = divideAndConquer(points, n, &hullSize);

    fprintf(file, "Divide and Conquer Convex Hull:\n");
    for (int i = 0; i < hullSize; i++) {
        fprintf(file, "(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

// *** MAIN FUNCTION ***
int main() {
    Point points[MAX_POINTS];
    generateRandomPoints(points, MAX_POINTS);

    FILE *bfFile = fopen("brute_force_output.txt", "w");
    FILE *gsFile = fopen("graham_scan_output.txt", "w");
    FILE *dcFile = fopen("divide_conquer_output.txt", "w");

    FILE *timeFile = fopen("execution_time.txt", "w");
    fprintf(timeFile, "Points, BruteForce (ms), GrahamScan (ms), DivideConquer (ms)\n");

    for (int n = 4; n <= MAX_POINTS; n += 4) {
        Point temp[MAX_POINTS];
        for (int i = 0; i < n; i++) temp[i] = points[i];

        Point temp1[MAX_POINTS];
        for (int i = 0; i < n; i++) temp1[i] = points[i];

        Point temp2[MAX_POINTS];
        for (int i = 0; i < n; i++) temp2[i] = points[i];

        clock_t start, end;
        double timeBrute, timeGraham, timeDC;

        start = clock();
        bruteForceConvexHull(temp, n, bfFile);
        end = clock();
        timeBrute = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        start = clock();
        grahamScanConvexHull(temp1, n, gsFile);
        end = clock();
        timeGraham = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        start = clock();
        computeConvexHull(temp2, n, dcFile);
        end = clock();
        timeDC = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        fprintf(timeFile, "%d, %.2f, %.2f, %.2f\n", n, timeBrute, timeGraham, timeDC);
    }

    fclose(bfFile);
    fclose(gsFile);
    fclose(dcFile);
    fclose(timeFile);

    printf("Output and execution time recorded in files.\n");
    return 0;
}
