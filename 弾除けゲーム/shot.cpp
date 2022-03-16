#include "shot.h"

SHOT::SHOT(){
	for(int i=0;i<SHOT_NUM;i++){
		enemy[i].x=(float)GetRand(Ww/25)*25;
		enemy[i].y=-50;
		enemy[i].speed=4+GetRand(1);
		enemy[i].roll=0;
		enemy[i].xmove=1.0f;
		enemy[i].ymove=1.0f;
		enemy[i].shotflag=false;
		enemy[i].reflectflag=false;
	}
	deadflag = false;
	jikihandle=LoadGraph("�f��/jiki.png");
	graphhandle=LoadGraph("�f��/�A.png");
	gameover=LoadGraph("�f��/Gameover.png");
	soundhandle=LoadSoundMem("�f��/�����ՂR�N�@�q��BGM�@Wave.wav");
	damagehandle=LoadSoundMem("�f��/�s�`���[��.wav");
	damageflag=false;
	score=0;
	fonthandle=CreateFontToHandle(NULL,20,2,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;
	ball=0;
}

void SHOT::pMove(){
//�v���C���[�v�Z�t�F�C�Y===============================================================
	GetMousePoint(&px,&py);
	if(px<prad)
		px=prad;
	if(px>Ww-prad)
		px=Ww-prad;
	if(py< prad)
		py=prad;
	if(py>Wh-prad)
		py=Wh-prad;
}

void SHOT::eMove(){
	//�V���b�g�ړ��v�Z�t�F�C�Y==============================================================
	if(g_count%120==0&&ball<SHOT_NUM){//2�b���Ƃ�1�e���̊p�x���v�Z���đ��
		enemy[ball].angle=(float)atan2(py-enemy[ball].y,px-enemy[ball].x);
		enemy[ball].shotflag=true;
		ball+=1;
	}

	for(int i=0;i<SHOT_NUM;i++)
	{
		if(enemy[i].y>0)enemy[i].reflectflag=true;
		if(enemy[i].shotflag)
		{
			if((enemy[i].y>Wh||enemy[i].y<0)&&enemy[i].reflectflag)//����
				enemy[i].ymove*=-1;
			if(enemy[i].x>Ww||enemy[i].x<0)
				enemy[i].xmove*=-1;
			enemy[i].x+=enemy[i].speed*cos(enemy[i].angle)*enemy[i].xmove;//�ړ�����
			enemy[i].y+=enemy[i].speed*sin(enemy[i].angle)*enemy[i].ymove;
		}
	}
//�����蔻��
	for(int i=0;i<SHOT_NUM;i++){
		if(enemy[i].shotflag){
			if((px-enemy[i].x)*(px-enemy[i].x)+(py-enemy[i].y)*(py-enemy[i].y)<(prad+erad)*(prad+erad))
				deadflag=true;
		}
	}
}

void SHOT::Draw()
{
/*===�v���C���[�`��t�F�C�Y===*/

	if(!deadflag)DrawRotaGraph((int)px,(int)py,1,0,jikihandle,true,false);

/*===�V���b�g�`��t�F�C�Y===*/

	for(int i=0;i<SHOT_NUM;i++)
	{
		DrawRotaGraph((int)enemy[i].x,(int)enemy[i].y,0.03,enemy[i].roll,graphhandle,true,true);
		enemy[i].roll+=(float)0.04*enemy[i].ymove*enemy[i].xmove;
	}

/*===�X�R�A�`��t�F�C�Y===*/

	DrawFormatStringToHandle(0,5,GetColor(255,255,0),fonthandle,"SCORE�F%d",score);

}

void SHOT::Score(){
	score += 1+ball;
}

SHOT::~SHOT(){
	StopSoundMem(soundhandle);
	DeleteSoundMem(soundhandle) ;


}

void SHOT::All(){
	if(!deadflag)
	{
		pMove();
		Score();
	}else{
		DrawRotaGraph(Ww/2,Wh/2,1.3,0,gameover,true,false);
		if(CheckSoundMem(damagehandle)==0)
		{
			if(damageflag==false){
				PlaySoundMem(damagehandle,DX_PLAYTYPE_BACK,false);
				damageflag=true;
			}
		}
	}
	eMove();
	Draw();
	if(CheckSoundMem(soundhandle)==0)
	{
		PlaySoundMem(soundhandle,DX_PLAYTYPE_LOOP,true);
	}
}