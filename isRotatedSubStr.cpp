/*Determines if the in given two strings, the second one is rotated from the first one
Eg: str1 = Hello, str2 = loHel*/

#include<iostream>
#include<string>
using namespace std;

bool IsRevSubStr(string str1, string str2)
{
	bool result = false;
	if(str1.length() != str2.length() || str2.length() ==0)
		result = false;
	else
	{
		//Create a temporary string such that str1 contains in that if the str2 is truely reversed
		string tmp = str2 +str2;
		cout<<"Tmp:"<<tmp<<endl;
		//Find returns string::npos if there is no match found. Else it returns the position of the first matched string.
		if(tmp.find(str1) != string::npos)
		{
				result = true;
		}
	}

	return result;
}

int main()
{
	string str1, str2;
	cout<<"Input string 1:";
	cin>>str1;
	cout<<"Input string 2:";
	cin>>str2;
	bool result = IsRevSubStr(str1, str2);
	if(result)
		cout<<"Result: true"<<endl;
	else
		cout<<"Result: false"<<endl;

	return 0;
}