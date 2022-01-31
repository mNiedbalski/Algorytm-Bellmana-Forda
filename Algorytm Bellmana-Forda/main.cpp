#include "model.h"
#include "widok.h"
using namespace std;

int main(int argc, char* argv[])
{
	Graph graph;
	Params myParameters;
	vector <int> variables;
	if (!Load_parameters(myParameters, argc, argv))
		return -1;
	Load_graph(myParameters.graphFile, graph);
	Load_variables(myParameters.pathsFile,variables);
	DisplayGraph(graph); //Debugg
	Setup_File(myParameters.outputFile);
	cout << "\n"; //Debugg
	if (!FileCorrect(myParameters.graphFile) || !FileCorrect(myParameters.pathsFile) || !FileCorrect(myParameters.outputFile))
			return -1;
	for (auto var : variables) {
		if (!CheckVar(var,graph)) {
			PrintNotFound(myParameters.outputFile, var);
		}
		else {
			if (!Bellman_Ford(graph, var, myParameters.outputFile)) {
				PrintNegativeCycle(myParameters.outputFile);
				cerr << "W grafie wystapil cykl o ujemnej wadze, dlatego dalsza kontynuacja petli jest zbedna.\n";
				return -1;
			}
		}
	}
	

}