#include <iostream>
#include <iomanip>
#include "prato.h"

using namespace std;

void print_game(BoardGame* game)
{
    for (auto y = 0; y < game->rows(); ++y)
    {
        for (auto x = 0; x < game->cols(); ++x)
        {

            cout << setw(3) << game->get_val(x, y);

        }
        cout << endl;
    }
}
void play_game(BoardGame* game)
{
    print_game(game);
    while (! game->finished())
    {
        string morf;
        int x, y;
        cout << endl << "Move or flag at? ";
        cin >> morf;
        cout<<endl<<"x,y?";
        cin>>x>>y;
        if(morf=="move"){
            game->play_at(x, y);
        }
        else{
            game->flag_at(x, y);
        }
        print_game(game);
    }
    cout << game->message() << endl;
}
int main()
{
    int w,h,n;
    cout<<"w,h,n??"<<endl;
    cin>>w>>h>>n;
    while (n>(w*h))
    {
        cout<<"n??"<<endl;
        cin>>n;
    }
    auto game = new prato{w,h,n};
    play_game(game);
    return 0;
}
