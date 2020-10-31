# Programming Lab 5: Chromatic Number of a Graph

This assignment was based around graph theory, specifically he concepts of breadth-first search and chromatic numbers.  Using a political map of South America and an abstracted graph representing the same, we were to:

1. Generate an adjacency matrix;
2. Create a Graph class that can use this as its internal representation and perform breadth-first searching;
3. Derive a Map class which can read in the list of countries and colors, and use those to calculate the chromatic number of the graph.

## Structure

### The Adjacency Matrix

An Adjacency Matrix is a mathematical construct used to represent graphs as a matrix of booleans representing connections.  Each 1 in the matrix is a connecting edge, and each 0 is a non-connection.  To check if two arbitrary nodes, $m$ and $n$, are adjacent, we check position $(n,m)$ in the adjacency matrix; a 1 will represent a connection, and a 0 no connection.

The political map of a continent is a simple graph; countries do not connect to themselves, and borders are by nature two-way.  This simplifies the adjacency matrix considerably, and the resulting matrix is mirrored across the diagonal:
$$
\begin{bmatrix}
0& 1& 1 &1& 1& 1& 1& 0& 1& 1& 1& 1& 0\\
1 &0 &1& 0& 0& 0& 0& 0& 0& 0& 0& 0& 0&\\
1 &1 &0 &1 &0 &0 &0 &0 &0 &0 &0 &0& 0\\
1 &0 &1 &0 &1 &0 &0 &0 &0 &0 &0 &0 &0\\
1& 0& 0& 1& 0& 1& 0& 0& 0& 0& 0& 0 &0\\
1 &0& 0& 0& 1& 0& 1& 1& 0& 0& 0& 0& 0\\
1& 0& 0& 0& 0& 1& 0& 1& 1& 0& 0& 0& 1\\
0& 0& 0& 0& 0& 1& 1& 0& 0& 0& 0& 0& 0\\
1& 0& 0& 0& 0& 0& 1& 0& 0& 1& 1& 0& 1\\
1& 0& 0& 0& 0& 0& 0& 0& 1& 0& 1& 0& 0\\
1& 0& 0& 0& 0& 0& 0& 0& 1& 1& 0& 1& 1\\
1& 0& 0& 0& 0& 0& 0& 0& 0& 0& 1& 0& 0\\
0& 0& 0& 0& 0& 1& 0& 1& 0& 1& 0& 0& 0\\
\end{bmatrix}
$$

### The Graph Class

The Graph class exists to contain the Adjacency Matrix and the array of nodes which represent countries, and to enable breadth-first searching on using those structures.  Since it is a matrix of nothing but 1s and 0s, the adjacency matrix is best representing in code as a two-dimensional array of booleans.  If there is an adjacency between nodes $n$ and $m$, then the value at `adjacencies[n][m]` will be `true`, and if there is not, it will be `false`.

To maintain the order of nodes, they are stored in a parallel array which corresponds to the matrix by index.  This allows the encapsulation of Node information; each node only contains information about itself, and no pointers to other nodes.  The Graph can read the information in its aggregated nodes to structure and search, but the nodes do not know anything about each other.

The only methods in the class are loading the adjacencies and nodes, and performing the breadth-first search.  The loading is straight-forward; I used vectors as opposed to arrays to facilitate use of this class for future adaptations.  The Breadth-first searching is built to return a queue in the correct order for some other use, rather than writing out the results.  It takes one argument, that of a starting node, and then references the adjacency matrix and array of nodes to return the correct order.

### The Map Class

The Chromatic Map class inherits all of the functionality of the Graph class, and includes the necessary methods to include colors, and find the smallest number of colors that can be used to color in the graph such that no adjacent nodes are the same color.  The allowed colors can be read from a file and stored in a map, which is then used as a printable enumerator.

The largest piece of the Chromatic Map class is the calculation of the chromatic number.  I have programmed it to do this by brute force.

