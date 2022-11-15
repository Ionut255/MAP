#include <iostream>
#include <conio.h>

using namespace std;

int st[100],n,nrsol;

int absolut(int x)
{
    if(x < 0) 
        x = -x;
    return x;
}
int valid(int k)
{
    int i;
    for ( i = 1; i < k-1; i++)
    {
        if ((st[i]==st[k])||(absolut((st[k] - st[i]))==(k - i)))
        {
           return 0;
        }
    }
    return 1;
}
int sol(int k)
{
    if(k==n)
        return 1;
    return 0;
}

void initializare(int k)
{
    st[k] = 0;
}

void tipar()
{
    int i,j;
    nrsol++;
    cout <<"\n Solutia " << nrsol <<" este: \n";
    for ( i = 1; i <= n; i++)
    {
        cout << endl;
        for (j = 1; j <=n; j++)
            if(st[j]==i)
             cout <<"D";
            else
             cout <<"+";
        
        
    }
    cout <<endl;
}
void back(int k)
{
    initializare(k);
    int i;
    for(i=1;i<=n;i++)
    {
        st[k]=i;
        if(valid(k)==1)
        {
            if(sol(k)==1)
             tipar();
            else
             back(k + 1);
        }
    }
}
int main()
{
    n=8;
    back(1);
    cout <<"\n Sunt"<<nrsol<<"solutii\n";
 return 0;
}