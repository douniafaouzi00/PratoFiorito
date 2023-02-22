#ifndef PRATO_H
#define PRATO_H

#include "boardgame.h"
#include <string>
#include <vector>
using namespace std;

class prato : public BoardGame
{
public:
    prato(int w, int h, int n);
    void play_at(int x, int y);
    string get_val(int x, int y);
    int cols() { return w_; }
    int rows() { return h_; }
    void flag_at(int x, int y);
    bool finished(){return finish_;};
    string message();
private:
    int pos(int x, int y) { return x , y; }
    int w_, h_;
    int n_;
    int band_= 0;
    bool finish_=false;
    bool loose_=false;
    vector<vector<int>> matrix_;
    vector<vector<bool>>open_;
    vector<vector<bool>>flag_;


};

#endif
