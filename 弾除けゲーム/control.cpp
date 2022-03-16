#include "control.h"

CONTROL::CONTROL(){
	shot = new SHOT;
	// backhandle = LoadGraph("雪.avi");
}

CONTROL::~CONTROL(){
	delete shot;
}

void CONTROL::All(){
/*============================================
	  線引き
  ============================================
	for(int s=0;s<=1000;s+=100)
	{
		DrawLine(0,s,1000,s,GetColor(255,0,0));
		DrawFormatString(0,s,GetColor(255,0,0),"%d",s);
	}
	for(int t=0;t<=1000;t+=100)
	{
		DrawLine(t,0,t,1000,GetColor(255,0,0));
		DrawFormatString(t,0,GetColor(255,0,0),"%d",t);
	}

/*=================================================
	  背景設定
  =================================================*/

	PlayMovieToGraph(backhandle);//動画を再生状態にする
	if(TellMovieToGraph(backhandle)>22800)//動画が????ミリ秒になったら5ミリ秒のところに戻して動画を再生状態にする
	{
		SeekMovieToGraph(backhandle,5);
		PlayMovieToGraph(backhandle);
	}
	DrawExtendGraph(0,0,Ww,Wh,backhandle,FALSE);//背景のグラフィックハンドルを描画する
	//DrawFormatString(0,50,GetColor(255,255,0),"%d",TellMovieToGraph(backhandle));//動画の再生位置を描画する

/*===============================================
       BGM設定
================================================*/
	
	shot->All();

/*===========================================
	  リセット
  =============================================*/
	if(key[KEY_INPUT_R]==1)
	{
		delete shot;
		shot = new SHOT;
	}
	g_count++;
	
}