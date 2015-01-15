#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/AppNative.h"

enum DIRECTIONS {
	LEFT,
	UP,
	RIGHT,
	DOWN
};

class MazeGenerator{
public:
	MazeGenerator();
	~MazeGenerator();

	void setup();
	void update();
	void draw();

private:
	static const int X_MAX = 10, Y_MAX = 10;
	int mWalls[X_MAX][Y_MAX], mSolution[X_MAX][Y_MAX];
};