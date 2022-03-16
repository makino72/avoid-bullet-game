#include "player.h"

PLAYER::PLAYER(){
	Cr=GetColor(255,255,0);
	deadflag = false;
}

void PLAYER::Move(){
	GetMousePoint(&x,&y);
//à⁄ìÆêßå‰=======================================
	if(x<prad)
		x=prad;
	if(x>Ww-prad)
		x=Ww-prad;
	if(y< prad)
		y= prad;
	if(y>Wh-prad)
		y=Wh-prad;
}

void PLAYER::Draw()
{
	DrawCircle((int)x,(int)y, prad, Cr,true);
}

PLAYER::~PLAYER()
{

}

 void PLAYER::All()
{
	if(deadflag)
	{
		Move();
		Draw();
	}
}