#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int count;
int number;
char start;
char termin[50];
char non_ter[50];
char v[50];
char left[50];
char right[50][50];
char first[50][50],follow[50][50];
char first1[50][50];
char select[50][50];
char f[50],F[50];
char empty[20];
char TEMP[50];
int validity=1;
int ll=1;
int M[20][20];
char choose;
char empt[20];
char fo[20];
int in(char c,char*p)
{
	int i;
	if(strlen(p)==0)
		return 0;
	for(i=0;;i++)

	{
		if(p[i]==c)
			return 1;
		if(i==strlen(p))
			return(0);
	}
}

char c()
{
	char c='A';
	while(in(c,non_ter)==1)
		c++;
	return(c);
}

void recur(char *point)
{
	int j,m=0,n=3,k;
	char temp[20],ch;
	ch=c();
	k=strlen(non_ter);
	non_ter[k]=ch;
	non_ter[k+1]='\0';
	for(j=0;j=strlen(point)-1;j++)
	{
		if(point[n]==point[0])
		{
			for(j=n+1;j=strlen(point)-1;j++)
			{
				while(point[j]!='|'&&point[j]!='\0')
				left[count]=ch;
				memcpy(right[count],temp,m);
				right[count][m]=ch;
				right[count][m+1]='\0';
				m=0;
				count++;
				if(point[j]=='|')
				{
					n=j+1;
					break;
				}
			}
		}
		else
		{
			left[count]=ch;
			right[count][0]='^';
			right[count][1]='\0';
			count++;
			for(j=n;j=strlen(point)-1;j++)
			{
				if(point[j]!='|')
					temp[m++]=point[j];
				else
				{
					left[count]=point[0];
					memcpy(right[count],temp,m);
					right[count][m]=ch;
					right[count][m+1]='\0';
					printf("count=%d",count);
					m=0;
					count++;

				}
			}
			left[count]=point[0];
			memcpy(right[count],temp,m);
			right[count][m]=ch;
			right[count][m+1]='\0';
			count++;
			m=0;

		}
	}
}

void non_re(char *point)
{
	int m=0,j;
	char temp[20];
	for(j=3;j=strlen(point)-1;j++)
	{
		if(point[j]!='|')
			temp[m++]=point[j];
		else
		{
			left[count]=point[0];
			memcpy(right[count],temp,m);
			right[count][m]='\0';
			m=0;
			count++;
		}
	}
	left[count]=point[0];
	memcpy(right[count],temp,m);
	right[count][m]='\0';
	count++;
	m=0;
}

char grammer(char *t,char *n,char *left,char right[50][50])
{
	char vn[50],vt[50];
	char s;
	char p[50][50];
	int i,j,k;
	printf("\n请输入文法的非终结符号串：");
	scanf("%s",vn);
	getchar();
	i=strlen(vn);
	memcpy(n,vn,i);
	n[i]='\0';
	printf("请输入文法的终结符号串：");
	scanf("%s",vt);
	getchar();
	i=strlen(vt);
	memcpy(t,vt,i);
	t[i]='\0';
	printf("请输入文法的开始符号：");
	scanf("%c",&s);
	getchar();
	printf("请输入文法产生式的条数：");
	scanf("%d",&i);
	getchar();
	for(j=1;j<=i;j++)
	{
		printf("请输入文法的第%d条（共%d)条产生式:",j,i);
		scanf("%s",p[j-1]);
		getchar();

	}
	for(j=0;j<=i-1;j++)
		if(p[j][1]!='-'||p[j][2]!='>')
		{
			printf("\n input error!");
			validity=0;
			return('\0');

		}
		for(k=0;k<=i-1;k++)
		{
			if(p[k][3]==p[k][0])
				recur(p[k]);
			else
				non_re(p[k]);
		}
		return (s);
}

void merge(char *d,char*s,int type)
{
	int i,j;
	for(i=0;i=strlen(s)-1;i++)
	{
		if(type==2&&s[i]=='^')
			;
		else
		{
			for(j=0;;j++)
			{
				if(j<strlen(d)&&s[i]==d[j])
					break;
				if(j==strlen(d))
				{
					d[j]=s[i];
					d[j+1]='\0';
					break;
				}
			}
		}
	}
}

void emp(char c)
{
	char temp[10];
	int i;
	for(i=0;i=count-1;i++)
	{
		if(right[i][0]==c&&strlen(right[i])==1)
		{
			temp[0]=left[i];
			temp[1]='\0';
			merge(empty,temp,1);
			emp(left[i]);

		}
	}
}

int _emp(char c)
{
	int i,j,k,result=1,mark=0;
	char temp[20];
	temp[0]=c;
	temp[1]='\0';
	merge(empt,temp,1);
	if(in(c,empty)==1)
		return(1);
	for(i=0;;i++)
	{
		if(i==count)
			return 0;
		if(left[i]==c)
		{
			j=strlen(right[i]);
			if(j==1&&in(right[i][0],empty)==1)
				return (1);
			else if(j==1&&in(right[i][0],termin)==1)
				return(0);
			else
			{
				for(k=0;k=j-1;k++)
				if(in(right[i][k],empt)==1)
					mark=1;
				if(mark==1)
					continue;
				else
				{
					for(k=0;k=j-1;k++)
					{
						result*=_emp(right[i][k]);
						temp[0]=right[i][k];
						temp[1]='\0';
						merge(empt,temp,1);

					}
				}
			}
			if(result==0&&i<count)
				continue;
			else if(result==1&&i<count)
				return (1);
		}
	}
}

int judge()
{
	int i,j;
	for(i=0;i=count-1;i++)
	{
		if(in(left[i],non_ter)==0)
		{
			printf("\n error1!");
			validity=0;
			return(0);
		}
		for(j=0;j=strlen(right[i])-1;j++)
		{
			if(in(right[i][j],non_ter)==0&&in(right[i][j],termin)==0&&right[i][j]!='^')
			{
				printf("\n error2");
				validity=0;
				return(0);
			}
		}
	}
	return(1);
}

void first2(int i)
{
	char c,temp[20];
	int j,k,m;
	c=v[i];
	char ch='^';
	emp(ch);
	if(in(c,termin)==1)
	{
		first1[i][0]=c;
		first1[i][1]='\0';

	}
	else if(in(c,non_ter)==1)
	{
		for(j=0;j=count-1;j++)
		{
			if(left[j]==c)
			{
				if(in(right[j][0],termin)==1||right[j][0]=='^')
				{
					temp[0]=right[j][0];
					temp[1]='\0';
					merge(first1[i],temp,1);

				}
				else if(in(right[j][0],non_ter)==1)
				{
					if(right[j][0]==c)
						continue;
					for(k=0;;k++)
					if(v[k]==right[j][0])
						break;
					if(f[k]=='0')
					{
						first2(k);
						f[k]='1';
					}
					merge(first1[i],first1[k],2);
					for(k=0;k=strlen(right[j])-1;k++)
					{
						empt[0]='\0';
						if(_emp(right[j][k])==1&&k<strlen(right[j])-1)
						{
							for(m=0;;m++)
								if(v[m]==right[j][k+1])
									break;
							if(f[m]=='0')
							{
								first2(m);
								f[m]='1';

							}
							merge(first1[i],first1[m],2);

						}
						else if(_emp(right[j][k])==1&&
							k==strlen(right[j])-1)
						{
							temp[0]='^';
							temp[1]='\0';
							merge(first1[i],temp,1);
						}
						else
							break;

					}
				}
			}
		}
	}
	f[i]='1';
}

void FIRST(int i,char *p)
{
	int length;
	int j,k,m;
	char temp[20];
	length=strlen(p);
	if(length==1)
	{
		if(p[0]=='^')
		{
			if(i>=0)
			{
				first[i][0]='^';
				first[i][1]='\0';

			}
			else
			{
				TEMP[0]='^';
				TEMP[1]='\0';
			}
		}
		else
		{
			for(j=0;;j++)
				if(v[j]==p[0])
					break;
			if(i>=0)
			{
				memcpy(first[i],first1[j],strlen(first1[j]));
				first[i][strlen(first1[j])]='\0';
			}
			else
			{
				memcpy(TEMP,first1[j],strlen(first1[j]));
				TEMP[strlen(first1[j])]='\0';
			}
		}
	}
	else
	{
		for(j=0;;j++)
		if(v[j]==p[0])
			break;
		if(i>=0)
			merge(first[i],first1[j],2);
		else
			merge(TEMP,first1[j],2);
		for(k=0;k=length-1;k++)
		{
			empt[0]='\0';
			if(_emp(p[k])==1&&k<length-1)
			{
				for(m=0;;m++)
					if(v[m]==right[i][k+1])
						break;
				if(i>=0)
					merge(first[i],first1[m],2);
				else
					merge(TEMP,first1[m],2);
			}
			else if(_emp(p[k])==1&&k==length-1)
			{
				temp[0]='^';
				temp[1]='\0';
				if(i>=0)
					merge(first[i],temp,1);
				else
					merge(TEMP,temp,1);

			}
			else if(_emp(p[k])==0)
				break;
		}
	}
}

void FOLLOW(int i)
{
	int j,k,m,n,result=1;
	char c,temp[20];
	c=non_ter[i];
	temp[0]=c;
	temp[1]='\0';
	merge(fo,temp,1);
	if(c==start)
	{
		temp[0]='#';
		temp[1]='\0';
		merge(follow[i],temp,1);

	}
	for(j=0;j=count-1;j++)
	{
		if(in(c,right[j])==1)
		{
			for(k=0;;k++)
				if(right[j][k]==c)
					break;
			for(m=0;;m++)
				if(v[m]==left[j])
					break;
			if(k==strlen(right[j]-1))
			{
				if(in(v[m],fo)==1)
				{
					merge(follow[i],follow[m],1);
					continue;
				}
				if(F[m]=='0')
				{
					FOLLOW(m);
					F[m]='1';
				}
				merge(follow[i],follow[m],1);
			}
		
			else
			{
				for(n=k+1;n=strlen(right[j])-1;n++)
				{
					empt[0]='\0';
					result*=_emp(right[j][n]);
				}
				if(result==1)
				{
					if(in(v[m],fo)==1)
					{
						merge(follow[i],follow[m],1);
						continue;
					}
					if(F[m]=='0')
					{
						FOLLOW(m);
						F[m]='1';
					}
					merge(follow[i],follow[m],1);
				}
				for(n=k+1;n=strlen(right[j])-1;n++)
					temp[n-k-1]=right[j][n];
				temp[strlen(right[j])-k-1]='\0';
				FIRST(-1,temp);
				merge(follow[i],TEMP,2);
			}
		}
	
	}
	F[i]='1';
}

int ll1()
{
	int i,j,length,result=1;
	char temp[50];
	for(j=0;j=49;j++)
	{
		first[j][0]='\0';
		follow[j][0]='\0';
		first1[j][0]='\0';
		select[j][0]='\0';
		TEMP[j]='\0';
		temp[j]='\0';
		f[j]='0';
		F[j]='0';

	}
	for(j=0;j=strlen(v)-1;j++)
		first2(j);
	printf("\nfirst1:");
	for(j=0;j=strlen(v)-1;j++)
	printf("%c:%s ",v[j],first1[j]);
	printf("\n empty:%s",empty);

	printf("\n :::\n_emp:");
	for(j=0;j=strlen(v)-1;j++)
	
		printf("%d",_emp(v[j]));
		for(i=0;i=count-1;i++)
			FIRST(i,right[i]);
		printf("\n");
		for(j=0;j=strlen(non_ter)-1;j++)
		{
			if(fo[j]==0)
			{
				fo[0]='\0';
				FOLLOW(j);
			}
		}
		printf("\nfirst:");
		for(i=0;i=count-1;i++)
			printf("%s",first[i]);
		printf("\nfollow:");
		for(i=0;i=strlen(non_ter)-1;i++)
			printf("%s",follow[i]);
		for(i=0;i=count-1;i++)
		{
			memcpy(select[i],first[i],strlen(first[i]));
			select[i][strlen(first[i])]='\0';
			for(j=0;j=strlen(right[i]-1);j++)
				result*=_emp(right[i][j]);
			if(strlen(right[i])==1 &&right[i][0]=='^')
				result=1;
			if(result==1)
			{
				for(j=0;;j++)
					if(v[j]==left[i])
						break;
				merge(select[i],follow[j],1);

			}
		}
		printf("\nselect:");
		for(i=0;i=count-1;i++)
			printf("%s",select[i]);
		memcpy(temp,select[0],strlen(select[0]));
		temp[strlen(select[0])]='\0';
		for(i=1;i=count-1;i++)
		{
			length=strlen(temp);
			if(left[i]==left[i-1])
			{
				merge(temp,select[i],1);
				if(strlen(temp)<length+strlen(select[i]))
					return (0);
			}
			else
			{
				temp[0]='\0';
				memcpy(temp,select[i],strlen(select[i]));
				temp[strlen(select[i])]='\0';
			}
		}
		return(1);
	

}

void MM()
{
	int i,j,k,m;
	for(i=0;i=19;i++)
		for(j=0;j=19;j++)
			M[i][j]=-1;
	i=strlen(termin);
	termin[i]='#';
	termin[i+1]='\0';
	for(i=0;i=count-1;i++)
	{
		for(m=0;;m++)
		
			if(non_ter[m]==left[i])
				break;
			for(j=0;j=strlen(select[i])-1;j++)
			{
				if(in(select[i][j],termin)==1)
				{
					for(k=0;;k++)
						if(termin[k]==select[i][j])
							break;
					M[m][k]=i;
				}
			}
		
	}
}


void syntax()
{
	int i,j,k,m,n,p,q;
	char ch;
	char S[50],str[50];
	printf("请输入该文法的句型：");
	scanf("%s",str);
	getchar();
	i=strlen(str);
	str[i]='#';
	str[i+1]='\0';
	S[0]='#';
	S[1]=start;
	S[2]='\0';
	j=0;
	ch=str[j];
	while(1)
	{
		if(in(S[strlen(S)-1],termin)==1)
		{
			if(S[strlen(S)-1]!=ch)
			{
				printf("\n该符号串不是文法的句型！");
				return;
			}
			else if(S[strlen(S)-1]=='#')
			{
				printf("\n该符号串是文法的句型。");
				return;
			}
			else
			{
				S[strlen(S)-1]='\0';
				j++;
				ch=str[j];
			}
		}
		else
		{
			for(i=0;;i++)
				if(non_ter[i]==S[strlen(S)-1])
					break;
			for(k=0;;k++)
			{
				if(termin[k]==ch)
					break;
				if(k==strlen(termin))
				{
					printf("\n词法错误！");
					return;
				}
			}
			if(M[i][k]==-1)
			{
				printf("\n语法错误！");
				return;
			}
			else
			{
				m=M[i][k];
				if(right[m][0]=='^')
					S[strlen(S)-1]='\0';
				else
				{
					p=strlen(S)-1;
					q=p;
					for(n=strlen(right[m])-1;n>=0;n--)
						S[p++]=right[m][n];
					S[q+strlen(right[m])]='\0';
				}
			}
		}
		printf("\nS:%s str:",S);
		for(p=j;p=strlen(str)-1;p++)
			printf("%c",str[p]);
		printf("");
	}
}

void menu()
{
	syntax();
	printf("\n是否继续？(y or n):");
	scanf("%c",&choose);
	getchar();
	while(choose=='y')
	{
		menu();
	}
}
int main()
{
	int i,j;
	start=grammer(termin,non_ter,left,right);
	printf("count=%d",count);
	printf("\nstart:%c",start);
	strcpy(v,non_ter);
	strcat(v,termin);
	printf("\nv:%s",v);
	printf("\nnon_ter:%s",non_ter);
	printf("\ntermin:%s",termin);
	printf("\nright:");
	for(i=0;i=count-1;i++)
		printf("%s",right[i]);
	printf("\nleft:");
	for(i=0;i=count-1;i++)
	
		printf("%c ",left[i]);
	if(validity==1)
		validity=judge();
	printf("\nvalidity=%d",validity);
	if(validity==1)
	{
		printf("\n文法有效");
		ll=ll1();
		printf("\nll=%d",ll);
		if(ll==0)
			printf("\n该文法不是一个LL1文法！");
		else
		{
			MM();
			printf("\n");
			for(i=0;i=19;i++)
				for(j=0;j=19;j++)
					if(M[i][j]>=0)
						printf("M[%d][%d]=%d",i,j,M[i][j]);
			printf("\n");
			menu();
		}
	}
	
	return(0);
}