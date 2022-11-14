#include <iostream>
#include <conio.h>

using namespace std;

int st[100],n,nrsol;

int absolut(int x)
{
    if(x<0) 
    {
        x=-x;
        return x;
    }
}
int valid(int k)
{
    int i;
    for ( i = 1; i < k-1; i++)
    {
        if ((st[i]==st[k])||(absolut((st[k]-st[i]))==(k-i)))
        {
           return 0;
        }
    }
    return 1;
}


int main()
{


    
return 0;
}