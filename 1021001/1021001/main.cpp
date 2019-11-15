#include <iostream>
#include<stdio.h>
using namespace std;

int find(int a,int b){
	//构造优先关系表
	int table[6][6]={
		//数字1代表>   数字-1代表<     数字2代表空
		1,-1,-1,-1,1,1,
		1,1,-1,-1,1,1,
		1,1,2,2,1,1,
		-1,-1,-1,-1,0,2,
		1,1,2,2,1,1,
		-1,-1,-1,-1,2,0
	};
	return table[a-1][b-1];
}

int in_vt(char c)          //根据返回值到优先关系表里查找优先关系
{
	int n;
	switch(c)
	{
		case '+':n=1;break; case '*':n=2;break;
		case 'i':n=3;break;case '(':n=4;break;
		case ')':n=5;break; case'#':n=6;break;
		default: n=0;  //非终结符返回0
	}
	return n;
}
int judge(char *p,int k,char *psc)
{
	if(k==1&& p[k]=='#'  &&(*psc=='+' || *psc=='*'))
	{
		cout<<"\n运算符前无操作数\n";
		return 0;
	}
	if((*psc=='+' || *psc=='*') && (*(psc+1)=='+' || *(psc+1)=='*'))
	{
		cout<<"\n运算符号不能相邻\n";
		return 0;
	}
	if(*psc=='#' && (*(psc-1)=='+' || *(psc-1)=='*'))
	{
		cout<<"\n运算符后无操作数\n";
		return 0;

	}
	return 1;
}

int main(){
	char in_c[50]={'\0'};                       //输入串
	int n;
	int j;
	int k;                               //栈顶指针
	char s[30]={'\0'};                //分析栈
	char *ss;
	char *psc;                       //指向当前输入符号
	char q;
	int flag;
	while(1){
		cout<<"请输入要归约的字符串（以‘#’结束）"<<endl;
		cout<<"例如：（i+i)*i"<<endl;
		cin>>in_c;//输入串
		n=1;                          //记录步骤
		k=1;
		s[k]='#';
		s[k+1]='\0';                 //初始化
		ss=s+1;                      //指向栈底
		psc=in_c;
		
		cout<<"\n步骤\t符号栈S\t\t优先关系\t当前符号\t输入串Str\t\n";
		while(1)
		{
			if(judge(s,k,psc)==0)
			{
				cout<<"\n出错！\n";
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
					cout<<"\n归约成功！"<<endl;
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
				//cout<<"("<<n++<<")\t"<<ss<<"无\t\t"<<*psc<<"\t\t"<<psc+1<<endl;
				printf("(%d)\t%-24s无\t\t%-32s\\\n",n++,ss,*psc,psc+1);
				cout<<"\n错误!\n";
				break;
			}
		}
	}
	return 0;
}