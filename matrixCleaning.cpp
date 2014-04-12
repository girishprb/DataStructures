/*If A[i][j]==0, set all values along i'th row and j'th to 0 */
#include<stdlib.h>
#include<iostream>
using namespace std;

#define ROW 20
#define COL 20

class IntMatrix
{
private:
	int a[ROW][COL];
	bool markedCol[COL], markedRow[ROW];

public:

	//Constructor: //Randomly initialize the int array matrix
	IntMatrix()
	{
		for(int i=0; i <ROW; i++)
		{
			markedRow[i] = false;
			markedCol[i] = false;
			for(int j=0; j <COL; j++)
			{
				a[i][j] = (rand() % (int)(2));
			}
		}
	}

	void MatrixCleaning()
	{
		//First pass: Mark all the rows, columns containing 0.
		int i, j;
		for(i=0; i <ROW; i++)
		{
			for(j=0; j <COL; j++)
			{
				if(a[i][j] == 0)
				{
					markedRow[i] = true;
					markedCol[j] = true;
				}
			}
		}
		//Second pass: Set all elements of the rows, columns containing 0 to 0.
		for(i=0; i< ROW; i++)
			if(markedRow[i])
				CleanRow(i);

		for(j=0; j< COL; j++)
			if(markedCol[j])
				CleanCol(j);	

	}

	void CleanRow(int row)
	{
		for(int i=0; i< COL; i++)
			a[row][i] = 0;
			markedRow[row] = true;

	}

	void CleanCol(int col)
	{
		for(int i=0; i< ROW; i++)
			a[i][col] = 0;
			markedCol[col] = true;		
	}

	void PrintMatrix()
	{
		for(int i=0; i <ROW; i++)
		{
			for(int j=0; j <COL; j++)
			{
				cout<<a[i][j]<< "\t";
			}
			cout<<endl;
		}
	}
};


int main()
{
	IntMatrix intMat;
	intMat.PrintMatrix();
	intMat.MatrixCleaning();
	cout<<endl<<"After Cleaning"<<endl;
	intMat.PrintMatrix();
	return 0;
}