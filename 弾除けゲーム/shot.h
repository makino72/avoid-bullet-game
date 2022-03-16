#include "define.h"

struct ENEMY{
	float x,y;//���W
	float angle;//�p�x
	int speed;//����
	float roll;//�F
	float xmove;//x�ړ��W��
	float ymove;//y�ړ��W��
	bool shotflag;//�V���b�g�t���O
	bool reflectflag;//���˃t���O
};

class SHOT{
private:
	int px,py;//�v���C���[���W
	bool deadflag;//�v���C���[���S�t���O
	int jikihandle;
	int score;//�X�R�A
	int fonthandle;
	int ball;//�{�[���̐�
	int graphhandle;
	int gameover;
	int soundhandle;//BGM
	int damagehandle;
	bool damageflag;
	ENEMY enemy[SHOT_NUM];//�V���b�g�\����

	void pMove();//�v���C���[�v�Z�t�F�C�Y
	void eMove();//�G�l�~�[�v�Z�t�F�C�Y
	void Draw();//�`��t�F�C�Y
	void Score();//�X�R�A�t�F�C�Y
public:
	SHOT();//�R���X�g���N�^
	~SHOT();//�f�X�g���N�^
	void All();
};