#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

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
			cout.width(4);
			cout<<triangle[a][b]<<" ";
		}
		cout<<endl;
	}
	cout <<endl;
}

int maxPath ()
{
	for (int i= SIZE-2; i>=0; i--)
	{
		for (int j=0; j<=i; j++)
		{
			int sum;
			if (triangle[i+1][j]>= triangle[i+1][j+1])
				{sum = triangle[i][j] + triangle[i+1][j];}
			else
				{sum = triangle[i][j] + triangle[i+1][j+1];}
			triangle[i][j] = sum;
		}
		//cout<<"line: "<<i<<endl;
	}
	return triangle[0][0];
}

int main()
{
	dataIn();
	//print();
	int ans = maxPath();
	//print();
	cout<<"Answer:"<<ans<<endl;
	return 0;
}