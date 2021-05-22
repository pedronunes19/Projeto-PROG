// T04_G02
#include "gamestructs.hpp"

class Post{
public:
    Post(int x, int y, char ch );
	Post(Position pos, char ch );
	Position getPos() const;
    bool isElectrified() const;
    void turnOff();

private:
    char electrified;  // 3 states -> '*' for electrified posts, '+' for non electrified posts, 'O' for exits
	Position pos;
};