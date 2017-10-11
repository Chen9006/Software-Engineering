#include "initialization.h"


int voluntary_flag[21] = { 0 };
int stu_freetime_day_flag[10] = { 0 };
int mark_count_stu[301] = { 0 };

int count_stu = 300;

struct student
{
	int sid; // ѧ�����
	double gpa; // ѧ������
	string interest[12];//��Ȥ��ǩ
	int interest_cnt;//��Ȥ��ǩ����
	int voluntary[5]; //ѧ��־Ը����
	int start_freetime[10][2];//ѧ�����п�ʼʱ��
	int end_freetime[10][2];//ѧ�����н���ʱ��
	int freetime_cnt;//ѧ������ʱ�����
	vector<int>admission_dep;//����Ĳ��ű��
	bool mark_freetime[10];//���ĳ������ʱ����Ƿ����в��Ż
} stu[301];

struct department
{
	int did; //���ű��
	int num; //��������
	int numrest; //ʣ��ϯλ
	string feature[12];//�ص��ǩ
	int feature_cnt; //�ص��ǩ����
	int start_hdtime[2][2];//���Ż��ʼʱ��
	int end_hdtime[2][2];//���Ż����ʱ��
	int hdtime_cnt;//���Żʱ�����
	vector<struct student> res; //ƥ���ѧ����Ϣ
} dep[21];

string bq[12] = { "�˶�","��ѧ","���´�ҵ","��ҵ����","����","���ջ���","�������Ųɼ�","�ලУ��У��","���","Э��ѧ������ع���","Ӫ��У԰ѧϰ��Χ","������˼�뽨��" };



bool cmp_sid(student s1, student s2)
{
	return (s1.sid < s2.sid);
}

bool cmp_max_gpa(student s1, student s2)
{
	return (s1.gpa > s2.gpa);
}

void initialization::initialize_mark_freetime(int sid)
{
	for (int i = 0; i < 10; i++)
	{
		stu[sid].mark_freetime[i] = false;
	}
}

int initialization::time_is_ok(int sid, int did)
{
	for (int i = 0; i < stu[sid].freetime_cnt; i++)
	{
		for (int j = 0; j < dep[did].hdtime_cnt; j++)
		{
			if (!stu[i].mark_freetime[i] && stu[sid].start_freetime[i][0] == dep[did].start_hdtime[j][0] && stu[sid].start_freetime[i][1] <= dep[did].start_hdtime[j][1] && stu[sid].end_freetime[i][1] >= dep[did].end_hdtime[j][1])
				return i;
		}
	}

	return -1; //��ʾʱ���ͻ
}

bool initialization::InterestMatching(int sid, int did)
{
	for (int i = 0; i < stu[sid].interest_cnt; i++)
	{
		for (int j = 0; j < dep[did].feature_cnt; j++)
		{
			if (stu[did].interest[i] == dep[did].feature[j])
				return true;
		}
	}

	return false;
}

void initialization::initialize_stu_information(FILE* fp1)
{
	int a;
	for (int i = 1; i < 301; i++)
	{
		initialize_mark_freetime(i);

		fscanf(fp1, "%d", &stu[i].sid);
		//printf("%d\n", stu[i].sid);

		fscanf(fp1, "%lf", &stu[i].gpa);


		fscanf(fp1, "%d", &stu[i].interest_cnt);


		for (int j = 0; j < stu[i].interest_cnt; j++)
		{
			fscanf(fp1, "%d", &a);
			stu[i].interest[j] = bq[a];
		}

		fscanf(fp1, "%d", &a);

		for (int j = 0; j < 5; j++)
		{

			int a1;
			fscanf(fp1, "%d", &stu[i].voluntary[j]);

		}

		fscanf(fp1, "%d", &stu[i].freetime_cnt);

		for (int j = 0; j < stu[i].freetime_cnt; j++)
		{
			fscanf(fp1, "%d %d %d", &stu[i].start_freetime[j][0], &stu[i].start_freetime[j][1], &stu[i].end_freetime[j][1]);
			stu[i].end_freetime[j][0] = stu[i].start_freetime[j][0];
		}
	}

}

void initialization::initialize_dep_information(FILE* fp1)
{
	int a;
	for (int i = 1; i < 21; i++)
	{
		fscanf(fp1, "%d", &dep[i].did);
		//printf("%d\n", dep[i].did);

		fscanf(fp1, "%d", &dep[i].num);
		dep[i].numrest = dep[i].num;
		fscanf(fp1, "%d", &dep[i].feature_cnt);

		for (int j = 0; j < dep[i].feature_cnt; j++)
		{
			fscanf(fp1, "%d", &a);
			dep[i].feature[j] = bq[a];
		}
		fscanf(fp1, "%d", &dep[i].hdtime_cnt);

		for (int j = 0; j < dep[i].hdtime_cnt; j++)
		{
			fscanf(fp1, "%d %d %d", &dep[i].start_hdtime[j][0], &dep[i].start_hdtime[j][1], &dep[i].end_hdtime[j][1]);
			dep[i].end_hdtime[j][0] = dep[i].start_hdtime[j][0];

		}
	}
}


void initialization::GraFirst()
{
	sort(stu, stu + 301, cmp_max_gpa);

	for (int j = 0; j <= 4; j++)
	{
		for (int i = 1; i <= 300; i++)
		{

			int temp = stu[i].voluntary[j];
			if (dep[temp].numrest <= 0) continue;

			int mark = time_is_ok(i, temp);

			if (mark == -1) continue;


			else
			{
				stu[i].mark_freetime[mark] = true;//��Ǹ�ʱ������в��Ż
				dep[temp].res.push_back(stu[i]); //��ѧ����Ϣ���벿�ŵ�ƥ��vector��
				stu[i].admission_dep.push_back(temp);//�����ű�ż���ѧ��ƥ�䲿�ű��vector��
				if (dep[temp].numrest > 0)
					dep[temp].numrest--; //ʣ��ϯλ-1
			}

		}
	}
}

void initialization::InterestFirst()
{
	for (int j = 0; j <= 4; j++)
	{
		for (int i = 1; i <= 300; i++)
		{
			int temp = stu[i].voluntary[j];
			if (dep[temp].numrest <= 0) continue;

			int mark = time_is_ok(i, temp);

			if (mark == -1) continue;

			else if (InterestMatching(i, temp))
			{
				stu[i].mark_freetime[mark] = true;//��Ǹ�ʱ������в��Ż
				dep[temp].res.push_back(stu[i]); //��ѧ����Ϣ���벿�ŵ�ƥ��vector��
				stu[i].admission_dep.push_back(temp);//�����ű�ż���ѧ��ƥ�䲿�ű��vector��
				if (dep[temp].numrest > 0)
					dep[temp].numrest--; //ʣ��ϯλ-1
			}

		}

	}

}

void initialization::print_output_GF()
{
	freopen("./output_GF.txt", "w", stdout);

	for (int i = 1; i <= 20; i++)
	{
		printf("��%d�����ŵ����������\n", dep[i].did);

		if (!dep[i].res.empty())
		{
			printf("Ԥ������������%d ʵ������������%d\n", dep[i].num, dep[i].res.size());

			vector<struct student>::iterator iter = dep[i].res.begin();
			sort(dep[i].res.begin(), dep[i].res.end(), cmp_max_gpa);
			for (iter; iter != dep[i].res.end(); ++iter)
			{
				cout << "ѧ����ţ�" << iter->sid << " " << "ѧ������ : " << iter->gpa << " " << endl;
				if (mark_count_stu[iter->sid] == 0)
				{
					mark_count_stu[iter->sid] = 1;
					count_stu--;
				}
			}
			printf("\n");

		}
		else
		{
			printf("��ǰ����ѡ��ò���\n");
			printf("\n");
			continue;
		}

		printf("\n");
	}

	printf("\n");
	printf("\n");

	printf("---------------------------------------------\n");

	printf("\n");
	printf("\n");

	sort(stu, stu + 301, cmp_sid);

	for (int i = 1; i <= 300; i++)
	{
		vector<int>::iterator iter = stu[i].admission_dep.begin();
		printf("���Ϊ%d��ѧ�����벿�������\n", stu[i].sid);
		if (!stu[i].admission_dep.empty())
		{

			for (iter; iter != stu[i].admission_dep.end(); ++iter)
			{
				cout << "���ű�ţ�" << *iter << " " << endl;
			}
		}
		else
		{
			printf("��ǰδ�����κβ���\n");
		}

		printf("\n");
		printf("\n");

	}

	printf("������%d��ѧ��δ�����κβ���\n", count_stu);
	fclose(stdout);
}

void initialization::print_output_IF()
{
	freopen("./output_IF.txt", "w", stdout);

	for (int i = 1; i <= 20; i++)
	{
		printf("��%d�����ŵ����������\n", dep[i].did);

		if (!dep[i].res.empty())
		{
			printf("Ԥ������������%d ʵ������������%d\n", dep[i].num, dep[i].res.size());

			vector<struct student>::iterator iter = dep[i].res.begin();
			sort(dep[i].res.begin(), dep[i].res.end(), cmp_sid);
			for (iter; iter != dep[i].res.end(); ++iter)
			{
				cout << "ѧ����ţ�" << iter->sid << " ";
				cout << "ѧ����Ȥ : ";
				for (int k = 0; k < iter->interest_cnt; k++)
				{
					cout << iter->interest[k] << " ";
				}
				cout << endl;
				if (mark_count_stu[iter->sid] == 0)
				{
					mark_count_stu[iter->sid] = 1;
					count_stu--;
				}

			}
			printf("\n");
		}
		else
		{
			printf("��ǰ����δ����ѧ��\n");
			printf("\n");
			continue;
		}

		printf("\n");
	}

	printf("\n");
	printf("\n");

	printf("---------------------------------------------\n");

	printf("\n");
	printf("\n");

	sort(stu, stu + 301, cmp_sid);

	for (int i = 1; i <= 300; i++)
	{
		vector<int>::iterator iter = stu[i].admission_dep.begin();
		printf("���Ϊ%d��ѧ�����벿�������\n", stu[i].sid);
		if (!stu[i].admission_dep.empty())
		{

			for (iter; iter != stu[i].admission_dep.end(); ++iter)
			{
				cout << "���ű�ţ�" << *iter << " " << endl;
			}
		}
		else
		{
			printf("��ǰδ�����κβ���\n");
		}

		printf("\n");
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("������%d��ѧ��δ�����κβ���\n", count_stu);
	fclose(stdout);
}





