#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
#include <tuple>


using namespace std;

ifstream f("disjoint.in");
ofstream g("disjoint.out");


class graf{
private:
    int n, m;
    int parinte[100001], dimensiune[100001];
public:
    graf(int n, int m);
    int radacina_disjuncte(int n);
    void uniune_disjuncte(int x, int y);
    void init(int n);
    bool aceeasi_padure(int x, int y);
    void disjuncte(int n);
};

graf :: graf(int n, int m)
{
    this->n = n;
    this->m = m;
}

int graf :: radacina_disjuncte(int n)
{
   while(n!=parinte[n]){
        parinte[n]=radacina_disjuncte(parinte[n]);
        return parinte[n];
    }
    return n;
}

void graf :: uniune_disjuncte(int x, int y)
{
    if ( radacina_disjuncte(x) != radacina_disjuncte(y) )
    {
        if ( dimensiune[radacina_disjuncte(x)] > dimensiune[radacina_disjuncte(y)] )
            {parinte[radacina_disjuncte(y)] = radacina_disjuncte(x);
            dimensiune[x] += dimensiune[y];}
        else
        {
            parinte[radacina_disjuncte(x)] = radacina_disjuncte(y);
            dimensiune[y] += dimensiune[x];
        }
    }
}
void graf :: init(int n){
    for ( int i = 1; i <= n; i++ )
        {parinte[i] = i;
        dimensiune[i]=1;}
}

bool graf::aceeasi_padure(int x, int y){
    if (radacina_disjuncte(x)==radacina_disjuncte(y))
        return true;
    return false;
}

void graf :: disjuncte(int n)
{
    int comanda,x,y;

    init(n);
    for (int i = 1;i <= m;i++)
    { f>>comanda>>x>>y;
        if (comanda == 1)
            uniune_disjuncte(x,y);
        else if(comanda ==2)
        {if (aceeasi_padure(x,y))
                g<<"DA\n";
        else g<<"NU\n";}
    }
}

int main()
{
    int n, m;
    f >> n >> m;
    graf G(n, m);
    G.disjuncte(n);
    return 0;
}
