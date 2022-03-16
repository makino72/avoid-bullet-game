#include "define.h"

struct ENEMY{
	float x,y;//座標
	float angle;//角度
	int speed;//速さ
	float roll;//色
	float xmove;//x移動係数
	float ymove;//y移動係数
	bool shotflag;//ショットフラグ
	bool reflectflag;//反射フラグ
};

class SHOT{
private:
	int px,py;//プレイヤー座標
	bool deadflag;//プレイヤー死亡フラグ
	int jikihandle;
	int score;//スコア
	int fonthandle;
	int ball;//ボールの数
	int graphhandle;
	int gameover;
	int soundhandle;//BGM
	int damagehandle;
	bool damageflag;
	ENEMY enemy[SHOT_NUM];//ショット構造体

	void pMove();//プレイヤー計算フェイズ
	void eMove();//エネミー計算フェイズ
	void Draw();//描画フェイズ
	void Score();//スコアフェイズ
public:
	SHOT();//コンストラクタ
	~SHOT();//デストラクタ
	void All();
};