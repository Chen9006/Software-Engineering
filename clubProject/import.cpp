#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

string bq[12] = { "sports","lecture","cxcy","jyfw","jy","wyhy","wxjwcj","jdxfxj","cbhd","xzxxgz","yzxyxxqf","gqtsxjs"};

int main() {
	srand(time(NULL));
	FILE *fp1;
	fp1=fopen("import.txt","w");
	int i,j,cnt,test[21];
	for(i=1; i<=20; i++) {
		fprintf(fp1,"%d ",i);
		fprintf(fp1,"%d ",rand()%4+12);
		cnt=rand()%3+5;
		fprintf(fp1,"%d ",cnt);
		int l=rand()%12;
		for(j=0; j<cnt; j++) {
			l=(l+1)%12;
			fprintf(fp1,"%d ",l);
		}
		//fprintf(fp1,"\n");
		cnt=rand()%2+1;
		fprintf(fp1,"%d ",cnt);
		memset(test,0,sizeof(test));
		for(j=0; j<cnt;) {

			int day=rand()%7+1;
			if(test[day]==0) {
				int hour=rand() % 2 + 38;
				test[day]=1;
				j++;
				fprintf(fp1,"%d %d %d\n",day,hour,hour+3);
			}
		}
		fprintf(fp1,"\n");
	}

	for(i=1; i<=300; i++) {
		fprintf(fp1,"%d\n",i);
		fprintf(fp1,"%.2lf\n",(1 + rand() % 4 + double(rand() % 10) / 10));
		cnt=rand()%3+5;
		fprintf(fp1,"%d\n",cnt);
		int l=rand()%10;
		for(j=0; j<cnt; j++) {
			l=(l+1)%10;
			fprintf(fp1,"%d ",l);
		}
        fprintf(fp1,"\n");
		cnt=5;
		fprintf(fp1,"%d\n",cnt);
		memset(test,0,sizeof(test));
		for(j=0; j<cnt;) {

			int l=rand()%20+1;
			if(test[l]==0) {
				fprintf(fp1,"%d ",l);
				test[l]=1;
				j++;
			}
		}
	    fprintf(fp1,"\n");

		cnt=rand()%2+5;
		fprintf(fp1,"%d\n",cnt);
		memset(test,0,sizeof(test));
		for(j=0; j<cnt;) {

			int day=rand()%7+1;
			if(test[day]==0) {
				int hour=rand() % 3 + 36;
				test[day]=1;
				j++;
				fprintf(fp1,"%d %d %d\n",day,hour,rand()%3+hour+4);
			}
		}
		fprintf(fp1,"\n");
	}

	fclose(fp1);
	return 0;
}
/*
�ṩ���������20�����ţ�������������Ҫѧ������Ҫ������ޣ���������ֵ����[0,15]�ڣ�
�����ŵ��ص��ǩ��������ַ��������ŵĳ���ʱ��Σ�������ַ�/���ڣ���
300��ѧ��������������Ϣ����������ֵ����Ȥ��ǩ��������ַ�����
ÿ��ѧ���в�����5���Ĳ�����Ը��������Ը���ܿ�ȱ���Ϳ���ʱ��Σ�������ַ�/���ڣ���
ʵ��һ�������Զ������㷨������������Ϣ��������ź�ѧ�����ƥ����Ϣ
��һ��ѧ������ȷ�϶����������Ĳ��ţ�һ�����ſ��Է������ڵ�����Ҫ���ѧ������ѧ����
 �� δ�����䵽ѧ���Ĳ��� �� δ������ѡ�е�ѧ����*/


