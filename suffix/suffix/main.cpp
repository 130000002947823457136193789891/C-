#include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 struct node
 {
     int data;
     struct node *l;
     struct node *r;
 };
 char  s[101],q1[101],q2[101];
 int sp(char ch)    
 {
     int x;
     switch(ch)
     {
     case '+':x=1;break;
     case '-':x=1;break;
     case '*':x=2;break;
     case '/':x=2;break;
     default :x=0;
     }
     return x;
 }
 int i;
 void change()//����׺ʽ��Ϊ��׺ʽ����
 {
 
     int x=0,y=0;
     for(i=0; s[i]!='#'; i++)
     {
         if(s[i]>='a'&&s[i]<='z')
             q1[x++]=s[i];
         else if(s[i]=='(')
             q2[y++]=s[i];
         else if(s[i]==')')
         {
             while(q2[y-1]!='(')
             {
                 q1[x]=q2[y-1];
                 x++;
                 y--;
             }
             y--;
         }
         else if(sp(s[i])==1)
         {
             while(y!=0&&q2[y-1]!='(')
             {
                 q1[x]=q2[y-1];
                 x++;
                 y--;
             }
             q2[y++]=s[i];
         }
         else if(sp(s[i])==2)
         {
             while(y!=0&&sp(q2[y-1])==2)
             {
                 q1[x]=q2[y-1];
                 x++;
                 y--;
             }
             q2[y++]=s[i];
         }
 
     }
     while(y!=0)
     {
         q1[x]=q2[y-1];
         x++;
         y--;
     }
     q1[x]='\0';
 
 }
 void pretree(struct node *p)//ǰ�����
 {
     if(p != NULL)
     {
         printf("%c",p->data);
         pretree(p->l);
         pretree(p->r);
     }
 }
 void intree(struct node *p)//�������
 {
     if(p != NULL)
     {
         intree(p->l);
         printf("%c",p->data);
         intree(p->r);
 
     }
 }
 int main()
 {
     int top=0,j;
     gets(s);
     change();    //����׺ʽ��Ϊ��׺ʽ
     struct node *tree[101]= {NULL},*pi;   //�������ʽ��������ջ
     for( j = 0; j < i; j++)
     {
         if(q1[j] >= 'a' && q1[j] <= 'z')
         {
             pi = (struct node *)malloc(sizeof(struct node));
             pi->data = q1[j];
             pi->l = NULL;
             pi->r = NULL;
             tree[top++] = pi;
         }
         else
         {
             pi = (struct node *)malloc(sizeof(struct node));
             pi->data = q1[j];
             pi->r = tree[top-1];
             top--;
             pi->l = tree[top-1];
             top--;
             tree[top++] = pi;
         }
     }
     pretree(tree[0]);
     printf("\n");
     intree(tree[0]);
     printf("\n");
     puts(q1);    //����ɻ�Ϊ�������
     return 0;
 }