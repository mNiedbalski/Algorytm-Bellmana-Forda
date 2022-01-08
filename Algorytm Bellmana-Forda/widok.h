#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "model.h"
using namespace std;
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
void Load_parameters(vector <string>& params, const int& Liczba_parametrów, char* parametry[]);
void Load_graph(const string& name, Graph& _graph);
void Load_variables(const string& name, vector <int>& variables);
void DisplayGraph(const Graph& graph);