#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <direct.h>
#include <shlwapi.h>
#include <algorithm>

using namespace std;

class generator
{
public:
	void generate_sudoku();          //��ȡ�����
	int get_random_number();      //������������
	void generate_txt(int num, char * str); //����������д���ļ�
};