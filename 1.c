#include <stdio.h>
#include <stdlib.h>
 
int p,q,m,n,min=888;    //��������m ������ n   (p,q)Ϊ�յ������
int total = 0;      //·������
int book[51][51];       //������� �����ж��¸������Ƿ��߹� �߹�����Ϊ1
int a[51][51];         // 1��ʾ�յ� 0��ʾ�ϰ���
int path1[51],path2[51];//����·����x��y����
 
void createload();//�����Թ�
void dfs(int x, int y, int step);//������������Թ�
void printload();//��ʾ�Թ����·��
 
//�����Թ�
void createload()
{
    int st,ed;
 int i,j;
 printf("-------------------��ʼ�����Թ�-------------------\n");
 printf("��ֱ������Թ���������������");
 scanf("%d %d", &m, &n);
 printf("�������Թ������ߵ�·������Ϊ1 �ϰ�������Ϊ0��\n");
 for (i=0; i <m; i++)
  for (j =0; j <n; j++)
   scanf("%d", &a[i][j]);
 
 printf("������������꣺\n");
 scanf("%d %d", &st, &ed);
 book[st][ed] = 1;
 
 printf("�������յ����꣺\n");
 scanf("%d %d", &p, &q);
 printf("-------------------�����Թ��ɹ���-------------------\n");
 printf("���·�����£�\n");
 printf("(%d,%d)",st,ed);
 dfs(st, ed, 0);
 printf("\n���·��Ϊ%d\n",min);
 a[st][ed] = 2;
 a[p][q] = 3;
}
 
 
//�����������
void dfs(int x, int y, int step) {
    int i;
 if (x == p&& y == q)
 {
  total++;
  if (step < min){  //���step��minС�����޸�min��ֵ
   min = step;
            for(i = 0; i < step; i++){
                printf("(%d,%d)",path1[i],path2[i]); //��ӡһά·��
                a[path1[i]][path2[i]] = 5;
            }
        }
  return;    //����������յ�ͻ���
 }else {
  if ( y + 1 <= n && a[x][y+1] == 1 && book[x][y+1]==0) //�жϱ߽��Լ��������Ƿ񱻱�Ǻ��Ƿ��ǿյ�
  {
   book[x][y+1] = 1;  // ��ȥ�׶Σ����ߵ���ǰλ�ã�������߹�
            path1[step] = x; //����x
      path2[step] = y+1; //����y
   dfs(x , y+1, step + 1); // ���и�λ�õ������������
            book[x][y+1] = 0; // ���ݽ׶Σ� ȡ���ñ�ǣ�����˳������ƶ�
  }
  if ( x + 1 <= m && a[x+1][y] == 1 && book[x+1][y ] == 0)
  {
   book[x+1][y] = 1;
            path1[step] = x+1; //����x
      path2[step] = y; //����y
   dfs(x+1, y , step + 1);
   book[x+1][y] = 0;
  }
  if (0 < y -1  && a[x][y -1] == 1 && book[x][y - 1] == 0)
  {
   book[x][y -1] = 1;
            path1[step] = x; //����x
      path2[step] = y-1; //����y
   dfs(x, y - 1, step + 1);
   book[x][y - 1] = 0;
  }
  if (0 < x -1  && a[x - 1][y] == 1 && book[x -1][y] == 0)
  {
   book[x - 1][y] = 1;
            path1[step] = x-1; //����x
      path2[step] = y; //����y
   dfs(x -1, y, step + 1);
   book[x -1][y] = 0;
  }
  return;  //����·����ʱ ������һ��λ�ã�
 }
}
 
//��ʾ�Թ�·��
void printload()
{
    int i,j;
    printf("���·����ʾ���£�\n");
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
