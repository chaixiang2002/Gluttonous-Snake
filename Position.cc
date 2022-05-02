


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