#include "Graph.h"
#include "Vertex.h"

#include <vector>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

Graph::Graph() {
    vertices.resize(0);
}

Graph::Graph(ifstream& ifs) {
    int numVertices = 0;
    int numEdges = 0;
    string vertexName;
    string a;
    string b;
    int c;
    int posa;
    int posb;
    
    if (ifs.is_open()) {
        ifs >> numVertices;
        ifs >> numEdges;
        vertices.resize(numVertices);
        
        for (int i = 0; i < numVertices; ++i) {
            ifs >> vertexName;
            Vertex* v = new Vertex();
            v->label = vertexName;
            vertices.at(i) = v;
        }
        for (int i = 0; i < numEdges; ++i) {
            ifs >> a;
            for (int j = 0; j < numVertices; ++j) {
                if (vertices.at(j)->label == a) {
                    posa = j;
                }
            }
            ifs >> b;
            for (int j = 0; j < numVertices; ++j) {
                if (vertices.at(j)->label == b) {
                    posb = j;
                }
            }
            ifs >> c;
            
            pair<int, int> vPair;
            vPair = make_pair(posb, c);
            vertices.at(posa)->neighbors.push_back(vPair);
        }
    }
    
}

Graph::~Graph() {
    
}

void Graph::output_graph(const string& filename) {
    ofstream outFS(filename.c_str());
    outFS << "digraph g {" << endl;
    for (int i = 0; i < vertices.size(); ++i) {
        outFS << "    " << vertices.at(i)->label << " [label=\"" << vertices.at(i)->label << ", " << vertices.at(i)->distance << "\"];" << endl;
    }
    for (int i = 0; i < vertices.size(); ++i) {
        list<pair<int, int> >::iterator it;
        for (it = vertices.at(i)->neighbors.begin(); it != vertices.at(i)->neighbors.end(); ++it) {
            outFS << "    " << vertices.at(i)->label << " -> " << vertices.at(it->first)->label << ";" << endl;
        }
    }
    outFS << "}";
    
    // Assuming input files are in the form "input#.txt"
    string jpgFilename = filename.substr(0, filename.size() - 3)+".jpg";
    string command = "dot -Tjpg " + filename + " -o " + jpgFilename;
    system(command.c_str());
}

void Graph::bfs() {
    
    int posu = 0;
    queue<Vertex*> qV;
    qV.push(vertices.at(0));
    vertices.at(0)->color = "GRAY";
    vertices.at(0)->distance = 0;
    
    while (!qV.empty()) {
        vector<int> posvs(0);
        Vertex* u = qV.front();
        qV.pop();
        for (unsigned j = 0; j < vertices.size(); ++j) {
            if (u->label == vertices.at(j)->label) {
                posu = j;
            }
        }
        list<pair<int, int> >:: iterator it;
        for (it = vertices.at(posu)->neighbors.begin(); it != vertices.at(posu)->neighbors.end(); ++it) {
            posvs.push_back(it->first);
        }
        for (unsigned k = 0; k < posvs.size(); ++k) {
            if (vertices.at(posvs.at(k))->color == "WHITE") {
                vertices.at(posvs.at(k))->color == "GRAY";
                vertices.at(posvs.at(k))->distance = vertices.at(posu)->distance + 1;
                vertices.at(posvs.at(k))->prev = vertices.at(posu);
                qV.push(vertices.at(posvs.at(k)));
            }
        }
        vertices.at(posu)->color = "BLACK";
    }
}