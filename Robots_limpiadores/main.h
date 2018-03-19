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

typedef class {
	double x;
	double y;
} position;

typedef class {
private:
	double direction;
public:
	void create();
	void update(unsigned int maxFils, unsigned maxCols);
	position getPos();

} robotData;

	position p;
typedef class {
private:

	unsigned int filsize;
	unsigned int colsize;
	bool * tiles;

public:
	bool create(unsigned int fil, unsigned int col);
	void destroy(void);
	bool clean(position p);
	bool isDirty(double x, double y);
	bool floorStillDirty();
	unsigned int maxFil();
	unsigned int maxCol();
} floor_t;

typedef class {

private:
	robotData * robots;
	unsigned int ticks;
	floor_t f;
	modetype mode;

public:
	bool create(unsigned int robotCount, unsigned int fils, unsigned int cols, modetype m);
	unsigned int run();
	void destroy();

} simulation;