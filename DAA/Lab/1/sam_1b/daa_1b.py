import pandas as pd
import matplotlib.pyplot as plt

# Read the results file
file_name = "sort_results.txt"
data = pd.read_csv(file_name)

# Plot the data with a larger figure size
plt.figure(figsize=(20, 12))  # Increased width and height for a bigger plot

# Plot Insertion Sort times
plt.plot(data['Block_Size'], data['Insertion_Sort_Time(ms)'], marker='o', markersize=3, label='Insertion Sort')

# Plot Selection Sort times
plt.plot(data['Block_Size'], data['Selection_Sort_Time(ms)'], marker='o', markersize=3, label='Selection Sort')

# Customize the plot
plt.title("Comparison of Insertion Sort vs Selection Sort", fontsize=16)
plt.xlabel("Block Size", fontsize=14)
plt.ylabel("Time (ms)", fontsize=14)
plt.grid(True)
plt.legend(fontsize=12)

# Set zoomed in x and y axis limits
# Adjust these based on your data to make the plot more zoomed
plt.xlim(min(data['Block_Size']) + 10, max(data['Block_Size']) - 10)  # Narrowing the x-axis range
plt.ylim(min(data['Insertion_Sort_Time(ms)'].min(), data['Selection_Sort_Time(ms)'].min()) - 20,
         max(data['Insertion_Sort_Time(ms)'].max(), data['Selection_Sort_Time(ms)'].max()) + 20)  # Zooming into the y-axis

# Show the plot
plt.show()
