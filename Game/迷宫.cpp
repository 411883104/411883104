#include<cstdio>
#include<windows.h>
#include<conio.h>
using namespace std;
char arr[50][50]={"############",
 				  "#O#    #   #",
 				  "#   ## # # #",
 				  "#####    # #",
 				  "#     #### #",
 				  "# #####  # #",
 				  "#       ##  ",
 				  "############"};

int main()
{
	int x=1,y=1;
	char ch;
	for(int i=0;i<=7;i++)
	{
		puts(arr[i]);
	}
	while(1)
	{
		ch=getch();
		if(ch=='s')
		{
			if(arr[x+1][y]==' ')
			{
				arr[x][y]=' ';
				x++;
				arr[x][y]='0';
			}
		}
		if(ch=='w')
		{
			if(arr[x-1][y]==' ')
			{
				arr[x][y]=' ';
				x--;
				arr[x][y]='0';
			}
		}
		if(ch=='a')
		{
			if(arr[x][y-1]==' ')
			{
				arr[x][y]=' ';
				y--;
				arr[x][y]='0';
			}
		}
		if(ch=='d')
		{
			if(arr[x][y+1]==' ')
			{
				arr[x][y]=' ';
				y++;
				arr[x][y]='0';
			}
		}
		system("cls");
		for(int i=0;i<=7;i++)
		{
			puts(arr[i]);
		}
		if(x==6&&y==11)
			break;
	}
	printf("win!");
	Sleep(10000);
	return 0;
 } 
