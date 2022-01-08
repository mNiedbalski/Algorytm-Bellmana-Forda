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
* \brief Struktura opakowuj�ca wprowadzane kraw�dzie do programu
* 
* \param begin Zmienna przechowuj�ca indeks pocz�tku kraw�dzi
* \param end Zmienna przechowuj�ca indeks ko�ca kraw�dzi.
* \param cost Zmienna przechowuj�ca koszt przej�cia kraw�dzi.
*/
struct Edge
{
	int begin;
	int end;
	double cost;
};
/** \struct Node
* \brief Struktura opakowuj�ca wprowadzane wierzcho�ki do programu.
*
* \param index Zmienna przechowuj�ca indeks wierzcho�ka
* \param edges Lista przechowuj�ca kraw�dzie, kt�rymi mo�na przej�� z tego wierzcho�ka do innych.
*/
struct Node
{
	int index;
	list<Edge> edges;
};
/** \struct Graph
* \brief Struktura opakowuj�ca wprowadzony graf do programu.
* 
* \param nodes Wektor wierzcho�kow znajduj�cych si� w grafie.
* \param umap_nodes Mapa zawieraj�ca indeksy wierzcho�kow z przypisanymi do nich warto�ciami od 0, do n, gdzie n to liczba wierzcho�k�w w grafie.
* \param umap_nodes_reversed Mapa zawieraj�ca indeksy wierzcho�k�w, kt�re s� przypisane do warto�ci od 0, do n, gdzie n to liczba wierzcho�k�w w grafie.
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
