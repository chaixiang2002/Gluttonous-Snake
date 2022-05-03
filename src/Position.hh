
#include <cstdlib>
#include <iostream>
#include <ctime>

struct Position{
    int x,y;
    Position(int x,int y):x(x),y(y){}
    static Position get_position(int xx,int yy){
        Position res(xx,yy);
        return res;
    }
    static int get_rand(){
        std::srand(std::time(0)); // 以当前时间为随机数生成器的种子
        return std::rand();
    }
    bool is_equal(Position& t){
        if (x==t.x&&y==t.y) return true;
        return false;
    }
};