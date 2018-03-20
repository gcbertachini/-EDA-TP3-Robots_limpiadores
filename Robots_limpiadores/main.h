#pragma once

typedef enum { mode1 = 1, mode2 = 2 } modetype;
#define OPTION_QTY 4

typedef class{
public:
	const char * options[OPTION_QTY];
	int width;
	int height;
	int robots;
	int mode;
} parameters_t;

