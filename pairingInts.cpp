/*Given an unordered list of numbers find all pairs that add up to x.*/
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
	//Testing for 100 elements
	int arr[100], hashMap[100];

	//Generate 100 input values at random
	for(int i=0; i < 100; i++)
	{
		arr[i] = (rand() % (int)(100 + 1));
		hashMap[i] = 0;
	}

	//Display 100 values
	for(int i=0; i < 100; i++)
		cout<< arr[i] << "\t";

	//Logic
	for(int i=0; i < 100; i++)
	{
		hashMap[arr[i]]++;
		if(hashMap[100-arr[i]] != 0)
		{
			//Pair exists
			cout<<"pair: "<< arr[i]<<"--->"<<100-arr[i]<<endl;
			hashMap[arr[i]]=0;
			hashMap[100-arr[i]]=0;
		}
	}	

	return 0;
}