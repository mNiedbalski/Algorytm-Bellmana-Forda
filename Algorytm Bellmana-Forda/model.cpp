#include "model.h"
using namespace std;

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
		graph.allEdges.push_back(newEdge);
	}
	else {
		Node newNode;
		newNode.index = begin;
		graph.umap_nodes[begin] = graph.nodes.size();
		graph.umap_nodes_reversed[graph.nodes.size()] = begin;
		newNode.edges.push_back(newEdge);
		graph.allEdges.push_back(newEdge);
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

bool Bellman_Ford(Graph& graph, const int index)
{
	vector <int> distances;
	distances.resize(graph.nodes.size());
	for (int i = 0; i < graph.nodes.size(); i++)
		distances[i] = INT_MAX;
	distances[graph.umap_nodes.at(index)] = 0;

	bool change = false;
	for (int i = 0; i < graph.nodes.size(); i++) {
		for (auto node : graph.nodes) {
			for (auto edge : node.edges) {
				if (distances[graph.umap_nodes.at(edge.begin)] != INT_MAX && distances[graph.umap_nodes.at(edge.begin)] + edge.cost < distances[graph.umap_nodes.at(edge.end)]) {
					distances[graph.umap_nodes.at(edge.end)] = distances[graph.umap_nodes.at(edge.begin)] + edge.cost;
					if (i == graph.nodes.size() - 1)
						return false;
				}

			}
		}
	}
	cout << "RESULTS:\n\n";
	for (int i = 0; i < distances.size(); i++)
	{
		cout << index << " -> " << graph.umap_nodes_reversed.at(i) << " cost: " << distances[i] << endl;
	}
	return true;
}



bool StaryBellmanFord(Graph& graph, const int index)
{
	vector <int> distance;
	distance.resize(graph.nodes.size());

	for (int i = 0; i < graph.nodes.size(); i++)
		distance[i] = INT_MAX;
	distance[graph.umap_nodes.at(index)] = 0;

	for (int i = 0; i < graph.nodes.size(); i++) {
		for (auto edge : graph.nodes[i].edges) {
			if (distance[graph.umap_nodes.at(edge.begin)] != INT_MAX && distance[graph.umap_nodes.at(edge.begin)] + edge.cost < distance[graph.umap_nodes.at(edge.end)])
				distance[graph.umap_nodes.at(edge.end)] = distance[graph.umap_nodes.at(edge.begin)] + edge.cost;
		}
	}
	for (auto edge : graph.allEdges) {
		if (distance[graph.umap_nodes.at(edge.begin)] != INT_MAX && distance[graph.umap_nodes.at(edge.begin)] + edge.cost < distance[graph.umap_nodes.at(edge.begin)])
			return true;
	}

	cout << "RESULTS:\n\n";
	for (int i = 0;i < distance.size(); i++)
	{
		cout << index << " -> " << graph.umap_nodes_reversed.at(i) << " cost: " << distance[i] << endl;
	}
	return false;
	
}


/*	for (auto edge : graph.allEdges) {
		if (distance[graph.umap_nodes.at(edge.begin)] != INT_MAX && distance[graph.umap_nodes.at(edge.begin)] + edge.cost < distance[graph.umap_nodes.at(edge.end)])
			return true;
	}*/























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