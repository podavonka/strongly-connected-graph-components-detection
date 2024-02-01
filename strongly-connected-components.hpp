#ifndef B6B36PCC_SEMESTRAL_WORK_STRONGLY_CONNECTED_COMPONENTS_HPP
#define B6B36PCC_SEMESTRAL_WORK_STRONGLY_CONNECTED_COMPONENTS_HPP

#include <vector>
#include <stack>

/**
 * State enum
 *
 * Nodes states for a graph passing while executing Kosaraju-Sharir algorithm
 */
enum State { OPEN, UNVISITED, CLOSED };

/**
 * Graph class
 *
 * Graph is given by the number of nodes and the adjacency list
 * that contains neighbors for each node
 */
class graph {
    int nodes_count;
    std::vector<std::vector<int>> nodes;

    /**
     * Returns a new graph with same nodes
     * and transposed edges in the adjacency list
     */
    graph transpose();

    /**
     * Performs depth-first search looking
     * for strongly connected components using Tarjan's algorithm
     */
    void tarjan_algorithm_dfs(int node, int& time, std::vector<int>& index, std::vector<int>& lowlink,
                              std::vector<bool>& in_stack, std::stack<int>& nodes_stack);

    /**
     * Performs depth-first search for the first pass
     * of Kosaraju-Sharir algorithm in the original graph
     */
    void kosaraju_algorithm_dfs(int node, std::vector<State>& state, std::stack<int>& nodes_stack);
protected:
    /**
     * Performs depth-first search for the second pass
     * of Kosaraju-Sharir algorithm in the transposed graph
     */
    void kosaraju_algorithm_dfs_transposed(int node, std::vector<State>& state);
public:
    /**
     * Creates graph based on the given nodes number
     */
    explicit graph(int n);

    /**
     * Adds an oriented edge from one node to another
     */
    void add_edge(int n1, int n2);

    /**
     * Looks for strongly connected components in graph
     * using Tarjan's algorithm
     */
    void tarjan_algorithm();

    /**
    * Looks for strongly connected components in graph
    * using Kosaraju-Sharir algorithm
    */
    void kosaraju_algorithm();
};

#endif //B6B36PCC_SEMESTRAL_WORK_STRONGLY_CONNECTED_COMPONENTS_HPP
