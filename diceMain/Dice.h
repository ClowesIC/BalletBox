#pragma once
#include <iostream>
#include <cstdlib>
//define class

class Dice {
private:
	int sideUp;
public:
	Dice();
	void toss();
	int getSideUp() const;

};