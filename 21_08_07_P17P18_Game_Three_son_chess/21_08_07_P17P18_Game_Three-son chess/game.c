#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>

void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}

//我的写法
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0;i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			if (j < col - 1)
//			{
//				printf(" %c |", board[i][j]);
//			}
//			else 
//			{
//				printf(" %c ", board[i][j]);
//			}
//		}
//		printf("\n");
//		if (i < row - 1) 
//		{
//			for (j = 0; j < col; j++)
//			{
//				if (j < col - 1)
//				{
//					printf("---|");
//				}
//				else
//				{
//					printf("---");
//				}
//			}
//		}
//		
//		printf("\n");
//		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//printf("---|---|---\n");
//	}
//教学的写法
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		if (i < row - 1) 
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋！\n");
	printf("请玩家输入棋盘坐标下棋：\n");
	//判断 x y坐标的合法性
	while(1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if ((board[x - 1][y - 1]) != ' ')
			{
				printf("此坐标已下过，请重新输入坐标！\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("坐标非法，请重新输入坐标！\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋！\n");
	while (1)
	{

		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}


}