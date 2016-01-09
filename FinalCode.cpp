#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

//This is the size of the Triangle
#define SIZE 15
//This is the text file where data is collected
#define FILE "input.txt"
//this is the data storage
int triangle [SIZE][SIZE] = {0};

//goes through and parses numbers to put in a matrix
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

//used at any time to print the matrix
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


//starts from the second last row of the triangle
//adds up the bigger number from it's child and replaces number with sum
//continues up the triangle
int maxPath ()
{
	//second last row of triangle
	for (int i= SIZE-2; i>=0; i--)
	{
		//Starts at very left number
		for (int j=0; j<=i; j++)
		{
			//adds the bigger number from the bottom two numbers
			//and replaces it with sum
			int sum;
			if (triangle[i+1][j]>= triangle[i+1][j+1])
				sum = triangle[i][j] + triangle[i+1][j];
			else
				sum = triangle[i][j] + triangle[i+1][j+1];
			triangle[i][j] = sum;
		}
	}
	//continually cycles up until it gets to the first number
	//return first number the answer
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