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
	jikihandle=LoadGraph("素材/jiki.png");
	graphhandle=LoadGraph("素材/泡.png");
	gameover=LoadGraph("素材/Gameover.png");
	soundhandle=LoadSoundMem("素材/文化祭３年　牧野BGM　Wave.wav");
	damagehandle=LoadSoundMem("素材/ピチューン.wav");
	damageflag=false;
	score=0;
	fonthandle=CreateFontToHandle(NULL,20,2,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;
	ball=0;
}

void SHOT::pMove(){
//プレイヤー計算フェイズ===============================================================
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
	//ショット移動計算フェイズ==============================================================
	if(g_count%120==0&&ball<SHOT_NUM){//2秒ごとに1弾分の角度を計算して代入
		enemy[ball].angle=(float)atan2(py-enemy[ball].y,px-enemy[ball].x);
		enemy[ball].shotflag=true;
		ball+=1;
	}

	for(int i=0;i<SHOT_NUM;i++)
	{
		if(enemy[i].y>0)enemy[i].reflectflag=true;
		if(enemy[i].shotflag)
		{
			if((enemy[i].y>Wh||enemy[i].y<0)&&enemy[i].reflectflag)//反射
				enemy[i].ymove*=-1;
			if(enemy[i].x>Ww||enemy[i].x<0)
				enemy[i].xmove*=-1;
			enemy[i].x+=enemy[i].speed*cos(enemy[i].angle)*enemy[i].xmove;//移動制御
			enemy[i].y+=enemy[i].speed*sin(enemy[i].angle)*enemy[i].ymove;
		}
	}
//当たり判定
	for(int i=0;i<SHOT_NUM;i++){
		if(enemy[i].shotflag){
			if((px-enemy[i].x)*(px-enemy[i].x)+(py-enemy[i].y)*(py-enemy[i].y)<(prad+erad)*(prad+erad))
				deadflag=true;
		}
	}
}

void SHOT::Draw()
{
/*===プレイヤー描画フェイズ===*/

	if(!deadflag)DrawRotaGraph((int)px,(int)py,1,0,jikihandle,true,false);

/*===ショット描画フェイズ===*/

	for(int i=0;i<SHOT_NUM;i++)
	{
		DrawRotaGraph((int)enemy[i].x,(int)enemy[i].y,0.03,enemy[i].roll,graphhandle,true,true);
		enemy[i].roll+=(float)0.04*enemy[i].ymove*enemy[i].xmove;
	}

/*===スコア描画フェイズ===*/

	DrawFormatStringToHandle(0,5,GetColor(255,255,0),fonthandle,"SCORE：%d",score);

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