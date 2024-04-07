#include <bits/stdc++.h>
using namespace std;

int a[11][11]={0}; //��a�p�a��
int d[10][10]={0}; //�O�_���}
int flag=10,win=0;//�X�l�ơB���}����l��

void make()
{
    srand(time(NULL));
    int m, n, num=0;
    for(int i=1;i<=10;i++) //��m�a�p
    {
        do
        {
            m=rand()%9+1;
            n=rand()%9+1;
        }while(a[m][n]==10);
        for(int i=-1;i<2;i++) //�аO�Ʀr
        {
            for(int j=-1;j<2;j++)
            {
                if(a[m+i][n+j]!=10)a[m+i][n+j]++;
            }
        }
        a[m][n]=10;
    }
}

void printgame() //��X��
{
    cout << "    1   2   3   4   5   6   7   8   9   \n";
    cout << "  -------------------------------------\n";
    for(int i=1;i<=9;i++)
    {
        cout << i << " ";
        for(int j=1;j<=9;j++)
        {
            if(d[i][j]==0) cout << "| ? ";
            else if(d[i][j]==1)
            {
                if(a[i][j]==10) cout << "|�p ";
                else if(a[i][j]==0) cout << "|   ";
                else cout << "| " << a[i][j] <<" ";
            }
        else cout << "|�X ";
        }
        cout << "|"<<endl<<"  -------------------------------------\n";
    }
}

void large(int o,int p) //�۰ʫ���
{
    if(o<=9&&o>=1&&p<=9&&p>=1&&d[o][p]==0)
    {
        win++;
        d[o][p]=1;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(a[o+i][p+j]==0) large(o+i,p+j);
                else if((i!=0||j!=0)&&d[o+i][p+j]!=1&&o+i<=9&&o+i>=1&&p+j<=9&&p+j>=1)
                {win++;d[o+i][p+j]=1;}
            }
        }
    }
}

bool play() //�ާ@
{
    int x, y, action;
    do
    {
        cout << "�п�J�i���檺�ʧ@\n";
        cin >> action >> y >> x;
    }while((action!=1&&action!=2)||d[x][y]==1||x>9||x<1||y>9||y<1);
    if(action==1)
    {
        if(a[x][y]==0) large(x,y);
        else {win++;d[x][y]=1;}
        if(a[x][y]==10) return true;
    }
    else
    {
        if(d[x][y]==2)
        {
            d[x][y]=0;
            flag++;
        }
        else
        {
            d[x][y]=2;
            flag--;
        }
    }
    return false;
}

int main()
{
    make();
    while(win!=71)
    {
        printgame();
        cout << "flag:" <<flag<<"\n";
        if(play()) break;
    }
    if(win==71)
    {printgame();cout << "you win!\n";}
    else
    {
        cout << "you lose :(\n";
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++) d[i][j]=1;
        }
        printgame();
    }
}
