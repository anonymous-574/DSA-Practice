import matplotlib.pyplot as plt
import pandas as pd

# Read CSV file
filename = "results.csv"
df = pd.read_csv(filename)

# Group data by pattern size (m)
grouped_data = df.groupby("m")

# Plot the graph
plt.figure(figsize=(12, 8))

for m, group in grouped_data:
    plt.plot(group["n"], group["time_ns"], marker="o", linestyle="-", label=f"m = {m}")

# Labels and legend
plt.xlabel("Text Size (n)")
plt.ylabel("Time (ns)")
plt.title("Search Algorithm Performance for Different Pattern Sizes")
plt.legend(title="Pattern Size (m)")
plt.grid(True)

# Save and display
plt.savefig("search_performance.png", dpi=300)
plt.show()