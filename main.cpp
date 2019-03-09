#include <windows.h>
#include <iostream>
#include "doonce.h"
#include <vector>
#include "functions.cpp"

bool noS = false;
bool invS = false;
bool invSo = false;

const unsigned short MSB = 0x8000;



std::vector<doonce> keys;
std::vector<char> chars;

int main() {
	chars.push_back('X');
	chars.push_back('V');
	chars.push_back('L');
	chars.push_back('C');
	chars.push_back('W');
	chars.push_back('K');
	chars.push_back('H');
	chars.push_back('G');
	chars.push_back('F');
	chars.push_back('Q');
	chars.push_back('U');
	chars.push_back('I');
	chars.push_back('A');
	chars.push_back('E');
	chars.push_back('O');
	chars.push_back('S');
	chars.push_back('N');
	chars.push_back('R');
	chars.push_back('T');
	chars.push_back('D');
	chars.push_back('Y');
	chars.push_back('P');
	chars.push_back('Z');
	chars.push_back('B');
	chars.push_back('M');

	//Top
	keys.push_back(doonce("C5", Fn, FnS, FnL));
	keys.push_back(doonce("D5", Fn, FnS, FnL));
	keys.push_back(doonce("E5", Fn, FnS, FnL));
	keys.push_back(doonce("F5", Fn, FnS, FnL));
	keys.push_back(doonce("G5", Fn, FnS, FnL));
	keys.push_back(doonce("A5", Fn, FnS, FnL));
	keys.push_back(doonce("B5", Fn, FnS, FnL));
	keys.push_back(doonce("C6", Fn, FnS, FnL));
	keys.push_back(doonce("D6", Fn, FnS, FnL));
	keys.push_back(doonce("E6", Fn, FnS, FnL));

	//Middle
	keys.push_back(doonce("C3", Fn, FnS, FnL));
	keys.push_back(doonce("D3", Fn, FnS, FnL));
	keys.push_back(doonce("E3", Fn, FnS, FnL));
	keys.push_back(doonce("F3", Fn, FnS, FnL));
	keys.push_back(doonce("G3", Fn, FnS, FnL));
	keys.push_back(doonce("A3", Fn, FnS, FnL));
	keys.push_back(doonce("B3", Fn, FnS, FnL));
	keys.push_back(doonce("C4", Fn, FnS, FnL));
	keys.push_back(doonce("D4", Fn, FnS, FnL));
	keys.push_back(doonce("E4", Fn, FnS, FnL));
	keys.push_back(doonce("F4", Fn, FnS, FnL));

	//Bottommost
	keys.push_back(doonce("C2", Fn, FnS, FnL));
	keys.push_back(doonce("D2", Fn, FnS, FnL));
	keys.push_back(doonce("E2", Fn, FnS, FnL));
	keys.push_back(doonce("F2", Fn, FnS, FnL));

	
	while (true) {
		for(int i = 0; i < chars.size(); i++) {
			if (GetAsyncKeyState(chars[i]) & MSB) {
				keys[i].doF();
			}else {
				if (!noS) {
					keys[i].reset();
				}else{
					keys[i].done = false;
				}
				//std::cout << "up" << std::endl;
			}
		}
		
		if (GetAsyncKeyState(VK_SPACE) & MSB) {
			noS = !invS;
		}else {
			noS = invS;
		}
		if (GetAsyncKeyState(VK_RETURN) & MSB) {
			return 0;
		}
		if (GetAsyncKeyState(VK_MENU) & MSB) {
			if (!invSo) {
				invS = !invS;
				invSo = true;
			}
		}else{
			invSo = false;
		}
  }
	
	return 0;
}