#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib> 
#include<ctime>
#include <fstream>
#include <algorithm>

using namespace std;

class initialization
{
public :
	void initialize_stu_information(FILE* fp1); //��ʼ��ѧ����Ϣ
	void initialize_dep_information(FILE* fp1);//��ʼ��������Ϣ
	void initialize_mark_freetime(int sid); 
	void GraFirst(); //�Լ�������ԭ������
	void InterestFirst(); //����Ȥ����ԭ������
	int  time_is_ok(int sid, int did);//�ж�ʱ���Ƿ��ͻ
	bool InterestMatching(int sid, int did);//�ж���Ȥ�Ƿ�ƥ��
	void print_output_GF();//�Լ�������ԭ������������
	void print_output_IF();//����Ȥ����ԭ������������
};

