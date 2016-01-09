#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

#define SIZE 15
#define FILE "input.txt"
int triangle [SIZE][SIZE] = {0};

void dataIn () {
	ifstream tfile(FILE);
	int i(0);
	//cycle through rows
	while(!tfile.eof())
	{
		string line;
		int j(0), next(0);
		getline (tfile, line);
		stringstream eachrow(line);
		//store each row
		while(eachrow >> next)
		{
			triangle [i][j]=next;
			j++;
		}
		i++;
	}
	tfile.close();
}

void print()
{
	for(int a=0; a<SIZE; a++)
	{
		for(int b=0; b<SIZE; b++)
		{
			cout.width(2);
			cout<<triangle[a][b]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	dataIn();
	print();
}