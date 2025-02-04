import matplotlib.pyplot as plt

with open("merge.txt", "r") as file:
    insert_times = [float(line.strip()) for line in file]

with open("quick.txt", "r") as file:
    select_times = [float(line.strip()) for line in file]

batches = list(range(1, len(insert_times) + 1))

plt.figure(figsize=(15, 6))
plt.plot(batches, insert_times, label="Merge Sort", color="blue", marker='o')
plt.plot(batches, select_times, label="Quick Sort", color="orange", marker='x')

plt.title("Comparison of Sorting Times", fontsize=14)
plt.xlabel("Batch Number", fontsize=12)
plt.ylabel("Time Taken (ms)", fontsize=12)
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()