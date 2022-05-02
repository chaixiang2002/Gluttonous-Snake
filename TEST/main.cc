
#include <cstdlib>
#include <iterator>
#include <ostream>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>
struct Position{
    int x,y;
    Position(int x,int y):x(x),y(y){}
    static Position get_position(int xx,int yy){
        Position res(xx,yy);
        return res;
    }

    bool is_equal(Position& t){
        if (x==t.x&&y==t.y) return true;
        return false;
    }
};
typedef std::vector<std::string> Window;

struct Screen{
    Window window;
    int width, hight;
    std::string name;
    int freq;

    void set_freq(int t){
        freq=t;
    }
    bool is_legal(Position pos){
        if(pos.x>-1&&pos.x<width && pos.y>-1&&pos.y<hight)
            return true;

        while(true){
            std::cerr<<"error:01"<<std::endl;
        }
        return false;
    }
    void set_name(std::string str){
        name=str;
    }
    void set_width_hight(int wid,int hig){
        width=wid;
        hight=hig;
    }
    Window get_window(){
        std::string str(width,' ');
        Window res(hight,str);
        return res;
    }

    Screen(std::string str){
        /*
            待添加
        */
        set_width_hight(60, 20);
        window=get_window();
        set_name(str);
        set_freq(500000);
    }
    void snake_wall(){
        std::string t(width,'=');
        window[0]=t;
        window[hight-1]=t;
        for (int i=1; i<hight-1; i++) {
            window[i][0]='|';
            window[i][width-1]='|';
        }
    }
    void print(){
        std::system("clear");
        std::cout<<"\t\t    『"<<name<< "』"<<std::endl;
        for(auto& t:window){
            for(auto& tmp:t){
                std::cout<<tmp;
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
    void update_window(std::queue<Position>& que,Position food){
        while (!que.empty()) {
            auto& t=que.front();
            if(!is_legal(t))//////////////////////??????
                return;
            window[t.y][t.x]='o';
            que.pop();
        }

        window[food.y][food.x]='?';
    }
};


class Snake:public Screen{
    std::queue<Position> snake;
    bool state;
    Position food;
    int dir;


    void set_food(){
        food=Position::get_position
            (rand()%(width-2)+1,rand()%(hight-2)+1);
    }
    // Position get_food(){
    //     return food;
    // }
    bool is_wall(int& x,int& y){
        if(window[y][x]=='=' || window[y][x]=='|')
            return true;
        return false;
    }
    bool is_snake(int& x,int& y){/////////?????????
        auto que_copy=snake;
        while (!que_copy.empty()) {
            auto& t=que_copy.front();
            if(t.x==x&&t.y==y)
                return true;
            que_copy.pop();
        }
        return false;
    }
    bool is_food(Position& t){
        return food.is_equal(t);
    }
    bool is_dead(int& x,int& y){
        if(is_wall(x, y)|| is_snake(x, y)){
            std::cout<<"you dead!!!!"<<std::endl;
            state=0;
            return true;
        }
        return false;
    }
    void push_in_que(int x,int y){
        if (is_dead(x,y)) {
            //game_over();//////////////////////////////??????
        } else {
            Position t=Position::get_position(x, y);
            snake.push(t);
            if(is_food(t)){
                set_food();
            } else {
                snake.pop();
            }
        }
    }
    void walk(){
        switch (dir) {
        case 97://left
            push_in_que(snake.back().x-1,snake.back().y);
            break;
        case 100://right
            push_in_que(snake.back().x+1,snake.back().y);
            break;
        case 119://up
            push_in_que(snake.back().x,snake.back().y-1);
            break;
        case 115://down
            push_in_que(snake.back().x,snake.back().y+1);
            break;
        }
    }

public:
    Snake(std::string):Screen("Gluttonous Sanke")
        ,food( Position::get_position(10,10) ){

        state=1;
        set_food();
        set_dir(97);
        snake.push(Position::get_position(33, 10));
        snake.push(Position::get_position(32, 10));
        snake.push(Position::get_position(31, 10));
        snake.push(Position::get_position(30, 10));
    }
    void set_dir(int d){
        if(d<96)
            d+='a'-'A';
        //if(d==97||d==100||d==119||d==115)
        if(d==97&&dir!=100)   dir=d;
        else if(d==100&&dir!=97)   dir=d;
        else if(d==119&&dir!=115)   dir=d;
        else if(d==115&&dir!=119)   dir=d;
    }
    bool get_state(){
        return state;
    }
    void looping_body(){
        update_window(snake, food);
        print();
        walk();
    }
};

int main(){
    Snake mysnake("Gluttonous Snake");
    mysnake.snake_wall();
    auto game=[&]{
        while (mysnake.get_state()) {
            mysnake.looping_body();
            usleep(mysnake.freq);
        }
    };
    // auto user_scanf=[&]{
    //     while (mysnake.get_state()) {
    //         mysnake.set_dir(get_char());
    //         usleep(mysnake.freq);
    //     }
    // };
    std::thread thread_game(game);
    //std::thread thread_scanf(user_scanf);

    while(true){}
    return 0;
}