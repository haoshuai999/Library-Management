/*小结：这个图书馆管理系统我做了很久，秉着逗比的风格，结合网上的一些资料和老师上课的知识和反复修改，终于做出了这个管理系统。做系统期间当然有各种困难，但不得不说老师上课
时给的许多建议特别有用。我的read函数就是这样写出来的。做完后还是挺有成就感的。*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct PUB   //定义书籍出版时间结构体
{
	int year;
	int month;
	int day;
};
struct manage    //定义管理员相关信息结构体
{
    char sn[30];
    char sw[30];
};
typedef struct BOOK //定义书籍相关信息结构体
{   
	char name[30];
	int booknum;
    char author[30];
	struct PUB pubtime;
	float price;
	int borrow;
}TBOOK;
/*菜单*/
void manage();
void user();
void index();
/*添加图书*/
void add();
void input();
/*浏览图书*/
void scan();
void scannum();
void scanname();
void scanzero();
void scanone();
void scanall();
/*修改图书*/
void edit();
void editnum();
void editname();
void editinput(int);
/*删除图书*/
void del();
void delnum();
void delname();
/*排序图书*/
void order();
/*游客借书*/
void borrow();
void borrownum();
void borrowname();
/*密码*/
void password();
void changepass();
void nodata();
int check(int);
TBOOK* read(int *n);
int main()
{
	index();  //主页面
	return 0;
}
/*管理员查询方式 添加图书*/
void input()//录入信息
{
	FILE* fp;
	struct BOOK book;
	int j,a;
	do
	{
		printf("输入书号:");
		a=scanf("%d",&book.booknum);
		getchar();
		if ((fp=fopen("book.dat","rb"))==NULL)    //判断是否有可输入的文件
		{ 
            j=0;
		}
		else if(a!=1)
		{
			printf("你输入的是什么鬼\n");
			fflush(stdin);
		}
		else
		{
			j=check(book.booknum);
		}
	}while(j==1||a!=1);
	do
	{
		printf("输入书名:");
		scanf("%s",book.name);
		getchar();
		if(strlen(book.name)>30)
		{
			printf("大哥输太长了！最多输入30个字符\n");
		}
	}while(strlen(book.name)>30);
	do
	{
		printf("输入作者:");
		scanf("%s",book.author);
		getchar();
		if(strlen(book.author)>30)
		{
			printf("大哥输太长了！最多输入30个字符\n");
		}
	}while(strlen(book.author)>30);
	do
	{
		printf("输入出版年份:");
		a=scanf("%d",&book.pubtime.year);
		getchar();
		if(a!=1)
		{
			printf("你输入的是什么鬼\n");
			fflush(stdin);
		}
		else if(book.pubtime.year<(-2000))
		{
			printf("%d年有书籍吗？你素质是不是应该高点\n",book.pubtime.year);
			fflush(stdin);
		}
		else if(book.pubtime.year>2020)
		{
			printf("貌似还没到%d年吧？你素质是不是应该高点\n",book.pubtime.year);
			fflush(stdin);
		}
	}while(a!=1);
	do
	{
		printf("输入出版月份:");
	    a=scanf("%d",&book.pubtime.month);
	    getchar();
		if(a!=1)
		{
			printf("你输入的是什么鬼\n");
			fflush(stdin);
		}
		else if(book.pubtime.month<1||book.pubtime.month>12)
		{
			printf("月份有%d月吗？碰上傻子了\n",book.pubtime.month);
			fflush(stdin);
		}
	}while(a!=1||book.pubtime.month<1||book.pubtime.month>12);
	do
	{
		printf("输入出版日:");
		a=scanf("%d",&book.pubtime.day);
		getchar();
		if(a!=1)
		{
			printf("你输入的是什么鬼\n");
			fflush(stdin);
		}
		else if(book.pubtime.day<1||book.pubtime.day>31)
		{
			printf("日期有%d日吗？碰上傻子了\n",book.pubtime.day);
			fflush(stdin);
		}
	}while(a!=1||book.pubtime.day<1||book.pubtime.day>31);
	do
	{
		printf("输入书价:");
		a=scanf("%f",&book.price);
		getchar();
		if(a!=1)
		{
			printf("你输入的是什么鬼\n");
			fflush(stdin);
		}
	}while(a!=1);
	do
	{
		printf("输入书有没借出去（0表示未借出，1表示已借出）:");
		scanf("%d",&book.borrow);
		getchar();
		if(book.borrow!=1&&book.borrow!=0)
		{
			printf("你输入的是什么鬼\n");
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
		printf("先说好录入几本哈，一次最多录入100本！:");
		a=scanf("%d",&n);
		getchar();
        if(a!=1)
		{
			printf("你输入的是什么鬼\n");
			fflush(stdin);
		}
		else if(n<0||n>100)
		{
			printf("录入%d本？你在逗我？\n",n);
		}
	}while(a!=1||n<0||n>100);
    printf("要按要求输入信息，别调皮！\n");
	for(i=1;i<=n;i++)
	{
		if(n!=1)
		{
			printf("********************************************************************************\n");
            printf("请录入第%d本书\n",i);
	        printf("********************************************************************************\n");
		}
		input();
	}
	printf("已经按你的要求录入完了！按任意键回到管理员菜单吧\n");
	inp=getchar();
	inp=getchar();
	manage();
}
int check(int booknum)//判断新输入的图书信息编号是否使用过
{
    int j,n=0;
    TBOOK *b=read(&n);
	for(j=0;j<n;j++)
	{
		if(booknum==(b+j)->booknum)
		{
			printf("哎！这个编号已经使用过了~\n");
			return 1;
		}
	}
	return 0;
}
void nodata()//没书时返回
{
	FILE* fp=NULL;
	int inp;
	if ((fp=fopen("book.dat","rb"))==NULL)    //判断是否有可输入的文件
	{ 
		printf("书库里还是空空如也。。。按任意键返回上一级菜单吧\n");
		inp=getchar();
	    manage();
	}
    fclose(fp);
}
TBOOK* read(int *n)//将文件中的内容提出
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
/*浏览图书*/
void scan()
{
	nodata();
	printf("********************************************************************************\n");
    printf("嘻嘻，你要怎么看图书馆中的书单呢？\n");
	printf("********************************************************************************\n");
	int ch;
	printf("1.我要输入书号来查看！\n");
	printf("2.还是输入书名来查看适合我\n");
    printf("3.只看没借出的书\n");
	printf("4.就要看借出去的书\n");
	printf("5.给我打印整个书单，我就是任性\n");
	printf("6.我要回到上一级！\n");
	printf("********************************************************************************\n");
	do
	{
		printf("你要选择哪一个呢？\n");
		printf("我选:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("现在开始输入书号查看啦\n");
	        printf("********************************************************************************\n");
			scannum();//按书号
			break;
		case 2:
			system("CLS");
			printf("********************************************************************************\n");
            printf("现在可以输入书名来查看喽\n");
	        printf("********************************************************************************\n");
			scanname();//按书名
			break;
		case 3:
			system("CLS");
			printf("********************************************************************************\n");
            printf("下面都是还没借出去的书哈\n");
	        printf("********************************************************************************\n");
			scanzero();//未借出
			break;
		case 4:
			system("CLS");
			printf("********************************************************************************\n");
            printf("下面都是已经借出去的书呢\n");
	        printf("********************************************************************************\n");
			scanone();//已借出
			break;
		case 5:
			system("CLS");
			printf("********************************************************************************\n");
            printf("你这么任性我只好把所有书给你看了\n");
	        printf("********************************************************************************\n");
			scanall();//所有书
			system("CLS");
			scan();
			break;
		case 6:
			system("CLS");
			break;
		default:
			printf("你是不是故意输错的>__<\n");
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
		printf("请输入要被揪出来看的书的书号:");
		a=scanf("%d",&s);
		getchar();
		if(a!=1)
		{
			printf("你输入的是什么鬼\n");
			fflush(stdin);
		}
	}while(a!=1);
	printf("书号       书名       作者      出版日期         书价        是否借出\n");
	for(i=0;i<n;i++)
	{
		if(s==(b+i)->booknum)
		{
			flag=1;
			printf("%d%14s%11s%9d-%d-%d%13.1f",(b+i)->booknum,(b+i)->name,(b+i)->author,(b+i)->pubtime.year,(b+i)->pubtime.month,(b+i)->pubtime.day,(b+i)->price);
			if((b+i)->borrow==0)
			{
				printf("          否\n");
			}
			else if((b+i)->borrow==1)
			{
				printf("          是\n");
			}
        }
	}
	if(flag==0)
	{
		printf("大爷，你再打印一遍书单看看有没这个编号吧！按任意键回管理员菜单！\n");
	}
	else if(flag==1)
	{
		printf("看完了就按任意键回到上级菜单！\n");
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
		printf("请输入要被揪出来看的书的书名:");
		scanf("%s",s);
		getchar();
		if(strlen(s)>30)
		{
			printf("大哥输太长了！最多输入30个字符\n");
		}
	}while(strlen(s)>30);
	printf("书号       书名       作者      出版日期         书价        是否借出\n");
	for(i=0;i<n;i++)
	{
		if(strcmp(s,(b+i)->name)==0)
		{
			flag=1;
			printf("%d%14s%11s%9d-%d-%d%13.1f",(b+i)->booknum,(b+i)->name,(b+i)->author,(b+i)->pubtime.year,(b+i)->pubtime.month,(b+i)->pubtime.day,(b+i)->price);
			if((b+i)->borrow==0)
			{
				printf("          否\n");
			}
			else if((b+i)->borrow==1)
			{
				printf("          是\n");
			}
		}
	}
	if(flag==0)
	{
		printf("大爷，你再打印一遍书单看看有没这个名字吧！按任意键回管理员菜单！\n");
	}
	else if(flag==1)
	{
		printf("看完了就按任意键回到上级菜单！\n");
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
	printf("书号       书名       作者      出版日期         书价\n");
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
	    printf("看完了就按任意键回到上级菜单！\n");
	}
	else if(flag==0)
	{
	    printf("哎！书都被借光了！按任意键回到上级菜单！\n");
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
	printf("书号       书名       作者      出版日期         书价\n");
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
	    printf("看完了就按任意键回到上级菜单！\n");
	}
	else if(flag==0)
	{
	    printf("哎！书一本都没借出去！按任意键回到上级菜单！\n");
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
	printf("书号       书名       作者      出版日期         书价        是否借出\n");
	for(j=0;j<n;j++)
	{
	    printf("%d%14s%11s%9d-%d-%d%13.1f",(b+j)->booknum,(b+j)->name,(b+j)->author,(b+j)->pubtime.year,(b+j)->pubtime.month,(b+j)->pubtime.day,(b+j)->price);
		if((b+j)->borrow==0)
		{
			printf("          否\n");
		}
		else if((b+j)->borrow==1)
		{
			printf("          是\n");
		}
	}
	free(b);
    printf("已经按你的要求显示出书单了！按任意键回到上级菜单吧\n");
	inp=getchar();
	inp=getchar();
}
/*修改图书*/
void edit()
{
	nodata();
	int ch;
	printf("1.我要输入书号来修改！\n");
	printf("2.还是输入书名来修改适合我\n");
	printf("3.我要回到上一级！\n");
	printf("********************************************************************************\n");
	do
	{
		printf("你要选择哪一个呢？\n");
		printf("我选:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("现在开始输入书号修改啦\n");
	        printf("********************************************************************************\n");
			editnum();//按书号修改
			break;
		case 2:
			system("CLS");
			printf("********************************************************************************\n");
            printf("现在可以输入书名来修改喽\n");
	        printf("********************************************************************************\n");
			editname();//按书名修改
			break;
		case 3:
			system("CLS");
			manage();//返回上级
			break;
		default:
			printf("你是不是故意输错的>__<\n");
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
		printf("请输入要被改得面目全非的书的书号:");
		a=scanf("%d",&s);
		getchar();
		if(a!=1)
		{
			printf("你输入的是什么鬼\n");
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
		printf("大爷，你再打印一遍书单看看有没这个编号吧！按任意键回管理员菜单！\n");
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
		printf("请输入要被改得面目全非的书的书名:");
		scanf("%s",s);
		getchar();
		if(strlen(s)>30)
		{
			printf("大哥输太长了！最多输入30个字符\n");
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
		printf("大爷，你再打印一遍书单看看有没这个名字吧！按任意键回管理员菜单！\n");
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
    printf("快坦白你打算改这本书的什么信息？\n");
	printf("********************************************************************************\n");
	printf("1.自以为是的书号\n");
	printf("2.狂妄自大的书名\n");
    printf("3.惹人不快的作者名\n");
	printf("4.南辕北辙的出版年份\n");
	printf("5.胡乱写下的出版月份\n");
	printf("6.啼笑皆非的出版日\n");
    printf("7.令人发指的书价\n");
    printf("8.久未更新的借阅情况\n");
	printf("9.我要回到上一级！\n");
	printf("********************************************************************************\n");
	do
	{
		printf("你要选择哪一个呢？\n");
		printf("我选:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			do
			{
				printf("重新输入书号:");
				a=scanf("%d",&(b+i)->booknum);
				getchar();
				if(a!=1)
				{
					printf("你输入的是什么鬼\n");
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
				printf("重新输入书名:");
				scanf("%s",(b+i)->name);
				getchar();
				if(strlen((b+i)->name)>30)
				{
					printf("大哥输太长了！最多输入30个字符\n");
				}
			}while(strlen((b+i)->name)>30);
			break;
		case 3:
			system("CLS");
			do
			{
				printf("重新输入作者:");
				scanf("%s",(b+i)->author);
				getchar();
				if(strlen((b+i)->author)>30)
				{
					printf("大哥输太长了！最多输入30个字符\n");
				}
			}while(strlen((b+i)->author)>30);
			break;
		case 4:
			system("CLS");
			do
			{
				printf("重新输入出版年份:");
				a=scanf("%d",(b+i)->pubtime.year);
				getchar();
				if(a!=1)
				{
					printf("你输入的是什么鬼\n");
					fflush(stdin);
				}
				else if((b+i)->pubtime.year<(-2000))
				{
					printf("%d年有书籍吗？你素质是不是应该高点\n",(b+i)->pubtime.year);
					fflush(stdin);
				}
				else if((b+i)->pubtime.year>2020)
				{
					printf("貌似还没到%d年吧？你素质是不是应该高点\n",(b+i)->pubtime.year);
					fflush(stdin);
				}
			}while(a!=1);
			break;
		case 5:
			system("CLS");
			do
			{
				printf("重新输入出版月份:");
				a=scanf("%d",&(b+i)->pubtime.month);
				getchar();
				if(a!=1)
				{
					printf("你输入的是什么鬼\n");
					fflush(stdin);
				}
				else if((b+i)->pubtime.month<1||(b+i)->pubtime.month>12)
				{
					printf("月份有%d月吗？碰上傻子了\n",(b+i)->pubtime.month);
					fflush(stdin);
				}
			}while(a!=1||(b+i)->pubtime.month<1||(b+i)->pubtime.month>12);
			break;
		case 6:
			system("CLS");
			do
			{
				printf("重新输入出版日:");
				a=scanf("%d",&(b+i)->pubtime.day);
				getchar();
				if(a!=1)
				{
					printf("你输入的是什么鬼\n");
					fflush(stdin);
				}
				else if((b+i)->pubtime.day<1||(b+i)->pubtime.day>31)
				{
					printf("日期有%d日吗？碰上傻子了\n",(b+i)->pubtime.day);
					fflush(stdin);
				}
			}while(a!=1||(b+i)->pubtime.day<1||(b+i)->pubtime.day>31);
			break;
        case 7:
			system("CLS");
			do
			{
				printf("重新输入书价:");
				a=scanf("%f",&(b+i)->price);
				getchar();
				if(a!=1)
				{
					printf("你输入的是什么鬼\n");
					fflush(stdin);
				}
			}while(a!=1);
			break;
		case 8:
			system("CLS");
			do
			{
				printf("重新输入书有没借出去（0表示未借出，1表示已借出）:");
				scanf("%d",&(b+i)->borrow);
				getchar();
				if((b+i)->borrow!=1&&(b+i)->borrow!=0)
				{
					printf("你输入的是什么鬼\n");
					fflush(stdin);
				}
			}while((b+i)->borrow!=1&&(b+i)->borrow!=0);
			break;
		case 9:
			system("CLS");
			printf("********************************************************************************\n");
            printf("修改图书时间！修改图书时间！\n");
	        printf("********************************************************************************\n");
			edit();//返回上级
			break;
		default:
			printf("你是不是故意输错的>__<\n");
			break;
		}
		fp=fopen("book.dat","wb");
		for(j=0;j<n;j++)
		{
	        fwrite(b+j,sizeof(struct BOOK),1,fp);
		}
	    fclose(fp);
		free(b);
	    printf("改好啦！按任意键回到管理员菜单吧\n");
	    inp=getchar();
	    inp=getchar();
	    manage();
	}while(ch!=1&&ch!=2&&ch!=3&&ch!=4&&ch!=5&&ch!=6&&ch!=7&&ch!=8&&ch!=9);
}
/*删除图书*/
void del()
{
	nodata();
	int ch,inp;
	printf("1.我要输入书号来删除！\n");
	printf("2.还是输入书名来删除适合我\n");
    printf("3.还不如把所有书全删了爽\n");
	printf("4.我要回到上一级！\n");
	printf("********************************************************************************\n");
	do
	{
		printf("你要选择哪一个呢？\n");
		printf("我选:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("现在开始输入书号删除啦\n");
	        printf("********************************************************************************\n");
			delnum();//按书号删除
			break;
		case 2:
			system("CLS");
			printf("********************************************************************************\n");
            printf("现在可以输入书名来删除喽\n");
	        printf("********************************************************************************\n");
			delname();//按书名删除
			break;
		case 3:
			system("CLS");
			printf("********************************************************************************\n");
            printf("所有图书信息都被删光啦！\n");
	        printf("********************************************************************************\n");
			remove("book.dat");//直接删除文件
			printf("按任意键回到管理员菜单吧\n");
	        inp=getchar();
	        inp=getchar();
	        manage();
			break;
		case 4:
			system("CLS");
			manage();//返回上级
			break;
		default:
			printf("你是不是故意输错的>__<\n");
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
		printf("请输入要被处斩的书的书号:");
		a=scanf("%d",&s);
		getchar();
		if(a!=1)
		{
			printf("你输入的是什么鬼\n");
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
		printf("大爷，你再打印一遍书单看看有没这个编号吧！按任意键回管理员菜单！\n");
	}
	else if(flag==1)
	{
		printf("已经把那本该死的书删掉了！按任意键回到管理员菜单吧\n");
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
		printf("请输入要被处斩的书的书名:");
		scanf("%s",s);
		getchar();
		if(strlen(s)>30)
		{
			printf("大哥输太长了！最多输入30个字符\n");
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
		printf("大爷，你再打印一遍书单看看有没这个名字吧！按任意键回管理员菜单！\n");
	}
	else if(flag==1)
	{
		printf("已经把那本该死的书删掉了！按任意键回到管理员菜单吧\n");
	}
	inp=getchar();
	inp=getchar();
	manage();
}
/*排序图书*/
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
	printf("轻松排好！按任意键回到管理员菜单吧\n");
	inp=getchar();
	inp=getchar();
	manage();
}
void changepass()//更改密码
{
	char pw[30];
	struct manage set;
	FILE* fp1=NULL;
	FILE* fp2=NULL;
	int k,a,b,d,inp;
	printf("请输入用户名吧:");
	scanf("%s",set.sn);
	do
	{
		printf("该输入密码了:");
		scanf("%s",set.sw);
		printf("再输入密码确认一下咯:");
		scanf("%s",pw);
		k=strcmp(set.sw,pw); //对2次输入的密码进行比较
		a=strlen(set.sw); //取2次密码的长度，取用户名的长度
		b=strlen(pw);
		d=strlen(set.sn);
		if (k!=0)   //判断2次密码是否一致
		{ 
			printf("老大，两次输入的密码不一样哎!\n");
		}
		else if (a>15||b>15||d>15)   //判断用户名和密码是否符合长度规范
		{
			printf("你输的太长了！\n");
		}
	}while(a>15||b>15||d>15||k!=0);
    fp1=fopen("passname.dat","wb");  
	fwrite(&set.sn,sizeof(struct manage),1,fp1);
	fclose(fp1);
	fp2=fopen("password.dat","wb");  
	fwrite(&set.sw,sizeof(struct manage),1,fp2);
	fclose(fp2);
	printf("搞定了!要记好你的帐号和密码哦!!现在按任意键进入管理菜单");
	inp=getchar();
	inp=getchar();
	manage();   //密码创建完毕后进入管理员服务列表
}
void password()//管理员输入密码
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
	printf("哼哼，现在需要验证一下你的身份\n");
	printf("注意用户名和密码都是不超过20位滴\n");
	printf("********************************************************************************\n");
	if ((fp1=fopen("passname.dat","rb"))==NULL||(fp2=fopen("password.dat","rb"))==NULL) //判断文件是否存在，不存在就创建该信息文件
	{
		printf("哎你怎么还没创建管理员帐户!按任意键立刻创建!\n");
		inp=getchar();
		system("CLS");
		printf("********************************************************************************\n");
        printf("第一次创建用户你会不会羞涩啊\n");
	    printf("********************************************************************************\n");
        changepass();
	}
	for(i=1;i<=3;i++)
	{
		setname=fopen("passname.dat","rb");
	    fread(&set.sn,sizeof(struct manage),1,setname);
		fclose(setname);
	    printf("请输入用户名吧:");
		scanf("%s",passname);
		getchar();
		setword=fopen("password.dat","rb");
	    fread(&set.sw,sizeof(struct manage),1,setword);
        fclose(setword);
	    printf("该输入密码了:");
		scanf("%s",password);
		getchar();
		j=strcmp(passname,set.sn);
		k=strcmp(password,set.sw);
        if(j==0&&k==0)
		{
			manage();//密码输入正确
		}
		else
		{
			printf("输错了！你已经用了%d次机会\n",i);//密码输入错误
		}
	}
    do
	{
		printf("你没有机会了,退出(t)还是返回主页面(f)？");
		scanf("%c",&c);
		getchar();
		if(c=='t')
		{
			system("CLS");
			printf("希望能和你再见！\n");//退出
			exit(0);
		}
		else if(c=='f')
			index();
		else
			printf("你是不是故意输错的>__<\n");
	}while(c!='t'&&c!='f');
}
/*管理员查询方式*/
void manage()
{
	system("CLS");
	int ch;
	printf("********************************************************************************\n");
    printf("作为一名高素质的图书馆管理员，你打算做什么呢？\n");
	printf("********************************************************************************\n");
    printf("1.把图书信息录入进去\n");
	printf("2.查阅海量图书信息\n");
    printf("3.改一改图书信息\n");
	printf("4.删掉不要的图书信息\n");
	printf("5.给图书信息排个序\n");
	printf("6.换一组酷炫的用户名和密码\n");
	printf("7.我要回到上一级！\n");
	printf("********************************************************************************\n");
	do
	{
		printf("你要选择哪一个呢？\n");
		printf("我选:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("要开始录入书籍信息了，好紧张！\n");
	        printf("********************************************************************************\n");
			add();//录入图书
			break;
		case 2:
			system("CLS");
			scan();//浏览图书
			system("CLS");
            manage();
			break;
		case 3:
			system("CLS");
			printf("********************************************************************************\n");
            printf("修改图书时间！修改图书时间！\n");
	        printf("********************************************************************************\n");
			edit();//修改图书
			break;
		case 4:
			system("CLS");
			printf("********************************************************************************\n");
            printf("看哪本图书不爽了啊？\n");
	        printf("********************************************************************************\n");
			del();//删除图书
			break;
		case 5:
			system("CLS");
			printf("********************************************************************************\n");
            printf("看我乾坤大挪移！！\n");
	        printf("********************************************************************************\n");
			order();//排序图书
			break;
		case 6:
			system("CLS");
			printf("********************************************************************************\n");
            printf("听说你要改密码，那么开始吧\n");
	        printf("********************************************************************************\n");
			changepass();//改密码
			break;
		case 7:
			system("CLS");
			index();//返回上级
			break;
		default:
			printf("你是不是故意输错的>__<\n");
			break;
		}
	}while(ch!=1&&ch!=2&&ch!=3&&ch!=4&&ch!=5&&ch!=6&&ch!=7);
}
/*游客查询方式*/
void borrow()
{
	system("CLS");
	nodata();
	printf("********************************************************************************\n");
    printf("啥？借书？你要咋借？\n");
	printf("********************************************************************************\n");
	int ch;
	printf("1.我要输入书号来借书！\n");
	printf("2.还是输入书名来借书适合我\n");
    printf("3.我懒得返回上一级了，就在这级给我显示所有图书！\n");
	printf("4.我要回到上一级！\n");
	printf("********************************************************************************\n");
	do
	{
		printf("你要选择哪一个呢？\n");
		printf("我选:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("现在开始输入书号借书啦\n");
	        printf("********************************************************************************\n");
			borrownum();//按书号借阅
			break;
		case 2:
			system("CLS");
			printf("********************************************************************************\n");
            printf("现在可以输入书名来借书喽\n");
	        printf("********************************************************************************\n");
			borrowname();//按书名借阅
			break;
		case 3:
			system("CLS");
			printf("********************************************************************************\n");
            printf("懒死你算了！\n");
	        printf("********************************************************************************\n");
			scanall();//显示所有图书
			borrow();
			break;
		case 4:
			system("CLS");
			user();//返回上级
			break;
		default:
			printf("你是不是故意输错的>__<\n");
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
		printf("请输入要借的的书的书号:");
		a=scanf("%d",&s);
		getchar();
		if(a!=1)
		{
			printf("你输入的是什么鬼\n");
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
				printf("别闹了，这本书被借走了，你不会要去抢吧？按任意键回管理员菜单！\n");
				inp=getchar();
				inp=getchar();
				borrow();
			}
		}
	}
    if(flag==0)
	{
		printf("大爷，你再打印一遍书单看看有没这个编号吧！按任意键回管理员菜单！\n");
	}
	else if(flag==1)
	{
		printf("书已经借好了，不好好保管我可不饶你！看完了就按任意键回到上级菜单！\n");
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
		printf("请输入要借的书的书名:");
		scanf("%s",s);
		getchar();
		if(strlen(s)>30)
		{
			printf("大哥输太长了！最多输入30个字符\n");
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
				printf("别闹了，这本书被借走了，你不会要去抢吧？按任意键回上级菜单！\n");
				inp=getchar();
				inp=getchar();
				borrow();
			}
		}
	}
	if(flag==0)
	{
		printf("大爷，你再打印一遍书单看看有没这个名字吧！按任意键回管理员菜单！\n");
	}
	else if(flag==1)
	{
		printf("书已经借好了，不好好保管我可不饶你！看完了就按任意键回到上级菜单！\n");
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
    printf("作为一名有迫切需求的用户，你需要什么服务呢？\n");
	printf("********************************************************************************\n");
    printf("1.至少先让我看一下书单吧！\n");
	printf("2.嘿嘿，我要借书\n");
	printf("3.我要回到上一级！\n");
	printf("********************************************************************************\n");
	do
	{
		printf("你要选择哪一个呢？\n");
		printf("我选:\n");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
		case 1:
			system("CLS");
			printf("********************************************************************************\n");
            printf("经素质特高的管理员授权，你可以查看书单！\n");
	        printf("********************************************************************************\n");
			scan();//显示书单
			system("CLS");
			user();
			break;
	    case 2:
            borrow();//借书
			break;
		case 3:
			system("CLS");
			index();//返回上级
			break;
		default:
			printf("你是不是故意输错的>__<\n");
			break;
		}
	}while(ch!=1&&ch!=2&&ch!=3);
}
/*主页面*/
void index()
{
	system("CLS");
	int c;
	printf("********************************************************************************\n");
	printf("欢迎来到郝帅的图书馆管理系统，我这就让你见识一下高素质的图书馆管理员的风采\n");
    printf("********************************************************************************\n");
    printf("1.萌萌哒管理员系统\n");
	printf("2.超级耐用的用户系统\n");
	printf("3.真的要退出吗>__<\n");
	printf("********************************************************************************\n");
	do
	{
		printf("你要选择哪一个呢？\n");
		printf("我选:\n");
		scanf("%d",&c);
		getchar();
		switch(c)
		{
		case 1:
			system("CLS");
			password();//管理员密码系统
			break;
		case 2:
			system("CLS");
			user();//用户系统
			break;
		case 3:
			system("CLS");
			printf("希望能和你再见！\n");//退出
			exit(0);
			break;
		default:
			printf("你是不是故意输错的>__<\n");
		}
	}while(c!=1&&c!=2&&c!=3);
}