#pragma once
#include<fstream>


using namespace std;

void creatArray2D(int** &array, int x, int y)
{
	array = new int*[y];
	for (int j = 0; j < y; j++)
		array[j] = new int[x];
}

void initArray2D(int **array, int x, int y)
{
	for (int j = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			array[j][i] = 1;
		}
	}
}

void showArray2D(int ** array, int x, int y)
{
	for (int j = 0; j < y; j++) {
		for (int i = 0; i < x; i++)
			cout << array[j][i] << "\t";
		cout << endl;
	}
}

void deleteArray2D(int** &array, int y)
{
	for (int j = 0; j < y; j++)
		delete[] array[j];
	delete[] array;
}

bool load_data(int &n, int &m, int &k, int** &city_arr, int** &tram_rails, char* pathfile)
{
	ifstream infile(pathfile);
	infile >> n >> m >> k;

	if (n < 1 || n > 10e9)
	{
		cout << "Invalid value rows of city map" << endl;
		infile.close();
		return false;
	}
	if (m < 1 || m > 10e9)
	{
		cout << "invalid value columns of city map" << endl;
		infile.close();
		return false;
	}
	if (k < 0 || n > 1000)
	{
		cout << "invalid value tramway" << endl;
		infile.close();
		return false;
	}

	creatArray2D(city_arr, m, n);
	initArray2D(city_arr, m, n);

	creatArray2D(tram_rails, 3, k);

	for (int i = 0; i < k; i++)
	{
		infile >> tram_rails[i][0] >> tram_rails[i][1] >> tram_rails[i][2];
		if (tram_rails[i][0] < 1 || tram_rails[i][0] > n)
		{
			cout << "Invalid rows of tramway" << endl;
			infile.close();
			return false;
		}
		if (tram_rails[i][1] < 1 || tram_rails[i][1] > m || tram_rails[i][2] < 1 || tram_rails[i][2] > m)
		{
			cout << "Invalid beginning or end of a tramway" << endl;
			infile.close();
			return false;
		}
	}
	infile.close();
	return true;
}

int light_number(int &n, int &m, int &k, int** city_arr, int** tram_rails)
{
	int light = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = tram_rails[i][1] - 1; j <= tram_rails[i][2] - 1; j++)
		{
			city_arr[tram_rails[i][0] - 1][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (city_arr[i][j] == 1)
				light++;
		}
	}
	return light;
}