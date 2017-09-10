#include "generator.h"


int begin_board[3][3];  //������������3*3����(��������)

int sudoku_board[10][10];
//������������9*9����(9*9���̷ֳ�9��3*3������䣬�������ң����ϵ��¼�ΪM1,M2, ... ,M8��M9����)

int flag[10]; //�ж�������Ƿ��ظ�

int  unsigned seed = time(NULL);

int  generator::get_random_number() //��ȡ�����
{
	srand(seed);
	seed = rand();
	return (rand() % 9 + 1);
}

void generator::generate_sudoku() //������������
{

	memset(begin_board, 0, sizeof(begin_board));
	memset(flag, 0, sizeof(flag));
	memset(sudoku_board, 0, sizeof(sudoku_board));


	/*
	 ���ɻ���3*3����
	*/

	int count = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; ; j++)
		{
			int temp = get_random_number();
			//cout << temp << endl;
			if (flag[temp] == 0)
			{
				begin_board[i][count] = temp;
				flag[temp] = 1;
				count++;
				if (count == 3)
				{
					count = 0;
					break;
				}
			}
		}



	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			sudoku_board[i + 3][j + 3] = begin_board[i][j];  // ����9*9���̵����ĵ�3*3����(M5)

			/*
			 �Ի������̽����б任����������չ������M4,M6
			*/

			switch (i)
			{
			case 0:
				sudoku_board[i + 4][j] = begin_board[i][j];  // ���9*9���̵�[4][0~2]λ��
				sudoku_board[i + 5][j + 6] = begin_board[i][j];  // ���9*9���̵�[5][6~8]λ��
				break;

			case 1:
				sudoku_board[i + 4][j] = begin_board[i][j];  // ���9*9���̵�[5][0~2]λ��
				sudoku_board[i + 2][j + 6] = begin_board[i][j];  // ���9*9���̵�[3][6~8]λ��
				break;

			case 2:
				sudoku_board[i + 1][j] = begin_board[i][j];  // ���9*9���̵�[3][0~2]λ��
				sudoku_board[i + 2][j + 6] = begin_board[i][j];  // ���9*9���̵�[4][6~8]λ��
				break;
			}

			/*
			  �Ի������̽����б任�����ϣ�������չ������M2��M8
			*/

			switch (j)
			{
			case 0:
				sudoku_board[i][j + 4] = begin_board[i][j];  // ���9*9���̵�[0~2][4]λ��
				sudoku_board[i + 6][j + 5] = begin_board[i][j];  // ���9*9���̵�[6~8][5]λ��
				break;

			case 1:
				sudoku_board[i][j + 4] = begin_board[i][j];  // ���9*9���̵�[0~2][5]λ��
				sudoku_board[i + 6][j + 2] = begin_board[i][j];  // ���9*9���̵�[6~8][3]λ��
				break;

			case 2:
				sudoku_board[i][j + 1] = begin_board[i][j];  // ���9*9���̵�[0~2][3]λ��
				sudoku_board[i + 6][j + 2] = begin_board[i][j];  // ���9*9���̵�[6~8][4]λ��
				break;
			}
		}

	/*
		   ��M2��Ϊ�������̽����б任������������չ������M1��M3
	*/

	for (int i = 0; i <= 2; i++)
		for (int j = 3; j <= 5; j++)
		{
			switch (i)
			{
			case 0:
				sudoku_board[i + 1][j - 3] = sudoku_board[i][j];  // ���9*9���̵�[1][0~2]λ��
				sudoku_board[i + 2][j + 3] = sudoku_board[i][j];  // ���9*9���̵�[2][6~8]λ��
				break;

			case 1:
				sudoku_board[i + 1][j - 3] = sudoku_board[i][j];  // ���9*9���̵�[2][0~2]λ��
				sudoku_board[i - 1][j + 3] = sudoku_board[i][j];  // ���9*9���̵�[0][6~8]λ��
				break;

			case 2:
				sudoku_board[i - 2][j - 3] = sudoku_board[i][j];  // ���9*9���̵�[0][0~2]λ��
				sudoku_board[i - 1][j + 3] = sudoku_board[i][j];  // ���9*9���̵�[1][6~8]λ��
				break;
			}
		}


	/*
	��M8��Ϊ�������̽����б任������������չ������M7��M9
	*/

	for (int i = 6; i <= 8; i++)
		for (int j = 3; j <= 5; j++)
		{
			switch (i)
			{
			case 6:
				sudoku_board[i + 1][j - 3] = sudoku_board[i][j];  // ���9*9���̵�[7][0~2]λ��
				sudoku_board[i + 2][j + 3] = sudoku_board[i][j];  // ���9*9���̵�[9][6~8]λ��
				break;

			case 7:
				sudoku_board[i + 1][j - 3] = sudoku_board[i][j];  // ���9*9���̵�[8][0~2]λ��
				sudoku_board[i - 1][j + 3] = sudoku_board[i][j];  // ���9*9���̵�[6][6~8]λ��
				break;

			case 8:
				sudoku_board[i - 2][j - 3] = sudoku_board[i][j];  // ���9*9���̵�[6][0~2]λ��
				sudoku_board[i - 1][j + 3] = sudoku_board[i][j];  // ���9*9���̵�[9][6~8]λ��
				break;
			}
		}

}

void generator::print_sudoku() //��ӡ��������
{

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cout << sudoku_board[i][j] << " ";
			if (j == 8)cout << endl;
		}


	cout << endl;
	cout << endl;

}

void generator::generate_txt(string str) //����������д���ļ�
{
	
	string str1 = str + "/sudoku.txt";
	//cout << str1 << endl;

	ofstream txt(str1, ios::app);
	//txt.open(str1);




	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			txt << sudoku_board[i][j] << " ";

			if (j == 8) txt << endl;
		}

	txt << endl;
	txt << endl;
	txt.close();
}
