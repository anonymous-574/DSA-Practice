import matplotlib.pyplot as plt
import os

filename = r"D:/code/DSA/DAA/Lab/4/time.txt"
vertices = []
prim_times = []
kruskal_times = []

with open(filename, "r") as file:
    next(file)  
    for line in file:
        parts = line.strip().split(", ")
        if len(parts) == 3:
            vertices.append(int(parts[0]))
            prim_times.append(int(parts[1]))
            kruskal_times.append(int(parts[2]))

if not vertices:
    print("Error: No valid data found in time.txt.")
    exit()

plt.figure(figsize=(8, 5))
plt.plot(vertices, prim_times, marker='o', linestyle='-', color='b', label="Prim's Algorithm")
plt.plot(vertices, kruskal_times, marker='s', linestyle='--', color='r', label="Kruskal's Algorithm")

plt.xlabel("Number of Vertices")
plt.ylabel("Execution Time (nanoseconds)")
plt.title("Execution Time of Prim's and Kruskal's Algorithms")
plt.legend()
plt.grid(True)

plot_filename = "execution_time_plot.png"
plt.savefig(plot_filename)
print(f"Plot saved as {plot_filename}")

plt.show()
