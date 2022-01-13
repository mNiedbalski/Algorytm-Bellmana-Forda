#pragma once
#include <iostream>
#include "model.h"
using namespace std;
/** \brief Funkcja, która obs³uguje podawane parametry do programu wraz z ich prze³¹cznikami.
*
* Przebieg funkcji:
* - Zainicjowanie wektora parametrów temp, w którym bêd¹ zawieraæ siê rzutowane parametry na typ string.
* - Wpisanie parametrów do wektora temp.
* - G³ówna pêtla funkcji, która iteruje przez wektor temp i gdy napotka prze³¹cznik, to wpisuje go do wektora params w nastêpuj¹cej kolejnoœci:
*   -# Plik wejœciowy z grafem
*   -# Plik wejœciowy z wierzcho³kami startowymi
*   -# Plik wyjœciowy z wynikami
*
*  Opis dzia³ania:
* -# Iteruj przez pomocniczy wektor, a¿ do napotkania prze³¹cznika.
* -# Element nastêpuj¹cy prze³¹cznik jest wartoœci¹ parametru odpowiadaj¹cego dla prze³¹cznika.
* -# Zapisz parametr do wektora parametrów.
*
* \param[in,out] params Wektor parametrów.
* \param[in] Liczba_parametrów Liczba parametrów wprowadzonych do programu.
* \param[in] parametry Wprowadzone parametry do programu wraz z ich odpowiadaj¹cymi prze³¹cznikami.
*/
bool Load_parameters(vector <string>& params, const int& Liczba_parametrów, char* parametry[]);
/** \brief Funkcja ³aduj¹ca graf z pliku tekstowego.
* 
* Przebieg funkcji:
* -# Wczytuj dane do zmiennej temp i zale¿nie od wartoœci zmiennej sequence wykonaj odpowiednie kroki:
*   -# Gdy sequence % 5 == 0 to przekonwertuj temp na typ int i zapisz w zmiennej beginning.
*   -# Gdy sequence % 5 == 1 to sprawdŸ czy krawêdŸ jest skierowana, czy dwukierunkowa i ustaw odpowiedni¹ wartoœæ zmiennej directed.
*   -# Gdy sequence % 5 == 2 to przekonwertuj temp na typ int i zapisz w zmiennej end.
*   -# Gdy sequence % 5 == 4 to przekonwertuj temp na typ double i zapisz w zmiennej cost. Nastêpnie zale¿nie od wartoœci zmiennej directed wykonaj funkcjê addEdge_Directed() raz, lub podwójnie.
* -# Zinkrementuj sequence i wczytuj dalej krawêdzie.
*	 
* \params[in] name Nazwa pliku tekstowego zawieraj¹cego graf.
* \param[in,out] _graph Graf, który jest ³adowany z pliku tekstowego.
* \return false jest niepoprawna liczba parametrow
* \return true jest poprawna liczba parametrow
*/
void Load_graph(const string& name, Graph& _graph);
/** \brief Funkcja wczytuj¹ca wierzcho³ki, dla których program bêdzie szukaæ najkrótszych tras do innych.
* \param[in] name Nazwa pliku tekstowego, z którego s¹ wczytywane zmienne.
* \param[in,out] variables Wektor zmiennych zawieraj¹cy wierzcho³ki, dla których program bêdzie szukaæ najkrótszych tras do innych wierzcho³ków.
*/
void Load_variables(const string& name, vector <int>& variables);
/** \brief Funkcja przygotowuj¹ca plik wyjœciowy do pracy.
* 
* Jej zadaniem jest wyczyszczenie aktualnej zawartoœci pliku. Potrzebne jest to, gdy¿ implementacja zapisywania danych do pliku dopisuje dane, a nie nadpisuje starych.
* 
* \param[in] fileName Nazwa pliku wyjœciowego.
*/
void Setup_File(const string& fileName);
/** \brief Funkcja wyœwietlaj¹ca graf w konsoli (Funkcja debuggowa).
* 
* \param[in,out] graph Wyœwietlany graf.
*/
void DisplayGraph(const Graph& graph);
/** \brief Funkcja wpisuj¹ca do pliku tekstowego informacjê o ujemnym cyklu w grafie.
* \param[in] _fileName Nazwa wyjœciowego pliku tekstowego.
*/
void PrintNegativeCycle(const string& _fileName);
/** \brief Funkcja wpisuj¹ca do pliku tekstowego informacjê o braku podanego wierzcholka.
* \param[in,out] _fileName Nazwa wyjœciowego pliku tekstowego.
* \param[in] _var Indeks wierzcholka.
*/
void PrintNotFound(const string& _fileName, const int& _var);
/** \brief Funkcja sprawdzaj¹ca, czy podany wierzcho³ek znajduje siê w grafie.
* \param[in] _graph Przeszukiwany graf.
* \param[in] _var Indeks szukanego wierzcho³ka.
*/
bool CheckVar(const int& _var, const Graph& graph);
/** \brief Funkcja sprawdzaj¹ca czy podany plik wejœciowy jest dostêpny dla programu.
* \param[in] _fileName nazwa sprawdzanego pliku.
* \return true program jest w stanie otworzyæ plik tekstowy.
* \return false program nie jest w stanie otworzyæ pliku tekstowego.
*/
bool FileCorrect(const string& _fileName);