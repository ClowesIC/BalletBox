#include <iostream>
#include <cstdlib>
#include "Dice.h"
using namespace std;

Dice::Dice() {
	srand(rand());
	sideUp = rand() % 6 + 1;
}
void Dice::toss() {
	sideUp = rand() % 6 + 1;
}
int Dice::getSideUp() const{
	return sideUp;
}