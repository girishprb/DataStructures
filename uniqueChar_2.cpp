/*Use Hashmap to check for collisions, maintain the counts*/
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	//Variables declaration
	bool isUnique = true;
	string userInput;
	std::map<char, int> hashMap;
	std::map<char, int>::iterator it;
	//User input section
	cout<<"Please enter a string to check if all characters are unique:";
	cin>>userInput;

	//Logic
	for(int i=0; i < userInput.length(); i++)
	{
		it = hashMap.find(userInput[i]);
		//First occurance
		if(it == hashMap.end())
		{
			hashMap.insert( std::pair<char,int>(userInput[i], 1) );
		}
		//Collision
		else
		{
			isUnique = false;
			it->second++;
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
	}

	cout<<"Printing the contents of the hap table\n";
	for(it = hashMap.begin(); it != hashMap.end(); it++)
		cout<<"Hash key:" << it->first <<"---> value:"<<it->second<<endl;

	return 0;
}
