#include "MazeGenerator.h"
#include "cinder\Rand.h"

using namespace ci;
using namespace ci::app;

MazeGenerator::MazeGenerator()
{

}

MazeGenerator::~MazeGenerator()
{

}

void MazeGenerator::setup()
{
	for (int x = 0; x < X_MAX; x++)
	{
		for (int y = 0; y < Y_MAX; y++)
		{
			mWalls[x][y] = 15;
		}
	}

	//get a solution
	int x = 0, y = 0;
	while (x != X_MAX && y != Y_MAX)
	{
		if (x >= X_MAX - 1)
			mSolution[x][y] = DOWN;
		else if (y >= Y_MAX - 1)
			mSolution[x][y] = RIGHT;
		else
		{
			if (ci::randInt(2) == 0)
			{
				mSolution[x][y] = DOWN;
			}
			else
			{
				mSolution[x][y] = RIGHT;
			}
		}

		switch (mSolution[x][y])
		{
		case LEFT:
			mWalls[x][y] &= 14;
			if (x > 0)
				mWalls[x - 1][y] &= 11;
			x--;
			break;
		case UP:
			mWalls[x][y] &= 13;
			if (y > 0)
				mWalls[x][y-1] &= 7;
			y--;
			break;
		case RIGHT:
			mWalls[x][y] &= 11;
			if (x < X_MAX - 1 )
				mWalls[x+1][y] &= 14;
			x++;
			break;
		case DOWN:
			mWalls[x][y] &= 7;
			if (y < Y_MAX - 1)
				mWalls[x][y+1] &= 13;
			y++;
			break;
		}
	}
}

void MazeGenerator::update()
{

}

void MazeGenerator::draw()
{
	gl::color(ci::Color::white());
	gl::begin(GL_LINES);
	for (int x = 0; x < X_MAX; x++)
	{
		for (int y = 0; y < Y_MAX; y++)
		{
			Vec2f vert1(x*getWindowWidth()/X_MAX, y * getWindowHeight()/Y_MAX);
			Vec2f vert2((x+1)*getWindowWidth() / X_MAX, y * getWindowHeight() / Y_MAX);
			Vec2f vert3(x*getWindowWidth() / X_MAX, (y+1) * getWindowHeight() / Y_MAX);
			Vec2f vert4((x+1)*getWindowWidth() / X_MAX, (y+1) * getWindowHeight() / Y_MAX);
			if (1 & mWalls[x][y])
			{
				gl::vertex(vert1);
				gl::vertex(vert3);
			}
			if (2 & mWalls[x][y])
			{
				gl::vertex(vert1);
				gl::vertex(vert2);
			}
			if (4 & mWalls[x][y])
			{
				gl::vertex(vert2);
				gl::vertex(vert4);
			}
			if (8 & mWalls[x][y])
			{
				gl::vertex(vert3);
				gl::vertex(vert4);
			}
			//gl::drawSolidCircle(vert, 2.f);
		}
	}

	gl::end();
}