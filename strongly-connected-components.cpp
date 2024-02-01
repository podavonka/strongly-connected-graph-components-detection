#include "strongly-connected-components.hpp"

#include <iostream>

graph::graph(int n) : nodes_count(n) {
    nodes.resize(n);
}

void graph::add_edge(int n1, int n2) {
    nodes[n1].push_back(n2);
}

graph graph::transpose() {
    graph g_transposed(nodes_count);

    for (int node = 0; node < nodes_count; ++node) {
        for (int neighbor : nodes[node]) {
            g_transposed.add_edge(neighbor, node);
        }
    }

    return std::move(g_transposed);
}

void graph::tarjan_algorithm_dfs(int node, int& time, std::vector<int>& index, std::vector<int>& lowlink,
                                 std::vector<bool>& in_stack, std::stack<int>& nodes_stack) {
    index[node] = lowlink[node] = ++time;

    nodes_stack.push(node);
    in_stack[node] = true;

    for (int neighbor : nodes[node]) {
        if (!index[neighbor]) {
            tarjan_algorithm_dfs(neighbor, time, index, lowlink, in_stack, nodes_stack);
            lowlink[node] = std::min(lowlink[node], lowlink[neighbor]);
        } else if (in_stack[neighbor]) {
            lowlink[node] = std::min(lowlink[node], lowlink[neighbor]);
        }
    }

    if (lowlink[node] == index[node]) {
        int component_member;
        std::cout << "Component: ";

        while (nodes_stack.top() != node) {
            component_member = nodes_stack.top();
            std::cout << component_member << " ";
            in_stack[component_member] = false;
            nodes_stack.pop();
        }

        component_member = nodes_stack.top();
        std::cout << component_member << "\n";
        in_stack[component_member] = false;
        nodes_stack.pop();
    }
}

void graph::tarjan_algorithm() {
    std::vector<int> index(nodes_count, 0);
    std::vector<int> lowlink(nodes_count, 0);
    std::vector<bool> in_stack(nodes_count, false);

    std::stack<int> nodes_stack;

    int time = 0;
    for (int node = 0; node < nodes_count; ++node) {
        if (!index[node]) {
            tarjan_algorithm_dfs(node, time, index, lowlink, in_stack, nodes_stack);
        }
    }
}

void graph::kosaraju_algorithm_dfs_transposed(int node, std::vector<State>& state) {
    state[node] = OPEN;
    std::cout << node << " ";
    for (int neighbor : nodes[node]) {
        if (state[neighbor] == UNVISITED) {
            kosaraju_algorithm_dfs_transposed(neighbor, state);
        }
    }
    state[node] = CLOSED;
}

void graph::kosaraju_algorithm_dfs(int node, std::vector<State>& state, std::stack<int>& nodes_stack) {
    state[node] = OPEN;
    for (int neighbor : nodes[node]) {
        if (state[neighbor] == UNVISITED) {
            kosaraju_algorithm_dfs(neighbor, state, nodes_stack);
        }
    }
    state[node] = CLOSED;
    nodes_stack.push(node);
}

void graph::kosaraju_algorithm() {
    std::vector<State> state(nodes_count, UNVISITED);
    std::stack<int> nodes_stack;

    for (int node = 0; node < nodes_count; ++node) {
        if (state[node] == UNVISITED) {
            kosaraju_algorithm_dfs(node, state, nodes_stack);
        }
    }

    graph g_transposed = transpose();

    std::fill(state.begin(), state.end(), UNVISITED);
    while (!nodes_stack.empty()) {
        int component_member = nodes_stack.top();
        nodes_stack.pop();

        if (state[component_member] == UNVISITED) {
            std::cout << "Component: ";
            g_transposed.kosaraju_algorithm_dfs_transposed(component_member, state);
            std::cout << "\n";
        }

    }
}
