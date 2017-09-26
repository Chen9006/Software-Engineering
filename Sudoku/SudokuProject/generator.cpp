#include "generator.h"

/*����Ҫ���������Ͻǵ�����ȷ��Ϊ��ѧ�ź���λ�ͣ�%9+1*/

int begin_board[3][3];  //������������3*3����(��������)

int sudoku_board[10][10];
//������������9*9����(9*9���̷ֳ�9��3*3������䣬�������ң����ϵ��¼�ΪM1,M2, ... ,M8��M9����)

int number[8] = { 1,2,3,4,5,6,7,9 };

char res[216];

int flag[10]; //�ж�������Ƿ��ظ�

int  unsigned seed = time(NULL);

int q_flag = 0;

int  generator::get_random_number() //��ȡ�����
{
	srand(seed);
	seed = rand();
	return (rand() % 9 + 1);
}

void generator::generate_sudoku() //������������
{

	//memset(begin_board, 0, sizeof(begin_board));
	memset(flag, 0, sizeof(flag));
	memset(sudoku_board, 0, sizeof(sudoku_board));


	/*
	���ɻ���3*3����
	*/

	int count = 0;

	if (q_flag == 0)
	{
		if (next_permutation(number, number + 8))
		{

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 3; j++)
				{
					begin_board[i][j] = number[count];
					count++;
				}


			begin_board[2][0] = number[count];
			count++;
			begin_board[2][1] = number[count];
			count++;
			begin_board[2][2] = 8;
		}
		else
		{
			int count = 0;
			int num = 0;

			flag[8] = 1;

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
						num++;

						if (count == 3)
						{
							count = 0;
							break;
						}

						if (num == 8) break;

					}
				}

			begin_board[2][2] = 8;
		}

		q_flag = 1;
	}
	else
	{
		q_flag = 0;
	}

	if (q_flag == 0)
	{
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
					sudoku_board[i + 5][j] = begin_board[i][j];  // ���9*9���̵�[4][0~2]λ��
					sudoku_board[i + 4][j + 6] = begin_board[i][j];  // ���9*9���̵�[5][6~8]λ��
					break;

				case 1:
					sudoku_board[i + 2][j] = begin_board[i][j];  // ���9*9���̵�[5][0~2]λ��
					sudoku_board[i + 4][j + 6] = begin_board[i][j];  // ���9*9���̵�[3][6~8]λ��
					break;

				case 2:
					sudoku_board[i + 2][j] = begin_board[i][j];  // ���9*9���̵�[3][0~2]λ��
					sudoku_board[i + 1][j + 6] = begin_board[i][j];  // ���9*9���̵�[4][6~8]λ��
					break;
				}

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

	}

	else
	{
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


void generator::generate_txt(int num, char * str) //����������д���ļ�
{
	generator gene;

	freopen(str, "w", stdout);

	for (int k = 0; k < num; k++)
	{
		int len = 0;
		gene.generate_sudoku();

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				res[len++] = sudoku_board[i][j] + '0' ;
				res[len++]=' ';

				if (j == 8) res[len++] =' \n';
			}

		puts(res);
	}

	fclose(stdout);
}