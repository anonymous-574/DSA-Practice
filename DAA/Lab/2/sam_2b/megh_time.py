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
plt.grid(True, which="both", ls="-", alpha=0.2)

# Adjust layout
plt.tight_layout()

# Show the plot
plt.show()