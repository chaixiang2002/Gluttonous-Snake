#include "window.cc"
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>

class Snake:public Screen{
    std::queue<Position> snake;
    bool state;
    Position food;
    int dir;


    void set_food(){
        Position t=Position::get_position
            (Position::get_rand()%(width-2)+1,Position::get_rand()%(hight-2)+1);
        if(t.is_equal(food)){
            set_food();
        } else {
            food=t;
        }
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
    void snake_clear(){
        for(int i=1;i<hight-1;++i){
            for(int j=1;j<width-1;++j){
                window[i][j]=' ';
            }
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
        snake_clear();
        update_window(snake, food);
        print();
        walk();
    }
};