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
/** \brief Funkcja szukaj¹ca wierzcho³ka w grafie.
* 
* Funkcja iteruje przez wszystkie wierzcho³ki i sprawdza czy istnieje jakiœ o indeksach pocz¹tku i koñca krawêdzi.
* Jeœli zostanie znaleziony, to funkcja siê koñczy i zwraca indeks wierzcho³ka w wektorze.
* Jeœli nie zostanie znaleziony, zostaje przekazana o tym stosowna informacja i w kolejnych wykonywach instrukcjach programu brakuj¹cy wierzcho³ek zostaje dodany.
* 
* \param[in] graph Przeszukiwany graf.
* \param[in] index Indeks szukanego wierzcho³ka.
* \param[in,out] _found 
* \return indeks znalezionego wierzcho³ka
*/
int Find(const Graph& graph, const int& index, bool& _found);
/** \brief Funkcja dodaj¹ca skierowan¹ krawêdŸ do grafu.
* 
* Przebieg funkcji:
* -# Stwórz tymczasow¹ krawêdŸ i zainicjuj jej parametry wprowadzonymi parametrami do funkcji.
* -# SprawdŸ czy istnieje wierzcho³ek pocz¹tkowy i koñcowy w grafie. Jeœli, któryœ nie istnieje, to go stwórz.
* -# Wepchnij na koniec listy krawêdzi wierzcho³ka pocz¹tkowego ow¹ krawêdŸ.
* 
* \param[in,out] graph Graf do którego s¹ dodawane krawêdzie.
* \param[in] begin Indeks wierzcho³ka z którego wychodzi krawêdŸ.
* \param[in] end Indeks wierzcho³ka w którym siê koñczy krawêdŸ.
* \param[in] cost Koszt przejœcia z wierzcho³ka o indeksie begin do wierzcho³ka o indeksie end.
*/
void addEdge_Directed(Graph& graph, const int begin, const int end, const double cost);
/** \brief Funkcja zapisuj¹ca wyniki algorytmu Bellmana-Forda dla wprowadzonych danych. Zapis jest dokonywany w pliku tekstowym podanym przez u¿ytkownika.
* 
* Format zapisu:
* Wierzcholek startowy: index
* np. index->2->3 : cost
* np. index->4->5 : cost
* 
* \param[in] _graph Graf z którego s¹ zapisywane wyniki.
* \param[in] _fileName Nazwa pliku wyjœciowego.
* \param[in] index Indeks wierzcho³ka, dla którego s¹ zapisywane wyniki.
* \param[in] _distances Koszty optymalnych tras u³o¿one w kolejnoœci odpowiadaj¹cej ich destynacjom (indeks wektora distances odpowiada indeksowi w wektorze wierzcho³ków).
* \param[in] _paths Wypisane optymalne trasy u³o¿one w kolejnoœci odpowiadaj¹cej ich destynacjom (indeks wektora distances odpowiada indeksowi w wektorze wierzcho³ków).
*/
void Save(Graph& _graph, const string& _fileName, const int index, const vector <double>& _distances, const vector <string>& _paths);

/** \brief Najistotniejsza funkcja programu wykonuj¹ca algorytm Bellmana-Forda.
* 
* Przebieg dzia³ania algorytmu:
* -# Zainicjuj wektor dystansów do ka¿dego wierzcho³ka wartoœciami maksymalnymi, a komórkê odpowiadaj¹c¹ wierzcho³kowi startowemu zainicjuj zerem.
* -# Zainicjuj wektor tras indeksem startowego wierzcho³ka.
* -# Wykonaj krok 4 N razy, gdzie N to liczba wierzcho³ków w grafie. Dlaczego nie N-1 razy? Bo podczas tej pêtli algorytm jest w stanie sprawdziæ czy nie wystêpuje ujemny cykl. Jeœli w ostatniej iteracji wektor distances siê zmieni, to znaczy, ¿e wyst¹pi³ ujemny cykl.
* -# Wykonaj krok 5 i 6 dla ka¿dej krawêdzi w sprawdzanym wierzcho³ku.
* -# SprawdŸ, czy aktualny optymalny dystans do pocz¹tku tej krawêdzi nie wynosi MAX_INT (zamiast nieskoñczonoœci). Jeœli dystans do pocz¹tku tej krawêdzi wynosi MAX_INT to przejdŸ do kolejnej krawêdzi w tym wierzcho³ku.
* -# Jeœli aktualny optymalny dystans do pocz¹tku tej krawêdzi po dodaniu kosztu krawêdzi jest mniejszy od dystansu do koñca tej krawêdzi, to zaaktualizuj optymalny trasê i zaaktualizuj wygl¹d trasy w wektorze paths.
* -# Jeœli zosta³a wykonana ostatnia iteracja g³ównej pêtli, i nie dokonano zmian, to przejdŸ do zapisu danych w pliku. W przypadku, gdy dokonano zmian, to zwróæ fa³sz, symbolizuj¹cy pojawienie siê ujemnego cyklu.
*/
bool Bellman_Ford(Graph& graph, const int index, const string & fileName);
