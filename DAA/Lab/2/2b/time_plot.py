import matplotlib.pyplot as plt
import numpy as np

# Read the data from the time.txt file
num_points = []
graham_times = []
brute_times = []
dc_times = []

with open('D:/code/DSA/DAA/Lab/2/2b/time.txt', 'r', encoding="utf-8") as file:
    lines = file.readlines()
    # Skip header line
    for line in lines[1:]:
        data = line.split()
        num_points.append(int(data[0]))
        graham_times.append(float(data[1]))
        brute_times.append(float(data[2]))
        dc_times.append(float(data[3]))

# Convert to numpy arrays for convenience
num_points = np.array(num_points)
graham_times = np.array(graham_times)
brute_times = np.array(brute_times)
dc_times = np.array(dc_times)

# Plotting the times
plt.figure(figsize=(15, 6))

# Plot the times for each algorithm
plt.plot(num_points, graham_times, label='Graham Scan', color='blue', marker='o')
plt.plot(num_points, brute_times, label='Brute Force', color='red', marker='s')
plt.plot(num_points, dc_times, label='Divide and Conquer', color='green', marker='^')

plt.yscale('log')
# Adding titles and labels
plt.title('Algorithm Time Comparison')
plt.xlabel('Number of Points')
plt.ylabel('Time (ns)')
plt.legend()

# Show grid for better readability
plt.grid(True)

# Show the plot
plt.show()
