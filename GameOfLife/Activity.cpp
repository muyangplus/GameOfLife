/* Game Of Life
 * date@2022.7.11
 * auther@–Ï’’Ω‹
 */

 // C++
#include <iostream>
// SELF
#include "userAction.h"
#include "GameOfLife.h"

int main() {
	bool map[ROWS][COLS] = { 0 };
	
	userAction::init(map);
	//GameOfLife::random_mode(map);
	//GameOfLife::edit_mode(map);

	GameOfLife::run(-1, 0, map);

	closegraph();
	return 0;
}


