#include "model.h"
using namespace std;
void Load_parameters(vector <string>& params, const int & Liczba_parametrow, char* parametry[])
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
int Find(const Graph& graph, const int & index, bool & _found)
{
		if (graph.umap_nodes.find(index) != graph.umap_nodes.end()) {
			_found = true;
			return graph.umap_nodes.at(index);
		}
}
void addEdge_Directed(Graph& graph, const int begin, const int end, const int cost) //Skierowane
{ 
	bool found_beginning = false;
	bool found_end = false;
	Edge newEdge;
	newEdge.begin = begin;
	newEdge.end = end;
	newEdge.cost = cost;
	int where = Find(graph, newEdge.begin, found_beginning);
	Find(graph, newEdge.end, found_end);
	if (found_beginning) {
		graph.nodes[where].edges.push_back(newEdge);
	}
	else {
		Node newNode;
		newNode.index = begin;
		graph.umap_nodes[begin] = graph.nodes.size();
		graph.umap_nodes_reversed[graph.nodes.size()] = begin;
		newNode.edges.push_back(newEdge);
		graph.nodes.push_back(newNode);

	}
	if (!found_end) {
		Node newNode;
		newNode.index = end;
		graph.umap_nodes[end] = graph.nodes.size();
		graph.umap_nodes_reversed[graph.nodes.size()] = end;
		graph.nodes.push_back(newNode);

	}
}
void Bellman_Ford(Graph& graph, const int index)
{

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
























/*void dodajWierzcholek(Graf& _graf, int numer, int waga)
{
	Wierzcholek Node;
	Node.parametry = make_pair(numer, waga);
	list <Wierzcholek> tempLista;
	tempLista.push_back(Node);
	bool wstawiono = false;
	if (_graf.wierzcholki.size() == 0) {
		_graf.wierzcholki.push_back(tempLista);
		return;
	}
	auto iter = _graf.wierzcholki.begin();
	for (auto wierzcholek : _graf.wierzcholki){
		if (Node.parametry.first <= wierzcholek.begin()->parametry.first) {
			_graf.wierzcholki.insert(iter, tempLista);
			wstawiono = true;
			break;
		}
		else
			iter++;
	}
	if (!wstawiono)
		_graf.wierzcholki.push_back(tempLista);
}
void UzupelnijKrawedzie(Graf& _graf)
{

}
void WyswietlGraf(const Graf& _graf)
{
	int counter = 0;
	for (int i = 0; i < _graf.wierzcholki.size();i++) {
		counter = 0;
		cout << "Polaczenia wierzcholka numer " << i <<  ". (" << _graf.wierzcholki[i].begin()->parametry.first << "," << _graf.wierzcholki[i].begin()->parametry.second << ")\n";
		for (auto wierzcholek : _graf.wierzcholki[i]) {
			if (counter == 0)
				counter++;
			else
			cout << "  ->(" << wierzcholek.parametry.first << "," << wierzcholek.parametry.second << ")\n";
		}
	}
}*/