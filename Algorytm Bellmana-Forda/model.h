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
	vector <Node> nodes;
	unordered_map<int, int> umap_nodes;
	unordered_map<int, int> umap_nodes_reversed;
};
/** \brief Funkcja, która obs³uguje podawane parametry do programu wraz z ich prze³¹cznikami.
*
* Przebieg funkcji:
* - Zainicjowanie wektora parametrów temp, w którym bêd¹ zawieraæ siê rzutowane parametry na typ string.
* - Wpisanie parametrów do wektora temp.
* - G³ówna pêtla funkcji, która iteruje przez wektor temp i gdy napotka prze³¹cznik, to wpisuje go do wektora params.
*   -# Plik wejœciowy z grafem
*   -# Plik wejœciowy z wierzcho³kami startowymi
*   -# Plik wyjœciowy z wynikami
*
*  Opis dzia³ania:
* - Iteruj przez pomocniczy wektor, a¿ do napotkania prze³¹cznika.
* - Element nastêpuj¹cy prze³¹cznik jest wartoœci¹ parametru odpowiadaj¹cego dla prze³¹cznika.
* - Zapisz parametr do wektora parametrów.
*
* \param[in,out] params Wektor parametrów.
* \param[in] Liczba_parametrów Liczba parametrów wprowadzonych do programu.
* \param[in] parametry Wprowadzone parametry do programu wraz z ich odpowiadaj¹cymi prze³¹cznikami.
*/
void Load_parameters(vector <string>& params, const int & Liczba_parametrów, char* parametry[]);
void Load_graph(const string& name, Graph& _graph);
void Load_variables(const string& name, vector <int>& variables);
int Find(const Graph& graph, const int& index, bool& _found);
void addEdge_Directed(Graph& graph, const int begin, const int end, const int cost);
void Bellman_Ford(Graph& graph, const int index);
void DisplayGraph(const Graph& graph);