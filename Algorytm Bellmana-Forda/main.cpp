#include "model.h"
#include "widok.h"
using namespace std;

int main(int argc, char* argv[])
{
	Graph graph;
	vector <string> parameters;
	vector <int> variables;
	parameters.resize(3);
	if (!Load_parameters(parameters, argc, argv))
		return -1;
	Load_graph(parameters.at(0), graph);
	Load_variables(parameters.at(1),variables);
	DisplayGraph(graph); //Debugg
	Setup_File(parameters.at(2));
	cout << "\n"; //Debugg
	for (auto fileName : parameters)
		if (!FileCorrect(fileName)) {
			return -1;
		}
	for (auto var : variables) {
		if (!CheckVar(var,graph)) {
			PrintNotFound(parameters[2], var);
		}
		else {
			if (!Bellman_Ford(graph, var, parameters[2])) {
				PrintNegativeCycle(parameters[2]);
				cerr << "W grafie wystapil cykl o ujemnej wadze, dlatego dalsza kontynuacja petli jest zbedna.\n";
				return -1;
			}
		}
	}
	

}