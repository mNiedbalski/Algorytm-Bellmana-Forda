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
	vector <string> paths;
	distances.resize(graph.nodes.size());
	paths.resize(graph.nodes.size());
	for (int i = 0; i < graph.nodes.size(); i++)
		distances[i] = INT_MAX;
	distances[graph.umap_nodes.at(index)] = 0;
	string temp = to_string(index);
	cout << "paths: \n";
	for (int i = 0; i < graph.nodes.size(); i++) {
		paths[i] = temp;
	}




	bool change = false;
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
	cout << "RESULTS:\n\n";
	for (int i = 0; i < distances.size(); i++)
	{
		cout << index << " -> " << graph.umap_nodes_reversed.at(i) << " cost: " << distances[i] << endl;
		cout << paths[i] << endl;
	}
	return true;
}
