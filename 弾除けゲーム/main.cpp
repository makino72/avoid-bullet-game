#include "control.h"

char key[256];
int g_count=0;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(TRUE);
	SetGraphMode(Ww,Wh,16);
	SetWindowText("題名のないデジ研");
	SetDrawScreen(DX_SCREEN_BACK);
	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 )
	{
		return -1 ;	// エラーが起きたら直ちに終了
	}
	CONTROL *control = new CONTROL;
//実行部===========================================
	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && GetHitKeyStateAll(key)==0)
	{
		control->All();
	}
//==================================================
	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;
	// ソフトの終了
	return 0 ; 

}