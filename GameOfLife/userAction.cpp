// Self
#include "userAction.h"

// 初始化
void userAction::init(bool map[ROWS][COLS]) {
	userAction::menu();
	char cho = 0;
	std::cin >> cho;
	switch (cho)
	{
	case '1':
		GameOfLife::init(map);
		GameOfLife::random_mode(map);
		break;
	case '2':
		GameOfLife::init(map);
		GameOfLife::edit_mode(map);
		break;
	default:
		std::cout << "未知的选择，请输入正确的数字编号" << std::endl;
		userAction::init(map);
		break;
	}
	return;
}

// 显示菜单
void userAction::menu() {
	std::cout << "===============" << std::endl;
	std::cout << "请选择运行模式" << std::endl;
	std::cout << "[1]随机模式" << std::endl;
	std::cout << "[2]自定义模式" << std::endl;
	std::cout << "===============" << std::endl;
	return;
}


