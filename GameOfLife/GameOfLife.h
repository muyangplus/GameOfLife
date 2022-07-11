#pragma once

// C++
#include <iostream>
// easyX
#include <graphics.h>

#define SPACE 10
#define ROWS 50
#define COLS 50

class GameOfLife {
public:
	static void init(bool map[ROWS][COLS]);
	static void run(int times, int sleep, bool map[ROWS][COLS]);
	static void random_mode(bool map[ROWS][COLS]);
	static void edit_mode(bool map[ROWS][COLS]);
private:
	static int getLives(int x, int y, bool map[ROWS][COLS]);
	static void lifeWeekChange(bool map[ROWS][COLS]);
	static void drawRect(int x, int y, bool flag);
	static void uploadMap(bool map[ROWS][COLS]);
	static int editMap(bool map[ROWS][COLS]);
};


