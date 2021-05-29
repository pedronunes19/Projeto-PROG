// T04_G02

#include "Post.hpp"


/**************************************************************************************************************/
// CONSTRUCTORS
Post::Post(){
	
}

Post::Post(int x, int y, char ch)
{
	pos = {x, y};
	symbol = ch;
}
/**************************************************************************************************************/


/**************************************************************************************************************/
// GET INFO
Position Post::getPos() const
{
	return pos;
}
/**************************************************************************************************************/


/**************************************************************************************************************/
// STATE RELATED METHODS
bool Post::isElectrified() const
{
	return ( symbol == '*' );
}

void Post::turnOff()
{
	symbol = '+';
}

bool Post::isExit() const
{
	return ( symbol == 'O' );
}

char Post::getSymbol() const{
	return symbol;
}
/**************************************************************************************************************/