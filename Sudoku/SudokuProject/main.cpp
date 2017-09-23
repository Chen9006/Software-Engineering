#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <ctype.h>
#include <shlwapi.h>
#include "generator.h"

using namespace std;


int main(int argc, char* argv[])
{
	string temp = argv[1];
	string str = argv[2];

	/*
	�������ֲ�ƥ�䣬����
	*/

	if (temp != "-c")
	{
		cout << "error : the name of the parameter is mismatching !" << endl;
		return 0;
	}

	/*
	�������Ƿ��ַ�������
	*/

	for (int i = 0; i<str.size(); i++)
	{
		if (isdigit(str[i])) continue;
		else
		{
			cout << "error : the parameter  is not a number !" << endl;
			return 0;
		}
	}

	stringstream stream;
	stream << str;

	int num;
	stream >> num;


	/*int num;
	cin >> num;*/
	
	 
	generator ge;  //ʵ��������

	ge.generate_txt(num,"./sudoku.txt");

	return 0;
}