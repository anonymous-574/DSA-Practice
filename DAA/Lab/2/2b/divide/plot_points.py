import matplotlib.pyplot as plt

# Read points from file
graph_points = []
convex_hull_points = []

# Open the file
with open('points.txt', 'r') as file:
    lines = file.readlines()
    
    # Read Graph Points (skip the header)
    graph_section = False
    for line in lines:
        line = line.strip()  # Remove leading/trailing whitespace
        if not line:  # Skip empty lines
            continue
        if line == "Graph Points:":
            graph_section = True
            continue
        elif line == "Convex Hull Points (Answer):":
            graph_section = False
            continue
        elif graph_section:
            x, y = map(int, line.split())
            graph_points.append((x, y))
        elif not graph_section:
            x, y = map(int, line.split())
            convex_hull_points.append((x, y))

# Separate x and y coordinates for plotting
graph_x, graph_y = zip(*graph_points) if graph_points else ([], [])
convex_hull_x, convex_hull_y = zip(*convex_hull_points) if convex_hull_points else ([], [])

# Plotting
plt.figure(figsize=(10, 6))

# Plot all points in graph (blue)
plt.scatter(graph_x, graph_y, color='blue', label='Graph Points')

# Plot convex hull points (red)
plt.scatter(convex_hull_x, convex_hull_y, color='red', label='Convex Hull Points')

# Connect the convex hull points with red lines
for i in range(len(convex_hull_points)):
    plt.plot([convex_hull_x[i], convex_hull_x[(i + 1) % len(convex_hull_points)]],
             [convex_hull_y[i], convex_hull_y[(i + 1) % len(convex_hull_points)]], 
             color='red')

# Labels and title
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Convex Hull and Graph Points')
plt.legend()

# Show the plot
plt.show()
