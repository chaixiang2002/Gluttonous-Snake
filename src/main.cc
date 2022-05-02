#include "tc_snake.cc"
#include <term.h>
#include <unistd.h>
#include <thread>
#include "user_scanf.cc"

int main(){
    Snake mysnake("Gluttonous Snake");
    mysnake.set_freq(200000);
    mysnake.snake_wall();
    auto game=[&]{
        while (mysnake.get_state()) {
            mysnake.looping_body();
            usleep(mysnake.freq);
        }
    };
    auto user_scanf=[&]{
        while (mysnake.get_state()) {
            mysnake.set_dir(get_char());
            usleep(mysnake.freq);
        }
    };
    std::thread thread_game(game);
    std::thread thread_scanf(user_scanf);

    while(true){
        if(!mysnake.get_state()){
            sleep(1);
            return 0;
        }
    }
    return 0;
}