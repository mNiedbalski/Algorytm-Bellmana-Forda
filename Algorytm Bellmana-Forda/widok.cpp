#include "widok.h"
void Load_parameters(vector <string>& params, const int& Liczba_parametrow, char* parametry[])
{
	vector <string> temp;
	for (int i = 0; i < Liczba_parametrow; i++)
		temp.push_back(string(parametry[i]));
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == "-g")
			params[0] = parametry[i + 1];
		else if (temp[i] == "-w")
			params[1] = parametry[i + 1];
		else if (temp[i] == "-o")
			params[2] = parametry[i + 1];
	}
}
void Load_graph(const string& name, Graph& _graph)
{
	int beginning, end;
	double cost;
	bool directed = true;
	ifstream plik;
	string temp;
	int sequence = 0;
	plik.open(name);

	while (plik >> temp) {

		if (sequence % 5 == 0) {

			istringstream converted(temp);
			converted >> beginning;
		}
		else if (sequence % 5 == 1) {
			if (temp == "->")
				directed = true;
			else if (temp == "-")
				directed = false;
		}
		else if (sequence % 5 == 2) {
			istringstream converted(temp);
			converted >> end;
		}
		else if (sequence % 5 == 4) {
			istringstream converted(temp);
			converted >> cost;
			addEdge_Directed(_graph, beginning, end, cost);
			if (!directed)
				addEdge_Directed(_graph, end, beginning, cost);
		}
		sequence++;
	}
}
void Load_variables(const string& name, vector <int>& variables)
{
	ifstream plik;
	plik.open(name);
	int temp;
	while (plik >> temp)
		variables.push_back(temp);
}
void DisplayGraph(const Graph& graph)
{
	for (auto Node : graph.nodes) {
		cout << "Node index: " << graph.umap_nodes.at(Node.index) << "  User index: " << Node.index << endl;
		for (auto Edge : Node.edges) {
			cout << "  " << Edge.begin << " -> " << Edge.end << " : " << Edge.cost << endl;
		}
	}
}