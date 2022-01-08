#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "model.h"
using namespace std;
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
void Load_parameters(vector <string>& params, const int& Liczba_parametr�w, char* parametry[]);
void Load_graph(const string& name, Graph& _graph);
void Load_variables(const string& name, vector <int>& variables);
void DisplayGraph(const Graph& graph);