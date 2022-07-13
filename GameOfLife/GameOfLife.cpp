// Self
#include "GameOfLife.h"

// 初始化
void GameOfLife::init(bool map[ROWS][COLS]) {
	initgraph(COLS * SPACE, ROWS * SPACE);
	return;
}

/* 主程序 ?
 * times : 模拟次数（-1为无限次）
 * sleep : 模拟间隔（0为手动控制）
 * TODO:运行时编辑无效，（多线程尝试解决）
 */
void GameOfLife::run(int times, int sleep, bool map[ROWS][COLS]) {
	while (0 != times--) {		
		if (sleep) {
			Sleep(sleep);
		}
		else {
			while (!GameOfLife::editMap(map));
		}
		if (GameOfLife::editMap(map)) {
			break;
		}
		GameOfLife::lifeWeekChange(map);
		GameOfLife::uploadMap(map);
	}
	return;
}
// 随机模式
void GameOfLife::random_mode(bool map[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			map[i][j] = rand() % 2;
		}
	}
	return;
}

// 自定义模式
void GameOfLife::edit_mode(bool map[ROWS][COLS]) {
	GameOfLife::uploadMap(map);
	while (1) {
		if (editMap(map)) {
			break;
		}
	}
	return;
}

// 获取周围的细胞存活数量并返回
// update@2022.7.13
// 算法修正
int GameOfLife::getLives(int x, int y, bool map[ROWS][COLS]) {
	int num = 0;
	for (int i = max(x, 0); i < min(x + 3, ROWS); i++) {
		for (int j = max(y, 0); j < min(y + 3, COLS); j++) {
			if (map[i][j]) {
				num += map[i][j];
			}
		}
	}
	num -= map[x][y];
	return num;
}

// 生命周期变换
void GameOfLife::lifeWeekChange(bool map[ROWS][COLS]) {
	bool temp[ROWS][COLS] = { 0 };
	// 根据规则设定 temp
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) { 
			int num = GameOfLife::getLives(i, j, map);
			if (3 == num) {
				temp[i][j] = 1;
			}
			else if (2 == num) {
				temp[i][j] = map[i][j];
			}
			else {
				temp[i][j] = 0;
			}
		}
	}
	//uploadMap(temp);
	// 将 map 重设为 temp
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			map[i][j] = temp[i][j];
		}
	}
	return;
}

// 画矩形
void GameOfLife::drawRect(int x, int y, bool flag) {
	setlinecolor(RGB(133, 133, 133));
	if (flag) {
		setfillcolor(RGB(255, 255, 255));
	}
	else {
		setfillcolor(RGB(0, 0, 0));
	}
	fillrectangle(x * SPACE, y * SPACE, x * SPACE + SPACE, y * SPACE + SPACE);
	return;
}

// 刷新地图
void GameOfLife::uploadMap(bool map[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			GameOfLife::drawRect(j, i, map[i][j]);
		}
	}
	return;
}

// 编辑地图
// updata@2022.7.13
// 优化代码，运行速度显著提升
int GameOfLife::editMap(bool map[ROWS][COLS]) {
	MOUSEMSG msg = GetMouseMsg();
	if (msg.mkLButton) {
		map[msg.y / SPACE][msg.x / SPACE] = 1;
		drawRect(msg.x / SPACE, msg.y / SPACE, 1);
	}
	if (msg.mkRButton) {
		map[msg.y / SPACE][msg.x / SPACE] = 0;
		drawRect(msg.x / SPACE, msg.y / SPACE,0);
	}
	if (msg.mkMButton) {
		return 1;
	}
	return 0;
}


