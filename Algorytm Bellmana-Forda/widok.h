#pragma once
#include <iostream>
#include "model.h"
using namespace std;
/** \brief Funkcja, kt�ra obs�uguje podawane parametry do programu wraz z ich prze��cznikami.
*
* Przebieg funkcji:
* - Zainicjowanie wektora parametr�w temp, w kt�rym b�d� zawiera� si� rzutowane parametry na typ string.
* - Wpisanie parametr�w do wektora temp.
* - G��wna p�tla funkcji, kt�ra iteruje przez wektor temp i gdy napotka prze��cznik, to wpisuje go do wektora params w nast�puj�cej kolejno�ci:
*   -# Plik wej�ciowy z grafem
*   -# Plik wej�ciowy z wierzcho�kami startowymi
*   -# Plik wyj�ciowy z wynikami
*
*  Opis dzia�ania:
* -# Iteruj przez pomocniczy wektor, a� do napotkania prze��cznika.
* -# Element nast�puj�cy prze��cznik jest warto�ci� parametru odpowiadaj�cego dla prze��cznika.
* -# Zapisz parametr do wektora parametr�w.
*
* \param[in,out] params Wektor parametr�w.
* \param[in] Liczba_parametr�w Liczba parametr�w wprowadzonych do programu.
* \param[in] parametry Wprowadzone parametry do programu wraz z ich odpowiadaj�cymi prze��cznikami.
*/
bool Load_parameters(vector <string>& params, const int& Liczba_parametr�w, char* parametry[]);
/** \brief Funkcja �aduj�ca graf z pliku tekstowego.
* 
* Przebieg funkcji:
* -# Wczytuj dane do zmiennej temp i zale�nie od warto�ci zmiennej sequence wykonaj odpowiednie kroki:
*   -# Gdy sequence % 5 == 0 to przekonwertuj temp na typ int i zapisz w zmiennej beginning.
*   -# Gdy sequence % 5 == 1 to sprawd� czy kraw�d� jest skierowana, czy dwukierunkowa i ustaw odpowiedni� warto�� zmiennej directed.
*   -# Gdy sequence % 5 == 2 to przekonwertuj temp na typ int i zapisz w zmiennej end.
*   -# Gdy sequence % 5 == 4 to przekonwertuj temp na typ double i zapisz w zmiennej cost. Nast�pnie zale�nie od warto�ci zmiennej directed wykonaj funkcj� addEdge_Directed() raz, lub podw�jnie.
* -# Zinkrementuj sequence i wczytuj dalej kraw�dzie.
*	 
* \params[in] name Nazwa pliku tekstowego zawieraj�cego graf.
* \param[in,out] _graph Graf, kt�ry jest �adowany z pliku tekstowego.
* \return false jest niepoprawna liczba parametrow
* \return true jest poprawna liczba parametrow
*/
void Load_graph(const string& name, Graph& _graph);
/** \brief Funkcja wczytuj�ca wierzcho�ki, dla kt�rych program b�dzie szuka� najkr�tszych tras do innych.
* \param[in] name Nazwa pliku tekstowego, z kt�rego s� wczytywane zmienne.
* \param[in,out] variables Wektor zmiennych zawieraj�cy wierzcho�ki, dla kt�rych program b�dzie szuka� najkr�tszych tras do innych wierzcho�k�w.
*/
void Load_variables(const string& name, vector <int>& variables);
/** \brief Funkcja przygotowuj�ca plik wyj�ciowy do pracy.
* 
* Jej zadaniem jest wyczyszczenie aktualnej zawarto�ci pliku. Potrzebne jest to, gdy� implementacja zapisywania danych do pliku dopisuje dane, a nie nadpisuje starych.
* 
* \param[in] fileName Nazwa pliku wyj�ciowego.
*/
void Setup_File(const string& fileName);
/** \brief Funkcja wy�wietlaj�ca graf w konsoli (Funkcja debuggowa).
* 
* \param[in,out] graph Wy�wietlany graf.
*/
void DisplayGraph(const Graph& graph);
/** \brief Funkcja wpisuj�ca do pliku tekstowego informacj� o ujemnym cyklu w grafie.
* \param[in] _fileName Nazwa wyj�ciowego pliku tekstowego.
*/
void PrintNegativeCycle(const string& _fileName);
/** \brief Funkcja wpisuj�ca do pliku tekstowego informacj� o braku podanego wierzcholka.
* \param[in,out] _fileName Nazwa wyj�ciowego pliku tekstowego.
* \param[in] _var Indeks wierzcholka.
*/
void PrintNotFound(const string& _fileName, const int& _var);
/** \brief Funkcja sprawdzaj�ca, czy podany wierzcho�ek znajduje si� w grafie.
* \param[in] _graph Przeszukiwany graf.
* \param[in] _var Indeks szukanego wierzcho�ka.
*/
bool CheckVar(const int& _var, const Graph& graph);
/** \brief Funkcja sprawdzaj�ca czy podany plik wej�ciowy jest dost�pny dla programu.
* \param[in] _fileName nazwa sprawdzanego pliku.
* \return true program jest w stanie otworzy� plik tekstowy.
* \return false program nie jest w stanie otworzy� pliku tekstowego.
*/
bool FileCorrect(const string& _fileName);