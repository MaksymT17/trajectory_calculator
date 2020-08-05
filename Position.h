#ifndef POSITION_HEADER
#define POSITION_HEADER
struct Position
{
	Position(float x = 0, float y = 0);

	~Position();

	void Move(float dX, float dY);

	float mX, mY;
};
#endif