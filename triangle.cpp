#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> Row; // One row of the matrix
typedef vector<Row> Matrix; 

/*
matrix
1 2 3 4
5 6 7 8
9 A B C
matrix[0][2] = 3
matrix[1][3] = 8
matrix[2]= 9ABC
 */

int main() {
	ifstream input("input.txt");
	Matrix triangle(15,Row(15));
	string line;
	int size = triangle.size();

	if(input.is_open())
	{
		while(!input.eof())
		{
			getline(input,line);
			stringstream eachrow(line);
			for (int i=0; i<size; i++)
				for (int j=0; j<size;j++)
					eachrow >> triangle [i][j];
		}
		input.close();
	}
	for (int i=0; i<size; i++)
		{
			for (int j=0; j<size;j++)
				{
					cout << triangle[i][j] << " ";
				}
				cout <<endl;
		}

}