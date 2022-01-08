#include "model.h"
#include "widok.h"
using namespace std;

int main(int argc, char* argv[])
{
	Graph graph;
	vector <string> parameters;
	vector <int> variables;
	parameters.resize(3);
	Load_parameters(parameters, argc, argv);
	Load_graph(parameters.at(0), graph);
	Load_variables(parameters.at(1),variables);
	DisplayGraph(graph); //Debugg
	Setup_File(parameters.at(2));
	cout << "\n\n";
	for (auto var : variables) {
		if (!Bellman_Ford(graph, var, parameters[2]))
			cout << "\nWystapil ujemny cykl dla wierzcholka: " << var; //Debugg
		cout << endl; //Debugg
	}
	

}