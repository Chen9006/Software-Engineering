#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <direct.h>

using namespace std;

class generator
{
public:
	void generate_sudoku();          //��ȡ�����
	int get_random_number();      //������������
	void print_sudoku();               //��ӡ��������
	void generate_txt(string str); //����������д���ļ�
};

