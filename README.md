# Strongly Connected Components

**Author:** Valeriia Klimova

This C++ program is designed to identify and analyze the strongly connected components (SCCs) in directed graphs. The program offers two efficient algorithms for SCC detection: Tarjan's algorithm and Kosaraju-Sharir algorithm.

## Overview

Strongly connected components are subgraphs within a directed graph where every vertex is reachable from every other vertex.

### Features

- **Tarjan's algorithm** is an advanced graph traversal algorithm developed by Robert Tarjan that efficiently identifies SCCs in linear time.
- **Kosaraju-Sharir algorithm** is a two-pass algorithm based on depth-first search and reverse graph traversal, originally proposed by Sharadchandra and S. Kosaraju.

### Complexity
- If the graph is represented as an adjacency list then both algorithms run in Θ(|V|+|E|) time.
- If the graph is represented as an adjacency matrix then both algorithms run in O(|V|^2) time.

## Measurements

The measurements were performed against the code in the 1411f729 commit, on a 4-core i7-1165G7 CPU clocked at 2.8 GHz. Input files for one of the homeworks in B4M33PAL course were taken and modified for measurements purposes. Both algorithms were tested on each of these inputs and the results documented in the following table. The data are given in milliseconds.

| Input File   | Tarjan's algorithm | Kosaraju-Sharir algorithm |
|--------------|:------------------:|:-------------------------:|
| `input00.in` |        < 1         |            < 1            |
| `input01.in` |        < 1         |            < 1            |
| `input02.in` |        < 1         |            < 1            |
| `input03.in` |        < 1         |            < 1            |
| `input04.in` |        < 1         |            < 1            |
| `input05.in` |        < 1         |            < 1            |
| `input06.in` |        < 1         |            < 1            |
| `input07.in` |        < 1         |             1             |
| `input08.in` |         47         |            84             |
| `input09.in` |        352         |            794            |
| `input10.in` |        175         |            439            |

The results are shown in the graph:

![](/measurements/algorithms_measurements.png)

For smaller graphs, both algorithms offer comparable performance. However, when dealing with large and complex graphs, choosing Tarjan's algorithm can significantly reduce computation time due to its single-pass nature.

## Usage

### Input

The first input line contains two integers separated by space: number of vertices and number of edges. All the vertices are indexed from 0 to {number of vertices}−1. Next, there are {number of edges} lines with pairs of integers p1, p2 separated by space, representing an edge from one vertex to another.

Here is an example:
```
6 8
0 1
0 2
1 2
1 3
2 1
3 5
4 3
5 4
```

Input files for testing purposes can be found in the `/input` directory.

### Execute

1. Use CMake to build the project. Navigate to the project directory and execute the following commands:
```
cmake ..
make
```
2. Execute the compiled binary with the desired options:
```
./b6b36pcc-semestral-work [option] < input/[input].in
```

### Options

The program can be executed using the following optios:

```
--help, -h       Show help message
--tarj, -t       Execute Tarjan's algorithm
--kosa, -k       Execute Kosaraju-Sharir algorithm
```
