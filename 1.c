#include <stdio.h>
#include <stdlib.h>
 
int p,q,m,n,min=888;    //设置行数m 与列数 n   (p,q)为终点的坐标
int total = 0;      //路径总数
int book[51][51];       //标记数组 用于判断下个坐标是否走过 走过则标记为1
int a[51][51];         // 1表示空地 0表示障碍物
int path1[51],path2[51];//保存路径的x，y坐标
 
void createload();//创建迷宫
void dfs(int x, int y, int step);//深度优先搜索迷宫
void printload();//显示迷宫最短路径
 
//创建迷宫
void createload()
{
    int st,ed;
 int i,j;
 printf("-------------------开始创建迷宫-------------------\n");
 printf("请分别输入迷宫的行数和列数：");
 scanf("%d %d", &m, &n);
 printf("请输入迷宫，可走的路径设置为1 障碍物设置为0：\n");
 for (i=0; i <m; i++)
  for (j =0; j <n; j++)
   scanf("%d", &a[i][j]);
 
 printf("请输入起点坐标：\n");
 scanf("%d %d", &st, &ed);
 book[st][ed] = 1;
 
 printf("请输入终点坐标：\n");
 scanf("%d %d", &p, &q);
 printf("-------------------创建迷宫成功！-------------------\n");
 printf("最短路径如下：\n");
 printf("(%d,%d)",st,ed);
 dfs(st, ed, 0);
 printf("\n最短路径为%d\n",min);
 a[st][ed] = 2;
 a[p][q] = 3;
}
 
 
//深度优先搜素
void dfs(int x, int y, int step) {
    int i;
 if (x == p&& y == q)
 {
  total++;
  if (step < min){  //如果step比min小，就修改min的值
   min = step;
            for(i = 0; i < step; i++){
                printf("(%d,%d)",path1[i],path2[i]); //打印一维路径
                a[path1[i]][path2[i]] = 5;
            }
        }
  return;    //如果到达了终点就回溯
 }else {
  if ( y + 1 <= n && a[x][y+1] == 1 && book[x][y+1]==0) //判断边界以及该坐标是否被标记和是否是空地
  {
   book[x][y+1] = 1;  // 递去阶段：当走到当前位置，标记已走过
            path1[step] = x; //缓存x
      path2[step] = y+1; //缓存y
   dfs(x , y+1, step + 1); // 进行该位置的深度优先搜索
            book[x][y+1] = 0; // 回溯阶段： 取消该标记，并按顺序继续移动
  }
  if ( x + 1 <= m && a[x+1][y] == 1 && book[x+1][y ] == 0)
  {
   book[x+1][y] = 1;
            path1[step] = x+1; //缓存x
      path2[step] = y; //缓存y
   dfs(x+1, y , step + 1);
   book[x+1][y] = 0;
  }
  if (0 < y -1  && a[x][y -1] == 1 && book[x][y - 1] == 0)
  {
   book[x][y -1] = 1;
            path1[step] = x; //缓存x
      path2[step] = y-1; //缓存y
   dfs(x, y - 1, step + 1);
   book[x][y - 1] = 0;
  }
  if (0 < x -1  && a[x - 1][y] == 1 && book[x -1][y] == 0)
  {
   book[x - 1][y] = 1;
            path1[step] = x-1; //缓存x
      path2[step] = y; //缓存y
   dfs(x -1, y, step + 1);
   book[x -1][y] = 0;
  }
  return;  //当无路可走时 回溯上一个位置；
 }
}
 
//显示迷宫路径
void printload()
{
    int i,j;
    printf("最短路径显示如下：\n");
 for (i=0; i <m; i++){
  for (j =0; j <n; j++){
   printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
 
 
int main()
{
    createload();
    printload();
 return 0;
}
