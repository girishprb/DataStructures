/*Takes two strings as inputs and checks if the two strings are permutations of each other*/
#include<iostream>
#include<map>
#include<string>

using namespace std;

std::map<char, int> ComputeHash(string str)
{
    std::map<char, int> hashMap;
    std::map<char, int>::iterator it;
    //Logic
    for(int i=0; i < str.length(); i++)
    {
        it = hashMap.find(str[i]);
        //First occurance
        if(it == hashMap.end())
        {
            hashMap.insert( std::pair<char,int>(str[i], 1) );
        }
        //Collision
        else
        {
            it->second++;
        }
    }
    return hashMap;
}

void PrintHashmap(std::map<char, int> hashMap)
{
    std::map<char, int>::iterator it;
    for(it = hashMap.begin(); it != hashMap.end(); it++)
        cout<<"Hash key:" << it->first <<"---> value:"<<it->second<<endl;

}

int main()
{
    //Variables declaration
    bool isPermute = true;
    string str1, str2;
    std::map<char, int> hashMap1, hashMap2;
    std::map<char, int>::iterator it1, it2;
    //User input section
    cout<<"Please enter a string 1:"<<endl;
    cin>>str1;
    cout<<"Please enter a string 2:"<<endl;
    cin>>str2;


    //If the lengths are not same, they cannot be permutations
    if(str1.length() != str2.length())
    {
        isPermute = false;
    }
    else
    {
        hashMap1 = ComputeHash(str1);
        hashMap2 = ComputeHash(str2);

        cout<<"Printing hashmap of str1"<<endl;
        PrintHashmap(hashMap1);

        cout<<"Printing hashmap of str2"<<endl;
        PrintHashmap(hashMap2);


        //Logic
        for( it1 = hashMap1.begin(), it2= hashMap2.begin(); it1 != hashMap1.end() && it2 != hashMap2.end(); it1++, it2++)
        {
            if(it1->first != it2->first || it1->second != it2->second)
            {
                isPermute = false;
            }
        }

        if(it1 != hashMap1.end() || it2 != hashMap2.end())
            isPermute = false;
    }
    //results
    if(isPermute)
        cout<< "Both strings are permutations of each other\n";
    else
        cout<< "Both strings are not permutations of each other\n";

    return 0;
}
