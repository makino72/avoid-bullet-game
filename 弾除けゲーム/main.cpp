#include "control.h"

char key[256];
int g_count=0;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(TRUE);
	SetGraphMode(Ww,Wh,16);
	SetWindowText("�薼�̂Ȃ��f�W��");
	SetDrawScreen(DX_SCREEN_BACK);
	// �c�w���C�u��������������
	if( DxLib_Init() == -1 )
	{
		return -1 ;	// �G���[���N�����璼���ɏI��
	}
	CONTROL *control = new CONTROL;
//���s��===========================================
	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && GetHitKeyStateAll(key)==0)
	{
		control->All();
	}
//==================================================
	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;
	// �\�t�g�̏I��
	return 0 ; 

}