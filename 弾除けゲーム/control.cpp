#include "control.h"

CONTROL::CONTROL(){
	shot = new SHOT;
	// backhandle = LoadGraph("��.avi");
}

CONTROL::~CONTROL(){
	delete shot;
}

void CONTROL::All(){
/*============================================
	  ������
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
	  �w�i�ݒ�
  =================================================*/

	PlayMovieToGraph(backhandle);//������Đ���Ԃɂ���
	if(TellMovieToGraph(backhandle)>22800)//���悪????�~���b�ɂȂ�����5�~���b�̂Ƃ���ɖ߂��ē�����Đ���Ԃɂ���
	{
		SeekMovieToGraph(backhandle,5);
		PlayMovieToGraph(backhandle);
	}
	DrawExtendGraph(0,0,Ww,Wh,backhandle,FALSE);//�w�i�̃O���t�B�b�N�n���h����`�悷��
	//DrawFormatString(0,50,GetColor(255,255,0),"%d",TellMovieToGraph(backhandle));//����̍Đ��ʒu��`�悷��

/*===============================================
       BGM�ݒ�
================================================*/
	
	shot->All();

/*===========================================
	  ���Z�b�g
  =============================================*/
	if(key[KEY_INPUT_R]==1)
	{
		delete shot;
		shot = new SHOT;
	}
	g_count++;
	
}