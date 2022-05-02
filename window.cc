
#include <cstdlib>
#include <iterator>
#include <ostream>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include "Position.cc"
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

//测试
// int main(){
//     std::string str;
//     std::cin >>str;
//     Screen my_screen(str);
//     my_screen.snake_wall();

//     std::queue<Position> que;
//     que.push(Position::get_position(30, 10));
//     que.push(Position::get_position(31, 10));
//     que.push(Position::get_position(32, 10));
//     my_screen.update_window(que,Position::get_position(10, 10));
//     my_screen.print();
//     return 0;
// }