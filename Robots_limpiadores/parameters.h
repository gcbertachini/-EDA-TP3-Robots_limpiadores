#pragma once
#include "general.h"


class parameters_t{
public:

	parameters_t() {
		options[0] = { "height" };
		options[1] = { "width" };
		options[2] = { "robots" };
		options[3] = { "mode" };
		width = 0;
		height = 0;
		robots = 0;
		mode = mode0;
	}
	const char * options[OPTION_QTY];
	int width;
	int height;
	int robots;
	modetype mode;
};