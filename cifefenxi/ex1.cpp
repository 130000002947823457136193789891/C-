   

#include<iostream>  

#include<fstream>

#include <cstdio>

#include<string>

#include<cstdlib>

#include<sstream>

#include<stdlib.h>

#include<stdio.h>

//#include <regex>  

using namespace std;

#define max 100

//int转化为string
/*
1 guanjianzi
2 biaoshifu
3 changshu
4 yunsuanfu
5 jiefu
*/

string to_String1(int n)

{

	int m = n;

	int i = 0, j = 0;

	char s[max] ;

	char ss[max] ;

	while (m>0)

	{

		s[i++] = m % 10 + '0';

		m /= 10;

	}

	s[i] = '\0';

	cout << i << endl;

	i = i - 1;

	cout << i << endl;

	while (i >= 0)

	{

		ss[j++] = s[i--];

	}

	ss[j] = '\0';



	return ss;

}

int main()

{

	  

	

	ofstream so("output.txt",ios::trunc);

	ifstream  is;

	is.open("test.txt");

	int b = 0;//文件中字符串的长度

	int qqq[100] = {0};//存放有空格组成的字符串的位置

	int m = 0;//qqq数组的下标

	int qq[100] = {0};//存放出错出差位置

	int n = 0;//qq的下标

	string sss;//文件读取字符串所复值

	while (getline(is, sss))

	{     //判断字符串是否为空

		if (!sss.empty()) {

			string::size_type s = 0;//终结符的位置

			string::size_type c = 0;//字符为空格的个数

			b++;

			if (sss[0] == '/') {

				if (sss[1] == '/') {

					so << endl;

					continue;

				}

				if (sss[1] == '*') {

					if (sss[sss.size() - 1 == '/'] && sss[sss.size() - 2] == '*') {

						so << endl;

						continue;

					}

					else {

						string ddd;

						while (getline(is, ddd)) {

							if (!ddd.empty()) {

								if (ddd[ddd.size() - 1] == '/'&&ddd[ddd.size() - 2] == '*') {

									so << endl;

									break;

								}

								else {

									so << endl;

									continue;

								}

							}

						}

						continue;

					}

				}

			}

			for (string::size_type i = 0; i <sss.size(); i++)

			{

				if (sss[i] == ' ') {

					c = c + 1;

				}

			}

			if (c == sss.size()) {

				m++;

				qqq[m] = b;

				continue; }

			if(c!=sss.size()) {



				for (string::size_type i = 0; i < sss.size(); i++)

				{

					

					string::size_type j = i + 1;

					//判断字符为字母

					if (sss[i] <= 'z'&&sss[i] >= 'a')

					{

						if (i == sss.size() - 1)

						{

							string qs = "";

							for (; s < j; s++) {

								if (sss[s] != ' ') {

									qs = qs + sss[s];

								}

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << "," << qs<< ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "if") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs<<  ">,"; }
 
							 
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "double") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

						}

						switch (sss[j])

						{

						case'=': {

							string qs = "";

							string::size_type q = s;

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs<< ">,"; }

						 
							
					 
							
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "char") { so << "<1" << "," << qs<< ">,"; }

							else if (qs == "if") { so << "<1" << ","<< qs << ">,"; }

							else if (qs == "else") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "do") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else {

								if (sss[q] >= '0'&&sss[q] <= '9') {

									so << "LexicalError" << ",";

								}

								else {

								//	std::string s=qs;

								//	int num1=std::atoi(s.c_str());


									so << "<2" << "," << qs << ">,";

								}

							}

							break;

						}

						case'+': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs<<  ">,"; }

					 
							
						 
							
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "float") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "if") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "else") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs <<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;

						}

						case'<': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs <<  ">,"; }

						 
						 
							
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "if") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "while") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;

						}

						case'>': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs<<  ">,"; }
 
							
						 
							
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "if") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "while") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "return") { so << "<1" << "," <<qs<<">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;

						}

						

						

						case' ': {

							string qs = "";

							string::size_type q = s;

 							for (; s < j; s++) {

								if (sss[s] != ' ') {

									qs = qs + sss[s];

								}

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << "," << qs<< ">,"; }
 
							
							 
							
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "int") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "if") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else {

								if (sss[q] >= '0'&&sss[q] <= '9') {

									n++;

									qq[n] = b;

									so << "LexicalError" << ",";

									



								}

								else {

									so << "<2" << "," << qs << ">,";

								}

							}

							break;

						}

						case'-': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs <<  ">,"; }

						 
							
						 
							
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "if") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "return") { so << "<1" << "," << qs<<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;

						}

						case'*': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs<<  ">,"; }

						 
							
						 
						 
//							
 							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "float") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "if") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs << ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;

						}

						case'/': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs<<  ">,"; }
 
					//	 
							
						  	else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "if") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "while") { so << "<1" << ","<< qs << ">,"; }

							else if (qs == "do") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;

						}

						case'!': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs <<  ">,"; }
//
 							else if (qs == "float") { so << "<1" << ","<< qs<<  ">,"; }
//
 							else if (qs == "char") { so << "<1" << ","<< qs<<  ">,"; }
//
 							else if (qs == "if") { so << "<1" << ","<< qs<< ">,"; }

 							else if (qs == "else") { so << "<1" << ","<< qs<<  ">,"; }

 							else if (qs == "while") { so << "<1" << ","<< qs<<  ">,"; }

 							else if (qs == "do") { so << "<1" << ","<< qs<< ">,"; }
 
						 
							
 							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;

						}

						case'%': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "char") { so << "<1" << "," <<qs<< ">,"; }

							else if (qs == "if") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << "," << qs<< ">,"; }
 
							
					 
							
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;

						}

						case',': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "if") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs<<  ">,"; }

						 
					 
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;

						}

						case';': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "if") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs<<  ">,"; }

							 
						 
							
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;

						}

						case'(': {

							string qs = "";

							for (; s < j; s++) {

								if (sss[s] != '	') {

									qs = qs + sss[s];

								}

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "char") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "if") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "else") { so << "<1" << ","<< qs<<  ">,"; }
 
							 
							
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "do") { so << "<1" << ","<< qs <<  ">,"; }

							else if (qs == "return") { so << "<1" << ","<< qs<<  ">,"; }

							else { so << "<2" << "," << qs << ">,"; }

							break;



						}

						case')': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							if (qs == "void") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "int") { so << "<1" << ","<< qs << ">,"; }

							else if (qs == "float") { so << "<1" << ","<< qs<< ">,"; }

							else if (qs == "char") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "if") { so << "<1" << ","<< qs <<  ">,"; }

						 
							else if (qs == "long") { so << "<1" << ","<< qs<<  ">,"; }

							else if (qs == "else") { so << "<1" << "," << qs<<  ">,"; }

							else if (qs == "while") { so << "<1" << "," << qs << ">,"; }

							else if (qs == "do") { so << "<1" << "," << qs << ">,"; }

							else if (qs == "return") { so << "<1" << "," << qs << ">,"; }

							//else if(int.Parse(qs)>=0 && int.Parse(qs)<=65535) {so<<"<3"<<","<<qs<<">";}

							else {
								
								so << "<2" << "," << qs << ">,"; }

							break;

						}



						default:

							break;

						}





					}



					else if (sss[i] == '(') { so << "<5" << "," << "->,"; }

					else if (sss[i] == ')') { so << "<5" << "," << "->,"; }

					else if (sss[i] == '=') {

						if (sss[j] <= 'z'&&sss[j] >= 'a')

						{

							so << "<3" << "," << "->,";//*

						}

						else if (sss[j] == '=')

						{

							i = i + 1;

							s = j + 1;

							so << "<4" << "," << "->,";



						}

						else if (sss[j] <= '9'&&sss[j] >= '0')

						{



							so << "<3" << "," << "->,";

						}

						else if (sss[j] <= ' ')

						{

							i = i + 1;

							s = j + 1;

							so << "<3" << "," << "->,";

						}

					}

					else if (sss[i] == '>') {

						if (sss[j] <= 'z'&&sss[j] >= 'a')

						{



							so << "<3" << "," << "->,";//*

						}

						else if (sss[j] == '=')

						{

							i = i + 1;

							s = j + 1;

							so << "<4" << "," << "->,";



						}

						else if (sss[j] <= '9'&&sss[j] >= '0')

						{



							so << "<3" << "," << "->,";

						}

						else if (sss[j] == ' ') {

							s = j + 1;

							so << "<3" << "," << "->";

						}







					}

					else if (sss[i] == '<') {

						if (sss[j] <= 'z'&&sss[j] >= 'a')

						{



							so << "<4" << "," << "->,";

						}

						else if (sss[j] == '=')

						{

							i = i + 1;

							s = j + 1;

							so << "<4" << "," << "->,";



						}

						else if (sss[j] <= '9'&&sss[j] >= '0')

						{



							so << "<3" << "," << "->,";

						}

						else if (sss[j] == ' ') {

							s = j + 1;

							so << "<3" << "," << "->";

						}





					}

					else if (sss[i] == '!') {

						i = i + 1;

						s = j + 1;

						so << "<4" << "," << "->,";

					}

					else if (sss[i] == '&') {

						i = i + 1;

						s = j + 1;

						so << "<4" << "," << "->,";

					}

					else if (sss[i] == '|') {

						i = i + 1;

						s = j + 1;

						so << "<4" << "," << "->,";

					}

					else if (sss[i] == '+') {



						if (sss[j] == '=') {

							i = i + 1;

							s = j + 1;

							so << "<4" << "," << "->,";

						}

						else if (sss[j] == '+') {

							i = i + 1;

							s = j + 1;

							so << "<4" << "," << "->,";

						}

						else if (sss[j] <= 'z'&&sss[j] >= 'a')

						{



							so << "<4" << "," << "->,";

						}

						else if (sss[j] <= '9'&&sss[j] >= '0')

						{



							so << "<3" << "," << "->,";

						}

						else if (sss[j] == ' ') {

							s = j + 1;

							so << "<3" << "," << "->";

						}

					}//3

					else if (sss[i] == '-') { so << "<4" << "," << "->,"; }//4

					else if (sss[i] == '*') { so << "<4" << "," << "->,"; }//5

					else if (sss[i] == '/') {

						if (sss[j] == '/') {

							break;

						}

						so << "<4" << "," << "->,"; }//6

					else if (sss[i] == '%') { so << "<4" << "," << "->,"; }//7

					else if (sss[i] == ';') { so << "<5" << "," << "->,"; }

					else if (sss[i] == '{') { so << "<5" << "," << "->,"; }

					else if (sss[i] == '}') { so << "<5" << "," << "->,"; }

					else if (sss[i] == ',') { so << "<5" << "," << "->,"; }

					else if (sss[i] == ' ') { s = j; }

					else if (sss[i] >= '0'&&sss[i] <= '9') {

						if (i == sss.size() - 1)

						{

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							so << "<1" << "," << qs << ">,";

						}

						switch (sss[j])

						{

						case';': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							so << "<3" << "," << qs << ">,";//*

							break;

						}

						case')': {

							string qs = "";

							for (; s < j; s++) {

								qs = qs + sss[s];

							}

							s = j + 1;

							so << "<3" << "," << qs << ">,";//*

							break;

						}

						default:

							break;

						}

					}





				}

			}

			so << endl;

		}

		else {

			continue;

		}

	}

	is.close();

	if (qq[1]!=0) {

		string qw = "LexicalError(s) on line(s)";

		for (int i = 1; i < 100; i++) {

			if (qq[i] != 0) {

				for (int j = 1; j <100; j++)

				{

					if (qqq[j] != 0) {

						if (qq[i] < qqq[j]) {

							qq[i] = qq[i];

						}

						if (qq[i] > qqq[j]) {

							qq[i] = qq[i] - 1;

						}

					}

					else {

						break;

					}

				}

			}

			else

			{

				break;

			}

		}

		for (int k = 1; k < 100; k++)

		{

			if (qq[k] != 0) {

				int d = qq[k];

				string g = to_String1(d);

				qw = qw + g + ",";

			}

			else {

				break;

			}

		}

		so << endl;

		so << qw;

		

	}

	so.close();

	

	return 0;

}

