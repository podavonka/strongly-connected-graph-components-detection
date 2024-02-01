#include "strongly-connected-components.hpp"
#include "timer.hpp"

#include <cstdlib>
#include <iostream>

/**
 * Indicator value if an unknown
 * argument has been received
 */
#define UNKNOWN_ARG (-1)

/**
 * Prints manual if the --help argument has been given
 */
bool is_help(std::string const& arg);
int print_help(std::string const& exe);

/**
 * Inits graph and starts algorithm
 * for finding strongly connected components
 */
graph init_graph();
long long find_strongly_connected_components(std::string const& algorithm, graph g);

int main(int argc, char** argv) {
    if (argc == 1) std::clog << "No arguments have been given!\n";
    else if (argc >= 3) std::clog << "Too many arguments have been given!\n";

    if (is_help(argv[1])) return print_help(argv[0]);

    graph g = init_graph();
    long long time = find_strongly_connected_components(argv[1], g);

    if (time != UNKNOWN_ARG) std::cout << "Algorithm finished in " << time << "ms" << '\n';

    return EXIT_SUCCESS;
}

long long find_strongly_connected_components(std::string const& algorithm, graph g) {
    auto timer_start = timer::now();

    if (algorithm == "--tarj" || algorithm == "-t") {
        std::clog << "Tarjan's algorithm is executing.\n";
        g.tarjan_algorithm();
    }
    else if (algorithm == "--kosa" || algorithm == "-k") {
        std::clog << "Kosaraju-Sharir's algorithm is executing.\n";
        g.kosaraju_algorithm();
    }
    else {
        std::clog << "Unknown argument has been given!\n";
        return UNKNOWN_ARG;
    }

    auto timer_end = timer::now();

    return timer::to_ms(timer_end - timer_start);
}

graph init_graph() {
    int nodes_count, edges_count;
    std::cin >> nodes_count >> edges_count;

    graph g(nodes_count);

    for (int i = 0; i < edges_count; ++i) {
        int n1, n2;
        std::cin >> n1 >> n2;
        g.add_edge(n1, n2);
    }

    return g;
}

int print_help(std::string const& exe) {
    std::clog << "Help request has been received!\n";
    std::clog << "Usage: " + exe + " [option] < input/[input].in\n";
    std::clog << "Options:\n";
    std::clog << "  --help, -h       Show help message\n";
    std::clog << "  --tarj, -t       Execute Tarjan's algorithm\n";
    std::clog << "  --kosa, -k       Execute Kosaraju-Sharir algorithm\n";

    return EXIT_SUCCESS;
}

bool is_help(std::string const& arg) {
    return arg == "--help" || arg == "-h";
}
