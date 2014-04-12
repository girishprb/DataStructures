/*Reverse a null terminated string in memory */
#include<iostream>

using namespace std;

int main()
{
	//Variables declaration
	char* userInput = "asd";
	char tmp;
	char *f_ptr= userInput, *b_ptr = userInput;
	int i = 0;

	//Traverse through to end of the string
	while(*b_ptr!= '\0')
	{
		b_ptr++;
	}

	cout<<"Done with the traversal"<<endl;
	//Come one step back so as to preseve the null character
	b_ptr--;

	//Swap first and last character at a time
	while(f_ptr < b_ptr)
	{
		cout<<"f_ptr:"<<*f_ptr<<"; b_ptr:"<<b_ptr<<endl;
		tmp = *f_ptr;
		*f_ptr = *b_ptr;
		*b_ptr = tmp;
		//Increment the front pointer
		f_ptr++;

		//Decrement the  back pointer
		b_ptr--;		
	}

	//print the reversed string
	cout<<userInput<< endl;
	return 0;
}
