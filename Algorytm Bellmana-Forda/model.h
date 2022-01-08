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
* \brief Struktura opakowująca wprowadzane krawędzie do programu
* 
* \param begin Zmienna przechowująca indeks początku krawędzi
* \param end Zmienna przechowująca indeks końca krawędzi.
* \param cost Zmienna przechowująca koszt przejścia krawędzi.
*/
struct Edge
{
	int begin;
	int end;
	double cost;
};
/** \struct Node
* \brief Struktura opakowująca wprowadzane wierzchołki do programu.
*
* \param index Zmienna przechowująca indeks wierzchołka
* \param edges Lista przechowująca krawędzie, którymi można przejść z tego wierzchołka do innych.
*/
struct Node
{
	int index;
	list<Edge> edges;
};
/** \struct Graph
* \brief Struktura opakowująca wprowadzony graf do programu.
* 
* \param nodes Wektor wierzchołkow znajdujących się w grafie.
* \param umap_nodes Mapa zawierająca indeksy wierzchołkow z przypisanymi do nich wartościami od 0, do n, gdzie n to liczba wierzchołków w grafie.
* \param umap_nodes_reversed Mapa zawierająca indeksy wierzchołków, które są przypisane do wartości od 0, do n, gdzie n to liczba wierzchołków w grafie.
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
void Save(Graph& _graph, const string& _fileName, const int index, const vector <int>& _distances, const vector <string>& _paths);
bool Bellman_Ford(Graph& graph, const int index, const string & fileName);
