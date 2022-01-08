#include "model.h"
#include "widok.h"
using namespace std;

int main(int argc, char* argv[])
{
	Graph graph;
	vector <string> parametry;
	vector <int> zmienne;
	parametry.resize(3);
	Load_parameters(parametry, argc, argv);
	Load_graph(parametry.at(0), graph);
	Load_variables(parametry.at(1),zmienne);
	DisplayGraph(graph); //Debugg
	cout << "\n\n";
	if (!Bellman_Ford(graph, 1))
		cout << "\nWystapil ujemny cykl";

}