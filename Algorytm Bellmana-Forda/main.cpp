#include "model.h"
#include "widok.h"
using namespace std;

int main(int argc, char* argv[])
{
	Graph graph;
	vector <string> parametry;
	parametry.resize(3);
	Load_parameters(parametry, argc, argv);
	Load_graph(parametry.at(0), graph);
	DisplayGraph(graph); //Debugg
	
	/* // Debugg check czy dobrze zamapowano 
	for (auto iter : graph.umap_nodes)
		cout << iter.first << " = " << iter.second << endl;
	cout << "\nREVERSED:\n";
	for (auto iter : graph.umap_nodes_reversed)
		cout << iter.first << " = " << iter.second << endl;
	*/
	
	//
}