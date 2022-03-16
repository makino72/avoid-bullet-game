#include"define.h"

class PLAYER{
private:
	int x,y;
	int Cr;
	bool deadflag;

	void Move();
	void Draw();

public:
	PLAYER();
	~PLAYER();
	void All();
};