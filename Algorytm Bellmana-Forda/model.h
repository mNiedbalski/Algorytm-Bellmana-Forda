/**
* \file
*/
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
/** \brief Funkcja szukaj�ca wierzcho�ka w grafie.
* 
* Funkcja iteruje przez wszystkie wierzcho�ki i sprawdza czy istnieje jaki� o indeksach pocz�tku i ko�ca kraw�dzi.
* Je�li zostanie znaleziony, to funkcja si� ko�czy i przekazywany parametr _where zawiera informacje o tym, gdzie jest ten wierzcho�ek.
* Parametr _where jest tylko istotny dla poszukiwania pocz�tkowego wierzcho�ka, gdy� ko�cowy jest tylko tworzony, je�li go nie ma, aby istnia� w grafie.
* Je�li nie zostanie znaleziony, zostaje przekazana o tym stosowna informacja i w kolejnych wykonywach instrukcjach programu brakuj�cy wierzcho�ek zostaje dodany.
* 
* \param[in] graph Przeszukiwany graf.
* \param[in] index Indeks szukanego wierzcho�ka.
* \param[in,out] _found Zmienna przechowuj�ca informacj� o tym, czy zosta� znaleziony wierzcho�ek.
* \param[in,out] _where Zmienna przechowuj�ca indeks znalezionego wierzcho�ka.
*/
bool Find(const Graph& graph, const int& index, int & _where);
/** \brief Funkcja dodaj�ca skierowan� kraw�d� do grafu.
* 
* Przebieg funkcji:
* -# Stw�rz tymczasow� kraw�d� i zainicjuj jej parametry wprowadzonymi parametrami do funkcji.
* -# Sprawd� czy istnieje wierzcho�ek pocz�tkowy i ko�cowy w grafie. Je�li, kt�ry� nie istnieje, to go stw�rz.
* -# Wepchnij na koniec listy kraw�dzi wierzcho�ka pocz�tkowego ow� kraw�d�.
* 
* \param[in,out] graph Graf do kt�rego s� dodawane kraw�dzie.
* \param[in] begin Indeks wierzcho�ka z kt�rego wychodzi kraw�d�.
* \param[in] end Indeks wierzcho�ka w kt�rym si� ko�czy kraw�d�.
* \param[in] cost Koszt przej�cia z wierzcho�ka o indeksie begin do wierzcho�ka o indeksie end.
*/
void addEdge_Directed(Graph& graph, const int begin, const int end, const double cost);
/** \brief Funkcja zapisuj�ca wyniki algorytmu Bellmana-Forda dla wprowadzonych danych. Zapis jest dokonywany w pliku tekstowym podanym przez u�ytkownika.
* 
* Format zapisu:
* Wierzcholek startowy: index
* np. index->2->3 : cost
* np. index->4->5 : cost
* 
* \param[in] _graph Graf z kt�rego s� zapisywane wyniki.
* \param[in] _fileName Nazwa pliku wyj�ciowego.
* \param[in] index Indeks wierzcho�ka, dla kt�rego s� zapisywane wyniki.
* \param[in] _distances Koszty optymalnych tras u�o�one w kolejno�ci odpowiadaj�cej ich destynacjom (indeks wektora distances odpowiada indeksowi w wektorze wierzcho�k�w).
* \param[in] _paths Wypisane optymalne trasy u�o�one w kolejno�ci odpowiadaj�cej ich destynacjom (indeks wektora distances odpowiada indeksowi w wektorze wierzcho�k�w).
*/
void Save(Graph& _graph, const string& _fileName, const int index, const vector <double>& _distances, const vector <string>& _paths);

/** \brief Najistotniejsza funkcja programu wykonuj�ca algorytm Bellmana-Forda.
* 
* Przebieg dzia�ania algorytmu:
* -# Zainicjuj wektor dystans�w do ka�dego wierzcho�ka warto�ciami maksymalnymi, a kom�rk� odpowiadaj�c� wierzcho�kowi startowemu zainicjuj zerem.
* -# Zainicjuj wektor tras indeksem startowego wierzcho�ka.
* -# Wykonaj krok 4 N razy, gdzie N to liczba wierzcho�k�w w grafie. Dlaczego nie N-1 razy? Bo podczas tej p�tli algorytm jest w stanie sprawdzi� czy nie wyst�puje ujemny cykl. Je�li w ostatniej iteracji wektor distances si� zmieni, to znaczy, �e wyst�pi� ujemny cykl.
* -# Wykonaj krok 5 i 6 dla ka�dej kraw�dzi w sprawdzanym wierzcho�ku.
* -# Sprawd�, czy aktualny optymalny dystans do pocz�tku tej kraw�dzi nie wynosi MAX_INT (zamiast niesko�czono�ci). Je�li dystans do pocz�tku tej kraw�dzi wynosi MAX_INT to przejd� do kolejnej kraw�dzi w tym wierzcho�ku.
* -# Je�li aktualny optymalny dystans do pocz�tku tej kraw�dzi po dodaniu kosztu kraw�dzi jest mniejszy od dystansu do ko�ca tej kraw�dzi, to zaaktualizuj optymalny tras� i zaaktualizuj wygl�d trasy w wektorze paths.
* -# Je�li zosta�a wykonana ostatnia iteracja g��wnej p�tli, i nie dokonano zmian, to przejd� do zapisu danych w pliku. W przypadku, gdy dokonano zmian, to zwr�� fa�sz, symbolizuj�cy pojawienie si� ujemnego cyklu.
*/
bool Bellman_Ford(Graph& graph, const int index, const string & fileName);
