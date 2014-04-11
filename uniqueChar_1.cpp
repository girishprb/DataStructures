#include<iostream>
#include<set>
#include<string>

using namespace std;

int main()
{
	//Variables declaration
	bool isUnique = true;
	string userInput;
	std::set<char> setBucket, duplicateBucket;
	std::set<char>::iterator it;
	std::pair<std::set<char>::iterator,bool> ret;
	
	//User input section
	cout<<"";
	cout<<"Please enter a string to check if all characters are unique:";
	cin>>userInput;

	//Logic
	for(int i=0; i < userInput.length(); i++)
	{
		ret = setBucket.insert(userInput[i]);
		if(ret.second == false)
		{
			isUnique = false;
			//Collision, there are non unique characters
			duplicateBucket.insert(userInput[i]);
		}			
	}

	//results
	if(isUnique)
	{
		cout<< "The string has all unique characters\n";
	}
	else
	{
		cout<< "The string has repeated characters\n";
		cout<<"Printing out the duplicate characters:";
		for (it = duplicateBucket.begin(); it != duplicateBucket.end(); ++it)
		{
    		cout << *it;
		}
	}

	cout << endl;
	return 0;
}
