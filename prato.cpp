#include "prato.h"
#include<ctime>
#include <iostream>
#include <vector>
using namespace std;

prato::prato(int w, int h, int n)
{
    w_=w;
    h_=h;
    n_=n;
    matrix_.assign(h_, vector<int>(w_,0));
    open_.assign(h_, vector<bool>(w_,false));
    flag_.assign(h_, vector<bool>(w_,false));
    srand(time(nullptr));
    int i = 0;                                              // for random numbers)
    while (i < n_)
    {
        int y = rand() % (h_);
        int x = rand() % (w_);
        if (matrix_[y][x]==0)
        {
            matrix_[y][x]= -1;
            for (int a=x-1; a<=x+1; a++)
            {
                for(int b=y-1; b<=y+1; b++)
                {
                    if((b>=0  && b<h_) && (a>=0 && a<w_))
                    {
                        if((matrix_[b][a]!=-1))
                        {
                            matrix_[b][a]+=1;
                        }
                    }
                }

            }
            ++i;
        }
    }
}
void prato::play_at(int x, int y)
{
    if(matrix_[y][x]>=0)
    {
        open_[y][x]=true;
    }
    else
    {
        finish_=true;
        loose_=true;
    }

    if(matrix_[y][x]==0)
    {
        for (int a=x-1; a<=x+1; a++)
        {
            for(int b=y-1; b<=y+1; b++)
            {
                if(a>=0 && a<w_ && b>=0 && b<h_)
                {
                    if(open_[b][a]==false)
                    {
                        play_at(a,b);
                    }
                }
            }
        }
    }
}

string prato::get_val(int x, int y)
{
    if(open_[y][x]==true && 0 <= x && x < w_ && 0 <= y && y < h_)
    {
        return to_string(matrix_[y][x]);
    }
    else
    {
        if(flag_[y][x]==true)
        {
            return "%";
        }

    }
    return "x";
}

string prato::message()
{
    if(loose_==true)
    {
        return "oh you hit a bomb... you loose";
    }
    else
    {
        return "congrats you won!!";
    }
}

void prato::flag_at(int x, int y)
{
    if(open_[y][x]==true)
    {
        for (int a=x-1; a<=x+1; a++)
        {
            for(int b=y-1; b<=y+1; b++)
            {
                if(a>=0 && a<w_ && b>=0 && b<h_)
                {
                    if(flag_[b][a]==true){
                        band+=1
                    }
                }
            }
        }
        if(matrix_[x][y]==band){
            play_at()
        }
    }
    else
    {
        flag_[y][x]=true;
    }

}
