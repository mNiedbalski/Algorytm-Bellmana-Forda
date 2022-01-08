#pragma once
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <fstream>
using namespace std;
/** \struct Edge
* \brief Struktura opakowuj¹ca wprowadzane krawêdzie do programu
* 
* \param begin Zmienna przechowuj¹ca indeks pocz¹tku krawêdzi
* \param end Zmienna przechowuj¹ca indeks koñca krawêdzi.
* \param cost Zmienna przechowuj¹ca koszt przejœcia krawêdzi.
*/
struct Edge
{
	int begin;
	int end;
	double cost;
};
/** \struct Node
* \brief Struktura opakowuj¹ca wprowadzane wierzcho³ki do programu.
*
* \param index Zmienna przechowuj¹ca indeks wierzcho³ka
* \param edges Lista przechowuj¹ca krawêdzie, którymi mo¿na przejœæ z tego wierzcho³ka do innych.
*/
struct Node
{
	int index;
	list<Edge> edges;
};
/** \struct Graph
* \brief Struktura opakowuj¹ca wprowadzony graf do programu.
* 
* \param nodes Wektor wierzcho³kow znajduj¹cych siê w grafie.
* \param umap_nodes Mapa zawieraj¹ca indeksy wierzcho³kow z przypisanymi do nich wartoœciami od 0, do n, gdzie n to liczba wierzcho³ków w grafie.
* \param umap_nodes_reversed Mapa zawieraj¹ca indeksy wierzcho³ków, które s¹ przypisane do wartoœci od 0, do n, gdzie n to liczba wierzcho³ków w grafie.
*/
struct Graph
{
	list <Edge> allEdges;
	vector <Node> nodes;
	unordered_map<int, int> umap_nodes;
	unordered_map<int, int> umap_nodes_reversed;
};



int Find(const Graph& graph, const int& index, bool& _found);
void addEdge_Directed(Graph& graph, const int begin, const int end, const int cost);
bool StaryBellmanFord(Graph& graph, const int index);
bool Bellman_Ford(Graph& graph, const int index);
