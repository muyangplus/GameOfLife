// Self
#include "userAction.h"

// ��ʼ��
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
		std::cout << "δ֪��ѡ����������ȷ�����ֱ��" << std::endl;
		userAction::init(map);
		break;
	}
	return;
}

// ��ʾ�˵�
void userAction::menu() {
	std::cout << "===============" << std::endl;
	std::cout << "��ѡ������ģʽ" << std::endl;
	std::cout << "[1]���ģʽ" << std::endl;
	std::cout << "[2]�Զ���ģʽ" << std::endl;
	std::cout << "===============" << std::endl;
	return;
}


