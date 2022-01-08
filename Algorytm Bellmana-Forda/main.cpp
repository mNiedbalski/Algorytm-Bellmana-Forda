#include "model.h"
#include "widok.h"
using namespace std;

int main(int argc, char* argv[])
{
	Graph graph;
	vector <string> parametry;
	vector <int> variables;
	parametry.resize(3);
	Load_parameters(parametry, argc, argv);
	Load_graph(parametry.at(0), graph);
	Load_variables(parametry.at(1),variables);
	DisplayGraph(graph); //Debugg
	cout << "\n\n";
	for (auto var : variables) {
		if (!Bellman_Ford(graph, var))
			cout << "\nWystapil ujemny cykl";
		cout << endl;
	}


}