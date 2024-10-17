#ifndef SCORE_H
#define SCORE_H

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	~Dept();
	int getSize() { return size; }
	void read();
	bool isOver60(int index);
};
#endif
