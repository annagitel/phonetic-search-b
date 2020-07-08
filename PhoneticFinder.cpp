#include <iostream>
#include <cstring>
#include "PhoneticFinder.hpp"
using namespace std;
namespace phonetic{

	string change(string word)
	{
		string str("");
		for(int i=0;i<word.length();i++)
		{
			char letter=tolower(word.at(i));
			if(letter=='v' || letter=='w')
				str+='1';
			else if(letter=='b' || letter=='f' || letter=='p')
				str+='2';
			else if(letter=='g' || letter=='j')
				str+='3';
			else if(letter=='c' || letter=='k' || letter=='q')
				str+='4';
			else if(letter=='s' || letter=='z')
				str+='5';
			else if(letter=='d' || letter=='t')
				str+='6';
			else if(letter=='o' || letter=='u')
				str+='7';
			else if(letter=='i' || letter=='y')
				str+='8';
			else
				str+=letter;
		}

		return str;
	}

	bool similar(string word, string second) {
		string s1=change(word);
		string s2=change(second);
		if(s1.length()!=s2.length())
			return false;
		if(s1.compare(s2)==0)
			return true;
		else
			return false;
	}

	string find(string temp, string word){
		string text = temp + '\0';
		int i=0, j=0;
		if(word.compare("") == 0 || word.compare(" ") == 0)
			throw "Illegal input";
		if(text.compare("") == 0 || text.compare(" ") == 0)
			throw "Illegal input";

		while(i<text.length()){
			if(text.at(i) == ' ' || i == text.length()-1){
				char str[i-j+1];
				memset(str, 0, i-j+1);
				text.copy(str, i-j, j);
				if(similar(str, word))
					return str;
				j=i+1;
			}
			i++;

		}
		throw runtime_error("word wasn't found\"" + word +"\"");
	}

}


