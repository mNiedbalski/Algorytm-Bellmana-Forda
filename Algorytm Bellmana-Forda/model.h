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
	vector <Node> nodes;
	unordered_map<int, int> umap_nodes;
	unordered_map<int, int> umap_nodes_reversed;
};
/** \brief Funkcja, która obsługuje podawane parametry do programu wraz z ich przełącznikami.
*
* Przebieg funkcji:
* - Zainicjowanie wektora parametrów temp, w którym będą zawierać się rzutowane parametry na typ string.
* - Wpisanie parametrów do wektora temp.
* - Główna pętla funkcji, która iteruje przez wektor temp i gdy napotka przełącznik, to wpisuje go do wektora params.
*   -# Plik wejściowy z grafem
*   -# Plik wejściowy z wierzchołkami startowymi
*   -# Plik wyjściowy z wynikami
*
*  Opis działania:
* - Iteruj przez pomocniczy wektor, aż do napotkania przełącznika.
* - Element następujący przełącznik jest wartością parametru odpowiadającego dla przełącznika.
* - Zapisz parametr do wektora parametrów.
*
* \param[in,out] params Wektor parametrów.
* \param[in] Liczba_parametrów Liczba parametrów wprowadzonych do programu.
* \param[in] parametry Wprowadzone parametry do programu wraz z ich odpowiadającymi przełącznikami.
*/
void Load_parameters(vector <string>& params, const int & Liczba_parametrów, char* parametry[]);
void Load_graph(const string& name, Graph& _graph);
void Load_variables(const string& name, vector <int>& variables);
int Find(const Graph& graph, const int& index, bool& _found);
void addEdge_Directed(Graph& graph, const int begin, const int end, const int cost);
void Bellman_Ford(Graph& graph, const int index);
void DisplayGraph(const Graph& graph);