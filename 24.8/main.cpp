#include <cstring>
#include "Graph.h"
using namespace std;

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        cerr << "Usage error: expected <executable> <input>" << endl;
        exit(1);
    }
    
    ifstream ifs(argv[1]);
    if (!ifs) {
        cerr << "Input file not found." << endl;
        exit(1);
    }
    
    Graph g(ifs);
    ifs.close();
    g.bfs();
    // Assuming input files are in the form "input#.txt"
    string name = argv[1];
    string filename = name.substr(0, name.size() - 3);
    filename.append("dot");
    g.output_graph(filename);
    cout << "The End." << endl;
    
    return 0;
}