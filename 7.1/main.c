#include"list_int.h"

extern Item* LoadList(const char *filename);

int main(void) {
	Item *L = LoadList("Data_00.txt");
}