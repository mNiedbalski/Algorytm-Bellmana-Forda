#include "model.h"
using namespace std;

int Find(const Graph& graph, const int & index, bool & _found)
{
		if (graph.umap_nodes.find(index) != graph.umap_nodes.end()) {
			_found = true;
			return graph.umap_nodes.at(index);
		}
}
void addEdge_Directed(Graph& graph, const int begin, const int end, const double cost) //Skierowane
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

bool Bellman_Ford(Graph& graph, const int index, const string& fileName)
{
	vector <double> distances;
	vector <string> paths;
	distances.resize(graph.nodes.size());
	paths.resize(graph.nodes.size());
	for (int i = 0; i < graph.nodes.size(); i++)
		distances[i] = INT_MAX;
	distances[graph.umap_nodes.at(index)] = 0;
	string temp = to_string(index);
	for (int i = 0; i < graph.nodes.size(); i++) {
		paths[i] = temp;
	}

	for (int i = 0; i < graph.nodes.size(); i++) {
		for (auto node : graph.nodes) {
			for (auto edge : node.edges) {
				if (distances[graph.umap_nodes.at(edge.begin)] != INT_MAX && distances[graph.umap_nodes.at(edge.begin)] + edge.cost < distances[graph.umap_nodes.at(edge.end)]) {
					if (i == graph.nodes.size() - 1)
						return false;
					distances[graph.umap_nodes.at(edge.end)] = distances[graph.umap_nodes.at(edge.begin)] + edge.cost;
					paths[graph.umap_nodes.at(edge.end)] = paths[graph.umap_nodes.at(edge.begin)] + "->" + to_string(edge.end);

				}

			}
		}
	}
	Save(graph, fileName, index, distances, paths);
	return true;
}
void Save(Graph& _graph, const string& _fileName, const int index, const vector <double>& _distances, const vector <string>& _paths)
{
	ofstream file;
	file.open(_fileName, ios::app);
	file << "Wierzcholek startowy: " << index << endl;
	for (int i = 0; i < _graph.nodes.size(); i++) {
		if (index != _graph.umap_nodes_reversed.at(i)) {
			if (_distances[i] == INT_MAX)
				file << index << "->" << _graph.umap_nodes_reversed.at(i) << " : BRAK TRASY" << endl;
			else
				file << _paths[i] << " : " << _distances[i] << endl;
		}

	}

}

