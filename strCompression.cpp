#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string ConvertToString(int x)
{
	//using osstream to convert int to string
	cout<<x<<endl;
	string returnVal;
	std::ostringstream os;
	os << x;
	returnVal = os.str();
	return returnVal;
}

string CompressStr(string str)
{
	char tmp;
	string strTmp;
	int count = 1;
	string returnStr = "";
	tmp = str[0];
	for(int i=1; i < str.length(); i++)
	{
		if(str[i] == tmp)
		{
			count++;
		}
		else
		{
			strTmp = ConvertToString(count);
			cout<<"tmp:"<<strTmp<<endl;
			returnStr += tmp + strTmp;
			count = 1;
			tmp = str[i];
		}
	}
	strTmp = ConvertToString(count);
	returnStr += tmp + strTmp;
	return returnStr.length()<str.length()?returnStr:str;
}


int main()
{
	string str = "aaabbcccddaa123123";
	cout <<str<<endl;
	string result = CompressStr(str);
	cout<<"result:"<<result <<endl;
	return 0;
}