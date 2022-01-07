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
	vector <Node> nodes;
	unordered_map<int, int> umap_nodes;
	unordered_map<int, int> umap_nodes_reversed;
};
/** \brief Funkcja, kt�ra obs�uguje podawane parametry do programu wraz z ich prze��cznikami.
*
* Przebieg funkcji:
* - Zainicjowanie wektora parametr�w temp, w kt�rym b�d� zawiera� si� rzutowane parametry na typ string.
* - Wpisanie parametr�w do wektora temp.
* - G��wna p�tla funkcji, kt�ra iteruje przez wektor temp i gdy napotka prze��cznik, to wpisuje go do wektora params.
*   -# Plik wej�ciowy z grafem
*   -# Plik wej�ciowy z wierzcho�kami startowymi
*   -# Plik wyj�ciowy z wynikami
*
*  Opis dzia�ania:
* - Iteruj przez pomocniczy wektor, a� do napotkania prze��cznika.
* - Element nast�puj�cy prze��cznik jest warto�ci� parametru odpowiadaj�cego dla prze��cznika.
* - Zapisz parametr do wektora parametr�w.
*
* \param[in,out] params Wektor parametr�w.
* \param[in] Liczba_parametr�w Liczba parametr�w wprowadzonych do programu.
* \param[in] parametry Wprowadzone parametry do programu wraz z ich odpowiadaj�cymi prze��cznikami.
*/
void Load_parameters(vector <string>& params, const int & Liczba_parametr�w, char* parametry[]);
void Load_graph(const string& name, Graph& _graph);
void Load_variables(const string& name, vector <int>& variables);
int Find(const Graph& graph, const int& index, bool& _found);
void addEdge_Directed(Graph& graph, const int begin, const int end, const int cost);
void Bellman_Ford(Graph& graph, const int index);
void DisplayGraph(const Graph& graph);