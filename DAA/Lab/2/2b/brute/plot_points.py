import matplotlib.pyplot as plt

# Read points from file
graph_points = []
convex_hull_edges = []

# Open the file
with open('points.txt', 'r') as file:
    lines = file.readlines()
    
    section = None  # Track which section we're reading

    for line in lines:
        line = line.strip()  # Remove whitespace
        if not line:  # Skip empty lines
            continue

        if line == "Graph Points:":
            section = "graph"
            continue
        elif line == "Convex Hull Edges:":
            section = "hull"
            continue
        
        if section == "graph":
            x, y = map(int, line.split())
            graph_points.append((x, y))
        elif section == "hull":
            x1, y1, x2, y2 = map(int, line.split())
            convex_hull_edges.append(((x1, y1), (x2, y2)))

# Separate x and y coordinates for graph points
graph_x, graph_y = zip(*graph_points) if graph_points else ([], [])

# Plotting
plt.figure(figsize=(10, 6))

# Plot all points in graph (blue)
plt.scatter(graph_x, graph_y, color='blue', label='Graph Points')

# Plot convex hull edges (red)
for edge in convex_hull_edges:
    (x1, y1), (x2, y2) = edge
    plt.plot([x1, x2], [y1, y2], color='red')

# Plot convex hull points explicitly in red
hull_x, hull_y = zip(*[point for edge in convex_hull_edges for point in edge])
plt.scatter(hull_x, hull_y, color='red', label='Convex Hull Points')

# Labels and title
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Convex Hull and Graph Points')
plt.legend()

# Show the plot
plt.show()
