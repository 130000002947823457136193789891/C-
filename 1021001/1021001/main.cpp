#include <iostream>
#include<stdio.h>
using namespace std;

int find(int a,int b){
	//�������ȹ�ϵ��
	int table[6][6]={
		//����1����>   ����-1����<     ����2�����
		1,-1,-1,-1,1,1,
		1,1,-1,-1,1,1,
		1,1,2,2,1,1,
		-1,-1,-1,-1,0,2,
		1,1,2,2,1,1,
		-1,-1,-1,-1,2,0
	};
	return table[a-1][b-1];
}

int in_vt(char c)          //���ݷ���ֵ�����ȹ�ϵ����������ȹ�ϵ
{
	int n;
	switch(c)
	{
		case '+':n=1;break; case '*':n=2;break;
		case 'i':n=3;break;case '(':n=4;break;
		case ')':n=5;break; case'#':n=6;break;
		default: n=0;  //���ս������0
	}
	return n;
}
int judge(char *p,int k,char *psc)
{
	if(k==1&& p[k]=='#'  &&(*psc=='+' || *psc=='*'))
	{
		cout<<"\n�����ǰ�޲�����\n";
		return 0;
	}
	if((*psc=='+' || *psc=='*') && (*(psc+1)=='+' || *(psc+1)=='*'))
	{
		cout<<"\n������Ų�������\n";
		return 0;
	}
	if(*psc=='#' && (*(psc-1)=='+' || *(psc-1)=='*'))
	{
		cout<<"\n��������޲�����\n";
		return 0;

	}
	return 1;
}

int main(){
	char in_c[50]={'\0'};                       //���봮
	int n;
	int j;
	int k;                               //ջ��ָ��
	char s[30]={'\0'};                //����ջ
	char *ss;
	char *psc;                       //ָ��ǰ�������
	char q;
	int flag;
	while(1){
		cout<<"������Ҫ��Լ���ַ������ԡ�#��������"<<endl;
		cout<<"���磺��i+i)*i"<<endl;
		cin>>in_c;//���봮
		n=1;                          //��¼����
		k=1;
		s[k]='#';
		s[k+1]='\0';                 //��ʼ��
		ss=s+1;                      //ָ��ջ��
		psc=in_c;
		
		cout<<"\n����\t����ջS\t\t���ȹ�ϵ\t��ǰ����\t���봮Str\t\n";
		while(1)
		{
			if(judge(s,k,psc)==0)
			{
				cout<<"\n����\n";
				break;
			}

			if(in_vt(s[k]))
				j=k;
			else
				j=k-1;
			flag= find (in_vt(s[j]),in_vt(*psc));
			if(flag==1)
			{
				do{
					q=s[j];
					if(in_vt(s[j-1]))
						j--;
					else
						j=j-2;
				}while(find(in_vt(s[j]),in_vt(q))!=-1);
				printf("(%d)\t%-24s>\t\t%c\t\t%-32s\n",n++,ss,*psc,psc+1);
				k=j+1;
				s[k]='N';
				s[k+1]='\0';
				continue;
			}
			else if(flag==-1)
			{
				printf("(%d)\t%-24s<\t\t%c\t\t",n++,ss,*psc);
				//cout<<"("<<n++<<")\t"<<ss<<"\t\t"<<"<"<<"\t\t"<<
				k++;
				s[k]=*psc;
				s[k+1]='\0';
				psc++;
				cout<<psc<<endl;
				continue;
			}
			else if(flag==0)
			{
				if(s[j]=='#')
				{
					//cout<<"("<<n<<")\t"<<ss<<"\t\t#\t\n";
					printf("(%d)\t%-24s=\t\t#\t\n",n,ss);
					cout<<"\n��Լ�ɹ���"<<endl;
					break;
				}
				else
				{
					printf("(%d)\t%-24s=\t\t%c\t\t",n++,ss,*psc);
					//cout<<"("<<n++<<")\t"<<ss<<"\t\t"<<*psc<<"\t\t";
					k++;
					s[k]=*psc;
					s[k+1]='\0';
					psc++;
					cout<<psc<<endl;
					continue;
				}
			}
			else
			{
				//cout<<"("<<n++<<")\t"<<ss<<"��\t\t"<<*psc<<"\t\t"<<psc+1<<endl;
				printf("(%d)\t%-24s��\t\t%-32s\\\n",n++,ss,*psc,psc+1);
				cout<<"\n����!\n";
				break;
			}
		}
	}
	return 0;
}