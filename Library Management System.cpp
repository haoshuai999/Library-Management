/*С�᣺���ͼ��ݹ���ϵͳ�����˺ܾã����Ŷ��ȵķ�񣬽�����ϵ�һЩ���Ϻ���ʦ�Ͽε�֪ʶ�ͷ����޸ģ������������������ϵͳ����ϵͳ�ڼ䵱Ȼ�и������ѣ������ò�˵��ʦ�Ͽ�
ʱ������ཨ���ر����á��ҵ�read������������д�����ġ��������ͦ�гɾ͸еġ�*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct PUB   //�����鼮����ʱ��ṹ��
{
	int year;
	int month;
	int day;
};
struct manage    //�������Ա�����Ϣ�ṹ��
{
    char sn[30];
    char sw[30];
};
typedef struct BOOK //�����鼮�����Ϣ�ṹ��
{   
	char name[30];
	int booknum;
    char author[30];
	struct PUB pubtime;
	float price;
	int borrow;
}TBOOK;
/*�˵�*/
void manage();
void user();
void index();
/*���ͼ��*/
void add();
void input();
/*���ͼ��*/
void scan();
void scannum();
void scanname();
void scanzero();
void scanone();
void scanall();
/*�޸�ͼ��*/
void edit();
void editnum();
void editname();
void editinput(int);
/*ɾ��ͼ��*/
void del();
void delnum();
void delname();
/*����ͼ��*/
void order();
/*�οͽ���*/
void borrow();
void borrownum();
void borrowname();
/*����*/
void password();
void changepass();
void nodata();
int check(int);
TBOOK* read(int *n);
int main()
{
	index();  //��ҳ��
	return 0;
}
/*����Ա��ѯ��ʽ ���ͼ��*/
void input()//¼����Ϣ
{
	FILE* fp;
	struct BOOK book;
	int j,a;
	do
	{
		printf("�������:");
		a=scanf("%d",&book.booknum);
		getchar();
		if ((fp=fopen("book.dat","rb"))==NULL)    //�ж��Ƿ��п�������ļ�
		{ 
            j=0;
		}
		else if(a!=1)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
		else
		{
			j=check(book.booknum);
		}
	}while(j==1||a!=1);
	do
	{
		printf("��������:");
		scanf("%s",book.name);
		getchar();
		if(strlen(book.name)>30)
		{
			printf("�����̫���ˣ��������30���ַ�\n");
		}
	}while(strlen(book.name)>30);
	do
	{
		printf("��������:");
		scanf("%s",book.author);
		getchar();
		if(strlen(book.author)>30)
		{
			printf("�����̫���ˣ��������30���ַ�\n");
		}
	}while(strlen(book.author)>30);
	do
	{
		printf("����������:");
		a=scanf("%d",&book.pubtime.year);
		getchar();
		if(a!=1)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
		else if(book.pubtime.year<(-2000))
		{
			printf("%d�����鼮���������ǲ���Ӧ�øߵ�\n",book.pubtime.year);
			fflush(stdin);
		}
		else if(book.pubtime.year>2020)
		{
			printf("ò�ƻ�û��%d��ɣ��������ǲ���Ӧ�øߵ�\n",book.pubtime.year);
			fflush(stdin);
		}
	}while(a!=1);
	do
	{
		printf("��������·�:");
	    a=scanf("%d",&book.pubtime.month);
	    getchar();
		if(a!=1)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
		else if(book.pubtime.month<1||book.pubtime.month>12)
		{
			printf("�·���%d��������ɵ����\n",book.pubtime.month);
			fflush(stdin);
		}
	}while(a!=1||book.pubtime.month<1||book.pubtime.month>12);
	do
	{
		printf("���������:");
		a=scanf("%d",&book.pubtime.day);
		getchar();
		if(a!=1)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
		else if(book.pubtime.day<1||book.pubtime.day>31)
		{
			printf("������%d��������ɵ����\n",book.pubtime.day);
			fflush(stdin);
		}
	}while(a!=1||book.pubtime.day<1||book.pubtime.day>31);
	do
	{
		printf("�������:");
		a=scanf("%f",&book.price);
		getchar();
		if(a!=1)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
	}while(a!=1);
	do
	{
		printf("��������û���ȥ��0��ʾδ�����1��ʾ�ѽ����:");
		scanf("%d",&book.borrow);
		getchar();
		if(book.borrow!=1&&book.borrow!=0)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
	}while(book.borrow!=1&&book.borrow!=0);
    fp=fopen("book.dat","ab");  
	fwrite(&book,sizeof(struct BOOK),1,fp);
	fclose(fp);
}
void add()
{
	int i,n,inp,a;
	do
	{
		printf("��˵��¼�뼸������һ�����¼��100����:");
		a=scanf("%d",&n);
		getchar();
        if(a!=1)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
		else if(n<0||n>100)
		{
			printf("¼��%d�������ڶ��ң�\n",n);
		}
	}while(a!=1||n<0||n>100);
    printf("Ҫ��Ҫ��������Ϣ�����Ƥ��\n");
	for(i=1;i<=n;i++)
	{
		if(n!=1)
		{
			printf("********************************************************************************\n");
            printf("��¼���%d����\n",i);
	        printf("********************************************************************************\n");
		}
		input();
	}
	printf("�Ѿ������Ҫ��¼�����ˣ���������ص�����Ա�˵���\n");
	inp=getchar();
	inp=getchar();
	manage();
}
int check(int booknum)//�ж��������ͼ����Ϣ����Ƿ�ʹ�ù�
{
    int j,n=0;
    TBOOK *b=read(&n);
	for(j=0;j<n;j++)
	{
		if(booknum==(b+j)->booknum)
		{
			printf("�����������Ѿ�ʹ�ù���~\n");
			return 1;
		}
	}
	return 0;
}
void nodata()//û��ʱ����
{
	FILE* fp=NULL;
	int inp;
	if ((fp=fopen("book.dat","rb"))==NULL)    //�ж��Ƿ��п�������ļ�
	{ 
		printf("����ﻹ�ǿտ���Ҳ�������������������һ���˵���\n");
		inp=getchar();
	    manage();
	}
    fclose(fp);
}
TBOOK* read(int *n)//���ļ��е��������
{
	int i=0,j;
	TBOOK inf;
	TBOOK *p=NULL;
	FILE* fp;
	fp=fopen("book.dat","rb");
	while(fread(&inf,sizeof(struct BOOK),1,fp)==1)
	{
		i=i+1;
	}
	p=(struct BOOK *)calloc(i,sizeof(struct BOOK));
	rewind(fp);
	for(j=0;j<i;j++)
	{
		fread(&inf,sizeof(struct BOOK),1,fp);
		p[j]=inf;
	}
	fclose(fp);
    (*n)=i;
	return p;
}
/*���ͼ��*/
void scan()
{
	nodata();
	printf("********************************************************************************\n");
    printf("��������Ҫ��ô��ͼ����е��鵥�أ�\n");
	printf("********************************************************************************\n");
	int ch;
	printf("1.��Ҫ����������鿴��\n");
	printf("2.���������������鿴�ʺ���\n");
    printf("3.ֻ��û�������\n");
	printf("4.��Ҫ�����ȥ����\n");
	printf("5.���Ҵ�ӡ�����鵥���Ҿ�������\n");
	printf("6.��Ҫ�ص���һ����\n");
	printf("********************************************************************************\n");
	do
	{
		printf("��Ҫѡ����һ���أ�\n");
		printf("��ѡ:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���ڿ�ʼ������Ų鿴��\n");
	        printf("********************************************************************************\n");
			scannum();//�����
			break;
		case 2:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���ڿ��������������鿴�\n");
	        printf("********************************************************************************\n");
			scanname();//������
			break;
		case 3:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���涼�ǻ�û���ȥ�����\n");
	        printf("********************************************************************************\n");
			scanzero();//δ���
			break;
		case 4:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���涼���Ѿ����ȥ������\n");
	        printf("********************************************************************************\n");
			scanone();//�ѽ��
			break;
		case 5:
			system("CLS");
			printf("********************************************************************************\n");
            printf("����ô������ֻ�ð���������㿴��\n");
	        printf("********************************************************************************\n");
			scanall();//������
			system("CLS");
			scan();
			break;
		case 6:
			system("CLS");
			break;
		default:
			printf("���ǲ��ǹ�������>__<\n");
			break;
		}
	}while(ch!=1&&ch!=2&&ch!=3&&ch!=4&&ch!=5&&ch!=6);
}
void scannum()
{
    int i,s,a,n=0,inp,flag=0;
	TBOOK *b=read(&n);
	do
	{
		printf("������Ҫ������������������:");
		a=scanf("%d",&s);
		getchar();
		if(a!=1)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
	}while(a!=1);
	printf("���       ����       ����      ��������         ���        �Ƿ���\n");
	for(i=0;i<n;i++)
	{
		if(s==(b+i)->booknum)
		{
			flag=1;
			printf("%d%14s%11s%9d-%d-%d%13.1f",(b+i)->booknum,(b+i)->name,(b+i)->author,(b+i)->pubtime.year,(b+i)->pubtime.month,(b+i)->pubtime.day,(b+i)->price);
			if((b+i)->borrow==0)
			{
				printf("          ��\n");
			}
			else if((b+i)->borrow==1)
			{
				printf("          ��\n");
			}
        }
	}
	if(flag==0)
	{
		printf("��ү�����ٴ�ӡһ���鵥������û�����Űɣ���������ع���Ա�˵���\n");
	}
	else if(flag==1)
	{
		printf("�����˾Ͱ�������ص��ϼ��˵���\n");
	}
	free(b);
	inp=getchar();
	inp=getchar();
	system("CLS");
	scan();
}
void scanname()
{
	int i,n=0,inp,flag=0;
	char s[30];
	TBOOK *b=read(&n);
	do
	{
		printf("������Ҫ�������������������:");
		scanf("%s",s);
		getchar();
		if(strlen(s)>30)
		{
			printf("�����̫���ˣ��������30���ַ�\n");
		}
	}while(strlen(s)>30);
	printf("���       ����       ����      ��������         ���        �Ƿ���\n");
	for(i=0;i<n;i++)
	{
		if(strcmp(s,(b+i)->name)==0)
		{
			flag=1;
			printf("%d%14s%11s%9d-%d-%d%13.1f",(b+i)->booknum,(b+i)->name,(b+i)->author,(b+i)->pubtime.year,(b+i)->pubtime.month,(b+i)->pubtime.day,(b+i)->price);
			if((b+i)->borrow==0)
			{
				printf("          ��\n");
			}
			else if((b+i)->borrow==1)
			{
				printf("          ��\n");
			}
		}
	}
	if(flag==0)
	{
		printf("��ү�����ٴ�ӡһ���鵥������û������ְɣ���������ع���Ա�˵���\n");
	}
	else if(flag==1)
	{
		printf("�����˾Ͱ�������ص��ϼ��˵���\n");
	}
	free(b);
	inp=getchar();
	inp=getchar();
	system("CLS");
	scan();
}
void scanzero()
{
	int i,n=0,inp,flag=0;
	TBOOK *b=read(&n);
	printf("���       ����       ����      ��������         ���\n");
	for(i=0;i<n;i++)
	{
		if((b+i)->borrow==0)
		{
			printf("%d%14s%11s%9d-%d-%d%13.1f\n",(b+i)->booknum,(b+i)->name,(b+i)->author,(b+i)->pubtime.year,(b+i)->pubtime.month,(b+i)->pubtime.day,(b+i)->price);
			flag=1;
		}
	}
	free(b);
	if(flag==1)
	{
	    printf("�����˾Ͱ�������ص��ϼ��˵���\n");
	}
	else if(flag==0)
	{
	    printf("�����鶼������ˣ���������ص��ϼ��˵���\n");
	}
	inp=getchar();
	inp=getchar();
	system("CLS");
	scan();
}
void scanone()
{
	int i,n=0,inp,flag=0;
	TBOOK *b=read(&n);
	printf("���       ����       ����      ��������         ���\n");
	for(i=0;i<n;i++)
	{
		if((b+i)->borrow==1)
		{
			printf("%d%14s%11s%9d-%d-%d%13.1f\n",(b+i)->booknum,(b+i)->name,(b+i)->author,(b+i)->pubtime.year,(b+i)->pubtime.month,(b+i)->pubtime.day,(b+i)->price);
			flag=1;
		}
	}
	free(b);
	if(flag==1)
	{
	    printf("�����˾Ͱ�������ص��ϼ��˵���\n");
	}
	else if(flag==0)
	{
	    printf("������һ����û���ȥ����������ص��ϼ��˵���\n");
	}
	inp=getchar();
	inp=getchar();
	system("CLS");
	scan();
}
void scanall()
{
	int j,n=0,inp;
    TBOOK *b=read(&n);
	printf("���       ����       ����      ��������         ���        �Ƿ���\n");
	for(j=0;j<n;j++)
	{
	    printf("%d%14s%11s%9d-%d-%d%13.1f",(b+j)->booknum,(b+j)->name,(b+j)->author,(b+j)->pubtime.year,(b+j)->pubtime.month,(b+j)->pubtime.day,(b+j)->price);
		if((b+j)->borrow==0)
		{
			printf("          ��\n");
		}
		else if((b+j)->borrow==1)
		{
			printf("          ��\n");
		}
	}
	free(b);
    printf("�Ѿ������Ҫ����ʾ���鵥�ˣ���������ص��ϼ��˵���\n");
	inp=getchar();
	inp=getchar();
}
/*�޸�ͼ��*/
void edit()
{
	nodata();
	int ch;
	printf("1.��Ҫ����������޸ģ�\n");
	printf("2.���������������޸��ʺ���\n");
	printf("3.��Ҫ�ص���һ����\n");
	printf("********************************************************************************\n");
	do
	{
		printf("��Ҫѡ����һ���أ�\n");
		printf("��ѡ:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���ڿ�ʼ��������޸���\n");
	        printf("********************************************************************************\n");
			editnum();//������޸�
			break;
		case 2:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���ڿ��������������޸��\n");
	        printf("********************************************************************************\n");
			editname();//�������޸�
			break;
		case 3:
			system("CLS");
			manage();//�����ϼ�
			break;
		default:
			printf("���ǲ��ǹ�������>__<\n");
			break;
		}
	}while(ch!=1&&ch!=2&&ch!=3);
}
void editnum()
{
	int i,s,a,n=0,inp,flag=0;
	TBOOK *b=read(&n);
	do
	{
		printf("������Ҫ���ĵ���Ŀȫ�ǵ�������:");
		a=scanf("%d",&s);
		getchar();
		if(a!=1)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
	}while(a!=1);
	for(i=0;i<n;i++)
	{
		if(s==(b+i)->booknum)
		{
			flag=1;
			editinput(i);
        }
	}
	if(flag==0)
	{
		printf("��ү�����ٴ�ӡһ���鵥������û�����Űɣ���������ع���Ա�˵���\n");
		free(b);
		inp=getchar();
		inp=getchar();
		manage();
	}
}
void editname()
{
	int i,n=0,inp,flag=0;
	char s[30];
	TBOOK *b=read(&n);
	do
	{
		printf("������Ҫ���ĵ���Ŀȫ�ǵ��������:");
		scanf("%s",s);
		getchar();
		if(strlen(s)>30)
		{
			printf("�����̫���ˣ��������30���ַ�\n");
		}
	}while(strlen(s)>30);
	for(i=0;i<n;i++)
	{
		if(strcmp(s,(b+i)->name)==0)
		{
			flag=1;
			editinput(i);
		}
	}
	if(flag==0)
	{
		printf("��ү�����ٴ�ӡһ���鵥������û������ְɣ���������ع���Ա�˵���\n");
		free(b);
		inp=getchar();
		inp=getchar();
		manage();
	}
}
void editinput(int i)
{
	FILE* fp;
	int j,a,ch,n,inp;
	TBOOK *b=read(&n);
	printf("********************************************************************************\n");
    printf("��̹���������Ȿ���ʲô��Ϣ��\n");
	printf("********************************************************************************\n");
	printf("1.����Ϊ�ǵ����\n");
	printf("2.�����Դ������\n");
    printf("3.���˲����������\n");
	printf("4.��ԯ���޵ĳ������\n");
	printf("5.����д�µĳ����·�\n");
	printf("6.��Ц�Էǵĳ�����\n");
    printf("7.���˷�ָ�����\n");
    printf("8.��δ���µĽ������\n");
	printf("9.��Ҫ�ص���һ����\n");
	printf("********************************************************************************\n");
	do
	{
		printf("��Ҫѡ����һ���أ�\n");
		printf("��ѡ:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			do
			{
				printf("�����������:");
				a=scanf("%d",&(b+i)->booknum);
				getchar();
				if(a!=1)
				{
					printf("���������ʲô��\n");
					fflush(stdin);
				}
				else
				{
					j=check((b+i)->booknum);
				}
			}while(j==1||a!=1);
			break;
		case 2:
			system("CLS");
			do
			{
				printf("������������:");
				scanf("%s",(b+i)->name);
				getchar();
				if(strlen((b+i)->name)>30)
				{
					printf("�����̫���ˣ��������30���ַ�\n");
				}
			}while(strlen((b+i)->name)>30);
			break;
		case 3:
			system("CLS");
			do
			{
				printf("������������:");
				scanf("%s",(b+i)->author);
				getchar();
				if(strlen((b+i)->author)>30)
				{
					printf("�����̫���ˣ��������30���ַ�\n");
				}
			}while(strlen((b+i)->author)>30);
			break;
		case 4:
			system("CLS");
			do
			{
				printf("��������������:");
				a=scanf("%d",(b+i)->pubtime.year);
				getchar();
				if(a!=1)
				{
					printf("���������ʲô��\n");
					fflush(stdin);
				}
				else if((b+i)->pubtime.year<(-2000))
				{
					printf("%d�����鼮���������ǲ���Ӧ�øߵ�\n",(b+i)->pubtime.year);
					fflush(stdin);
				}
				else if((b+i)->pubtime.year>2020)
				{
					printf("ò�ƻ�û��%d��ɣ��������ǲ���Ӧ�øߵ�\n",(b+i)->pubtime.year);
					fflush(stdin);
				}
			}while(a!=1);
			break;
		case 5:
			system("CLS");
			do
			{
				printf("������������·�:");
				a=scanf("%d",&(b+i)->pubtime.month);
				getchar();
				if(a!=1)
				{
					printf("���������ʲô��\n");
					fflush(stdin);
				}
				else if((b+i)->pubtime.month<1||(b+i)->pubtime.month>12)
				{
					printf("�·���%d��������ɵ����\n",(b+i)->pubtime.month);
					fflush(stdin);
				}
			}while(a!=1||(b+i)->pubtime.month<1||(b+i)->pubtime.month>12);
			break;
		case 6:
			system("CLS");
			do
			{
				printf("�������������:");
				a=scanf("%d",&(b+i)->pubtime.day);
				getchar();
				if(a!=1)
				{
					printf("���������ʲô��\n");
					fflush(stdin);
				}
				else if((b+i)->pubtime.day<1||(b+i)->pubtime.day>31)
				{
					printf("������%d��������ɵ����\n",(b+i)->pubtime.day);
					fflush(stdin);
				}
			}while(a!=1||(b+i)->pubtime.day<1||(b+i)->pubtime.day>31);
			break;
        case 7:
			system("CLS");
			do
			{
				printf("�����������:");
				a=scanf("%f",&(b+i)->price);
				getchar();
				if(a!=1)
				{
					printf("���������ʲô��\n");
					fflush(stdin);
				}
			}while(a!=1);
			break;
		case 8:
			system("CLS");
			do
			{
				printf("������������û���ȥ��0��ʾδ�����1��ʾ�ѽ����:");
				scanf("%d",&(b+i)->borrow);
				getchar();
				if((b+i)->borrow!=1&&(b+i)->borrow!=0)
				{
					printf("���������ʲô��\n");
					fflush(stdin);
				}
			}while((b+i)->borrow!=1&&(b+i)->borrow!=0);
			break;
		case 9:
			system("CLS");
			printf("********************************************************************************\n");
            printf("�޸�ͼ��ʱ�䣡�޸�ͼ��ʱ�䣡\n");
	        printf("********************************************************************************\n");
			edit();//�����ϼ�
			break;
		default:
			printf("���ǲ��ǹ�������>__<\n");
			break;
		}
		fp=fopen("book.dat","wb");
		for(j=0;j<n;j++)
		{
	        fwrite(b+j,sizeof(struct BOOK),1,fp);
		}
	    fclose(fp);
		free(b);
	    printf("�ĺ�������������ص�����Ա�˵���\n");
	    inp=getchar();
	    inp=getchar();
	    manage();
	}while(ch!=1&&ch!=2&&ch!=3&&ch!=4&&ch!=5&&ch!=6&&ch!=7&&ch!=8&&ch!=9);
}
/*ɾ��ͼ��*/
void del()
{
	nodata();
	int ch,inp;
	printf("1.��Ҫ���������ɾ����\n");
	printf("2.��������������ɾ���ʺ���\n");
    printf("3.�������������ȫɾ��ˬ\n");
	printf("4.��Ҫ�ص���һ����\n");
	printf("********************************************************************************\n");
	do
	{
		printf("��Ҫѡ����һ���أ�\n");
		printf("��ѡ:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���ڿ�ʼ�������ɾ����\n");
	        printf("********************************************************************************\n");
			delnum();//�����ɾ��
			break;
		case 2:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���ڿ�������������ɾ���\n");
	        printf("********************************************************************************\n");
			delname();//������ɾ��
			break;
		case 3:
			system("CLS");
			printf("********************************************************************************\n");
            printf("����ͼ����Ϣ����ɾ������\n");
	        printf("********************************************************************************\n");
			remove("book.dat");//ֱ��ɾ���ļ�
			printf("��������ص�����Ա�˵���\n");
	        inp=getchar();
	        inp=getchar();
	        manage();
			break;
		case 4:
			system("CLS");
			manage();//�����ϼ�
			break;
		default:
			printf("���ǲ��ǹ�������>__<\n");
			break;
		}
	}while(ch!=1&&ch!=2&&ch!=3&&ch!=4);
}
void delnum()
{
	FILE* fp;
	int i,j,s,n=0,inp,a,flag=0;
	TBOOK *b=read(&n);
	do
	{
		printf("������Ҫ����ն��������:");
		a=scanf("%d",&s);
		getchar();
		if(a!=1)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
	}while(a!=1);
	for(i=0;i<n;i++)
	{
		if(s==(b+i)->booknum)
		{
			flag=1;
			if(n>=2)
			{
				fp=fopen("book.dat","wb");
				for(j=0;j<i;j++)
				{  
					fwrite(b+j,sizeof(struct BOOK),1,fp);
				}
				for(j=i+1;j<n;j++)
				{  
					fwrite(b+j,sizeof(struct BOOK),1,fp);
				}
				fclose(fp);
			}
			else
			{
				remove("book.dat");
			}
		}
	}
	free(b);
	if(flag==0)
	{
		printf("��ү�����ٴ�ӡһ���鵥������û�����Űɣ���������ع���Ա�˵���\n");
	}
	else if(flag==1)
	{
		printf("�Ѿ����Ǳ���������ɾ���ˣ���������ص�����Ա�˵���\n");
	}
	inp=getchar();
	inp=getchar();
	manage();
}
void delname()
{
	FILE* fp;
	int i,j,n=0,inp,flag=0;
	char s[30];
	TBOOK *b=read(&n);
	do
	{
		printf("������Ҫ����ն���������:");
		scanf("%s",s);
		getchar();
		if(strlen(s)>30)
		{
			printf("�����̫���ˣ��������30���ַ�\n");
		}
	}while(strlen(s)>30);
	for(i=0;i<n;i++)
	{
		if(strcmp(s,(b+i)->name)==0)
		{
			flag=1;
			if(n>=2)
			{
				fp=fopen("book.dat","wb");
				for(j=0;j<i;j++)
				{  
					fwrite(b+j,sizeof(struct BOOK),1,fp);
				}
				for(j=i+1;j<n;j++)
				{  
					fwrite(b+j,sizeof(struct BOOK),1,fp);
				}
				fclose(fp);
			}
			else
			{
				remove("book.dat");
			}
        }
	}
	if(flag==0)
	{
		printf("��ү�����ٴ�ӡһ���鵥������û������ְɣ���������ع���Ա�˵���\n");
	}
	else if(flag==1)
	{
		printf("�Ѿ����Ǳ���������ɾ���ˣ���������ص�����Ա�˵���\n");
	}
	inp=getchar();
	inp=getchar();
	manage();
}
/*����ͼ��*/
void order()
{
	nodata();
	FILE* fp;
	int i,j,t,n=0,inp;
	TBOOK *b=read(&n);
	for(j=0;j<n-1;j++)
	{   
		for(i=0;i<n-j-1;i++)
		{   
			if((b+i)->booknum>(b+i+1)->booknum)
			{
				t=(b+i)->booknum;
				(b+i)->booknum=(b+i+1)->booknum; 
				(b+i+1)->booknum=t;
			}
		}
	}
	fp=fopen("book.dat","wb");
	for(j=0;j<n;j++)
	{  
	    fwrite(b+j,sizeof(struct BOOK),1,fp);
	}
	fclose(fp);
	free(b);
	printf("�����źã���������ص�����Ա�˵���\n");
	inp=getchar();
	inp=getchar();
	manage();
}
void changepass()//��������
{
	char pw[30];
	struct manage set;
	FILE* fp1=NULL;
	FILE* fp2=NULL;
	int k,a,b,d,inp;
	printf("�������û�����:");
	scanf("%s",set.sn);
	do
	{
		printf("������������:");
		scanf("%s",set.sw);
		printf("����������ȷ��һ�¿�:");
		scanf("%s",pw);
		k=strcmp(set.sw,pw); //��2�������������бȽ�
		a=strlen(set.sw); //ȡ2������ĳ��ȣ�ȡ�û����ĳ���
		b=strlen(pw);
		d=strlen(set.sn);
		if (k!=0)   //�ж�2�������Ƿ�һ��
		{ 
			printf("�ϴ�������������벻һ����!\n");
		}
		else if (a>15||b>15||d>15)   //�ж��û����������Ƿ���ϳ��ȹ淶
		{
			printf("�����̫���ˣ�\n");
		}
	}while(a>15||b>15||d>15||k!=0);
    fp1=fopen("passname.dat","wb");  
	fwrite(&set.sn,sizeof(struct manage),1,fp1);
	fclose(fp1);
	fp2=fopen("password.dat","wb");  
	fwrite(&set.sw,sizeof(struct manage),1,fp2);
	fclose(fp2);
	printf("�㶨��!Ҫ�Ǻ�����ʺź�����Ŷ!!���ڰ�������������˵�");
	inp=getchar();
	inp=getchar();
	manage();   //���봴����Ϻ�������Ա�����б�
}
void password()//����Ա��������
{
	char passname[30];
	char password[30];
	FILE* setname=NULL;
	FILE* setword=NULL;
	FILE* fp1=NULL;
	FILE* fp2=NULL;
	int i,j,k,inp;
	char c;
	struct manage set;
	printf("********************************************************************************\n");
	printf("�ߺߣ�������Ҫ��֤һ��������\n");
	printf("ע���û��������붼�ǲ�����20λ��\n");
	printf("********************************************************************************\n");
	if ((fp1=fopen("passname.dat","rb"))==NULL||(fp2=fopen("password.dat","rb"))==NULL) //�ж��ļ��Ƿ���ڣ������ھʹ�������Ϣ�ļ�
	{
		printf("������ô��û��������Ա�ʻ�!����������̴���!\n");
		inp=getchar();
		system("CLS");
		printf("********************************************************************************\n");
        printf("��һ�δ����û���᲻����ɬ��\n");
	    printf("********************************************************************************\n");
        changepass();
	}
	for(i=1;i<=3;i++)
	{
		setname=fopen("passname.dat","rb");
	    fread(&set.sn,sizeof(struct manage),1,setname);
		fclose(setname);
	    printf("�������û�����:");
		scanf("%s",passname);
		getchar();
		setword=fopen("password.dat","rb");
	    fread(&set.sw,sizeof(struct manage),1,setword);
        fclose(setword);
	    printf("������������:");
		scanf("%s",password);
		getchar();
		j=strcmp(passname,set.sn);
		k=strcmp(password,set.sw);
        if(j==0&&k==0)
		{
			manage();//����������ȷ
		}
		else
		{
			printf("����ˣ����Ѿ�����%d�λ���\n",i);//�����������
		}
	}
    do
	{
		printf("��û�л�����,�˳�(t)���Ƿ�����ҳ��(f)��");
		scanf("%c",&c);
		getchar();
		if(c=='t')
		{
			system("CLS");
			printf("ϣ���ܺ����ټ���\n");//�˳�
			exit(0);
		}
		else if(c=='f')
			index();
		else
			printf("���ǲ��ǹ�������>__<\n");
	}while(c!='t'&&c!='f');
}
/*����Ա��ѯ��ʽ*/
void manage()
{
	system("CLS");
	int ch;
	printf("********************************************************************************\n");
    printf("��Ϊһ�������ʵ�ͼ��ݹ���Ա���������ʲô�أ�\n");
	printf("********************************************************************************\n");
    printf("1.��ͼ����Ϣ¼���ȥ\n");
	printf("2.���ĺ���ͼ����Ϣ\n");
    printf("3.��һ��ͼ����Ϣ\n");
	printf("4.ɾ����Ҫ��ͼ����Ϣ\n");
	printf("5.��ͼ����Ϣ�Ÿ���\n");
	printf("6.��һ����ŵ��û���������\n");
	printf("7.��Ҫ�ص���һ����\n");
	printf("********************************************************************************\n");
	do
	{
		printf("��Ҫѡ����һ���أ�\n");
		printf("��ѡ:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("Ҫ��ʼ¼���鼮��Ϣ�ˣ��ý��ţ�\n");
	        printf("********************************************************************************\n");
			add();//¼��ͼ��
			break;
		case 2:
			system("CLS");
			scan();//���ͼ��
			system("CLS");
            manage();
			break;
		case 3:
			system("CLS");
			printf("********************************************************************************\n");
            printf("�޸�ͼ��ʱ�䣡�޸�ͼ��ʱ�䣡\n");
	        printf("********************************************************************************\n");
			edit();//�޸�ͼ��
			break;
		case 4:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���ı�ͼ�鲻ˬ�˰���\n");
	        printf("********************************************************************************\n");
			del();//ɾ��ͼ��
			break;
		case 5:
			system("CLS");
			printf("********************************************************************************\n");
            printf("����Ǭ����Ų�ƣ���\n");
	        printf("********************************************************************************\n");
			order();//����ͼ��
			break;
		case 6:
			system("CLS");
			printf("********************************************************************************\n");
            printf("��˵��Ҫ�����룬��ô��ʼ��\n");
	        printf("********************************************************************************\n");
			changepass();//������
			break;
		case 7:
			system("CLS");
			index();//�����ϼ�
			break;
		default:
			printf("���ǲ��ǹ�������>__<\n");
			break;
		}
	}while(ch!=1&&ch!=2&&ch!=3&&ch!=4&&ch!=5&&ch!=6&&ch!=7);
}
/*�οͲ�ѯ��ʽ*/
void borrow()
{
	system("CLS");
	nodata();
	printf("********************************************************************************\n");
    printf("ɶ�����飿��Ҫզ�裿\n");
	printf("********************************************************************************\n");
	int ch;
	printf("1.��Ҫ������������飡\n");
	printf("2.�������������������ʺ���\n");
    printf("3.�����÷�����һ���ˣ������⼶������ʾ����ͼ�飡\n");
	printf("4.��Ҫ�ص���һ����\n");
	printf("********************************************************************************\n");
	do
	{
		printf("��Ҫѡ����һ���أ�\n");
		printf("��ѡ:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���ڿ�ʼ������Ž�����\n");
	        printf("********************************************************************************\n");
			borrownum();//����Ž���
			break;
		case 2:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���ڿ������������������\n");
	        printf("********************************************************************************\n");
			borrowname();//����������
			break;
		case 3:
			system("CLS");
			printf("********************************************************************************\n");
            printf("���������ˣ�\n");
	        printf("********************************************************************************\n");
			scanall();//��ʾ����ͼ��
			borrow();
			break;
		case 4:
			system("CLS");
			user();//�����ϼ�
			break;
		default:
			printf("���ǲ��ǹ�������>__<\n");
			break;
		}
	}while(ch!=1&&ch!=2&&ch!=3&&ch!=4);
}
void borrownum()
{
	FILE* fp;
	int i,j,s,a,n=0,inp,flag=0;
	TBOOK *b=read(&n);
	do
	{
		printf("������Ҫ��ĵ�������:");
		a=scanf("%d",&s);
		getchar();
		if(a!=1)
		{
			printf("���������ʲô��\n");
			fflush(stdin);
		}
	}while(a!=1);
	for(i=0;i<n;i++)
	{
		if(s==(b+i)->booknum)
		{
			flag=1;
			if((b+i)->borrow==0)
			{
				(b+i)->borrow=1;
				fp=fopen("book.dat","wb");
				for(j=0;j<n;j++)
				{
					fwrite(b+j,sizeof(struct BOOK),1,fp);
				}
				fclose(fp);
			}
			else if((b+i)->borrow==1)
			{
				printf("�����ˣ��Ȿ�鱻�����ˣ��㲻��Ҫȥ���ɣ���������ع���Ա�˵���\n");
				inp=getchar();
				inp=getchar();
				borrow();
			}
		}
	}
    if(flag==0)
	{
		printf("��ү�����ٴ�ӡһ���鵥������û�����Űɣ���������ع���Ա�˵���\n");
	}
	else if(flag==1)
	{
		printf("���Ѿ�����ˣ����úñ����ҿɲ����㣡�����˾Ͱ�������ص��ϼ��˵���\n");
	}
	free(b);
	inp=getchar();
	inp=getchar();
	borrow();
}
void borrowname()
{
	FILE* fp;
	int i,j,n=0,inp,flag=0;
	char s[30];
	TBOOK *b=read(&n);
	do
	{
		printf("������Ҫ����������:");
		scanf("%s",s);
		getchar();
		if(strlen(s)>30)
		{
			printf("�����̫���ˣ��������30���ַ�\n");
		}
	}while(strlen(s)>30);
	for(i=0;i<n;i++)
	{
		if(strcmp(s,(b+i)->name)==0)
		{
			flag=1;
			if((b+i)->borrow==0)
			{
				(b+i)->borrow=1;
				fp=fopen("book.dat","wb");
				for(j=0;j<n;j++)
				{
					fwrite(b+j,sizeof(struct BOOK),1,fp);
				}
				fclose(fp);
			}
			else if((b+i)->borrow==1)
			{
				printf("�����ˣ��Ȿ�鱻�����ˣ��㲻��Ҫȥ���ɣ�����������ϼ��˵���\n");
				inp=getchar();
				inp=getchar();
				borrow();
			}
		}
	}
	if(flag==0)
	{
		printf("��ү�����ٴ�ӡһ���鵥������û������ְɣ���������ع���Ա�˵���\n");
	}
	else if(flag==1)
	{
		printf("���Ѿ�����ˣ����úñ����ҿɲ����㣡�����˾Ͱ�������ص��ϼ��˵���\n");
	}
	free(b);
	inp=getchar();
	inp=getchar();
	borrow();
}
void user()
{
	int ch;
	printf("********************************************************************************\n");
    printf("��Ϊһ��������������û�������Ҫʲô�����أ�\n");
	printf("********************************************************************************\n");
    printf("1.���������ҿ�һ���鵥�ɣ�\n");
	printf("2.�ٺ٣���Ҫ����\n");
	printf("3.��Ҫ�ص���һ����\n");
	printf("********************************************************************************\n");
	do
	{
		printf("��Ҫѡ����һ���أ�\n");
		printf("��ѡ:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("�������ظߵĹ���Ա��Ȩ������Բ鿴�鵥��\n");
	        printf("********************************************************************************\n");
			scan();//��ʾ�鵥
			system("CLS");
			user();
			break;
	    case 2:
            borrow();//����
			break;
		case 3:
			system("CLS");
			index();//�����ϼ�
			break;
		default:
			printf("���ǲ��ǹ�������>__<\n");
			break;
		}
	}while(ch!=1&&ch!=2&&ch!=3);
}
/*��ҳ��*/
void index()
{
	system("CLS");
	int c;
	printf("********************************************************************************\n");
	printf("��ӭ������˧��ͼ��ݹ���ϵͳ������������ʶһ�¸����ʵ�ͼ��ݹ���Ա�ķ��\n");
    printf("********************************************************************************\n");
    printf("1.�����չ���Աϵͳ\n");
	printf("2.�������õ��û�ϵͳ\n");
	printf("3.���Ҫ�˳���>__<\n");
	printf("********************************************************************************\n");
	do
	{
		printf("��Ҫѡ����һ���أ�\n");
		printf("��ѡ:\n");
		scanf("%d",&c);
		getchar();
		switch(c)
		{
		case 1:
			system("CLS");
			password();//����Ա����ϵͳ
			break;
		case 2:
			system("CLS");
			user();//�û�ϵͳ
			break;
		case 3:
			system("CLS");
			printf("ϣ���ܺ����ټ���\n");//�˳�
			exit(0);
			break;
		default:
			printf("���ǲ��ǹ�������>__<\n");
		}
	}while(c!=1&&c!=2&&c!=3);
}