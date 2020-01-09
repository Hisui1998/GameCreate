#include "TestEnemy.h"
#include "ResourceMng.h"
#include "Application.h"

constexpr float speed = 3.0f;
int TestEnemy::StateIdle(void)
{
	return 0;
}

int TestEnemy::StateMove(void)
{
	Vec2 vec;//�G�l�~�[�x�N�g��
	auto v = _player->GetPos();

	vec.x = v.x - pos.x;	//x���x�N�g��
	vec.y = v.y - pos.y;	//y���x�N�g��
	
	float l = max(sqrt(vec.x*vec.x + vec.y*vec.y),0);
	vec.x = vec.x / l;
	vec.y = vec.y / l;

	pos.x += vec.x;
	pos.y += vec.y;

	return 0;
}

int TestEnemy::StateJump(void)
{
	return 0;
}

int TestEnemy::StateAttack(void)
{
	return 0;
}

int TestEnemy::StateShot(void)
{
	return 0;
}

//�R���X�g���N�^
TestEnemy::TestEnemy(std::shared_ptr<Actor> player)
{
	_player = player;
	Init();
}

//�f�X�g���N�^
TestEnemy::~TestEnemy()
{
}

//������
bool TestEnemy::Init()
{
	_animFlame.resize((int)ENEMY_STATE::MAX);

	_images[(int)ENEMY_STATE::MOVE] = ResourceMng::Get()->GetID("../Resource/Enemy/enemy1.png", { 64, 64 }, { 4, 1 });

	//_animFlame[(int)ANIM_STATE::IDLE] = 12;
	_animFlame[(int)ENEMY_STATE::MOVE] = 4;
	//_animFlame[(int)ANIM_STATE::JUMP] = 13;
	//_animFlame[(int)ANIM_STATE::CROUCH] = 1;
	//_animFlame[(int)ANIM_STATE::FALL] = 3;
	//_animFlame[(int)ANIM_STATE::SHORT_RANGE_ATK] = 10;
	_animCnt = 0;

	

	//�G�l�~�[���W
	pos = { 100, (float)(Application::Instance()->GetWindowSize().height - 100) };

	//�֐��|�C���^������
	_state = ENEMY_STATE::MOVE;
	stateTbl[static_cast<int>(ENEMY_STATE::IDLE)] = &TestEnemy::StateIdle;
	stateTbl[static_cast<int>(ENEMY_STATE::MOVE)] = &TestEnemy::StateMove;
	//stateTbl[static_cast<int>(ENEMY_STATE::JUMP)] = &TestEnemy::StateJump;
	stateTbl[static_cast<int>(ENEMY_STATE::SHORT_RANGE_ATK)] = &TestEnemy::StateAttack;
	stateTbl[static_cast<int>(ENEMY_STATE::LONG_RANGE_ATK)] = &TestEnemy::StateShot;

	//�v���C���[
	//_player = std::make_shared<Player>();

	return false;
}

//�X�V
void TestEnemy::UpDate(char* key)
{
	(this->*stateTbl[static_cast<int>(_state)])();
}

//�`��
void TestEnemy::Draw()
{
	_animCnt++;
	DrawRotaGraph(pos.x, pos.y, 1, 0, _images[(int)_state][(_animCnt / 3) % _animFlame[(int)_state]], true, false);
}

//�����蔻��
void TestEnemy::CheckHitBox(const RECT& rect, Vec2 pos)
{
}
