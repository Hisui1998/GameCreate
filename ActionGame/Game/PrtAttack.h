#pragma once
#include "Actor.h"

//攻撃のもとになるクラス
class PrtAttack :
	public Actor
{
protected:
	Vec2 pos;		//位置情報
	Vec2 dir;		//向き情報
	float speed;	//速度
	Vec2 size;		//アクターの画像サイズ

	bool alive;		//生存フラグ

public:
	PrtAttack();
	virtual ~PrtAttack();

	virtual bool Init() = 0;
	virtual void UpDate(char* key) = 0;
	virtual void Draw() = 0;

	//Get関数
	Vec2 GetPos() { return pos; };
	Vec2 GetDir() { return dir; };
	Vec2 GetSize() { return size; };

	//この攻撃が生きているかどうか
	bool isAlive() { return alive; };

	//攻撃を消去する関数
	void CallDeath(void);
	//攻撃が削除されたものか判定する関数
	void DestroyProc(void);
};

