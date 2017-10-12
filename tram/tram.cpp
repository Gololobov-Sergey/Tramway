// tram.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include"function.h"

using namespace std;

int main()
{
	int n;                               // rows map
	int m;                               // columns map
	int k;                               // tramway
	int streetlight;                     // number of street lights
	int** city_array = nullptr;          // array map of city
	int** tram_rails = nullptr;          // array of tramway
	char* pathfile = "D:\\test4-in.txt"; // pathfile

	if (load_data(n, m, k, city_array, tram_rails, pathfile))
	{
		streetlight = light_number(n, m, k, city_array, tram_rails);

		cout << "Map of tram routes" << endl;
		showArray2D(city_array, m, n);
		cout << endl;

		cout << "Array of tram routes" << endl;
		showArray2D(tram_rails, 3, k);
		cout << endl;

		cout << "Number of street lights - " << streetlight << endl;
	}

	deleteArray2D(city_array, n);
	deleteArray2D(tram_rails, k);
	system("pause");
    return 0;
}

