#include "Check.h"
#include "Input.h"
#include "collection.h"

namespace {
	constexpr float kSpeed = 1.0f;
	const VECTOR kInitVec = VGet(0.0f, 0.0f, 0.0f);
}

Check::Check(Input& input) :
	m_input(input),
	m_pos(kInitVec),
	m_move(kInitVec),
	m_dir(kInitVec),
	m_enemyPos(kInitVec)
{
	
}

void Check::Init()
{
	int x = 0, y = 0;
	GetWindowSize(&x, &y);
	m_pos = VGet(x / 2, y / 2, 0.0f);
	m_enemyPos = VGet(x / 2 + 100.0f, y / 2, 0.0f);
}

void Check::Update()
{
	m_input.Update();
	Move();
}

void Check::Draw()
{
	DrawFan(m_pos, m_dir, DX_PI / 3.0f, 50.0f, 0xff00ff);
	DrawCircle(m_pos.x, m_pos.y, 10.0f, 0xffffff, true);
	DrawCircle(m_enemyPos.x, m_enemyPos.y, 10.0f, 0xffff00, true);
}

void Check::End()
{
}

void Check::Move()
{
	m_move = kInitVec;

	if (m_input.GetIsPress(PAD_INPUT_RIGHT)){
		m_move.x += kSpeed;
	}

	if (m_input.GetIsPress(PAD_INPUT_LEFT)) {
		m_move.x -= kSpeed;
	}

	if (m_input.GetIsPress(PAD_INPUT_UP)) {
		m_move.y -= kSpeed;
	}

	if (m_input.GetIsPress(PAD_INPUT_DOWN)) {
		m_move.y += kSpeed;
	}

	if (m_move.x != 0.0f || m_move.y != 0.0f) {
		m_move = VNorm(m_move);
		m_dir = m_move;
		m_pos = VAdd(m_pos, m_move);
	}
	
}

void Check::DrawFan(const VECTOR& center, const VECTOR& dir, float angle, float radius, unsigned int color)
{
	// 扇形を何分割するか(多いと処理が増える)
	const int div = 32;

	// 扇形の左右の端は「中心角 ± 半分の角度」になるため、
	// あらかじめ半分の角度を求めておく。
	float half = angle * 0.5f;

	// プレイヤーの向きベクトル（dir）を角度に変換する。
	// atan2(y, x) はベクトルの向きを 0〜2π の角度として求められる。
	// これが扇形の "中央の方向".
	float baseRot = atan2f(dir.y, dir.x);

	// 扇形を 0〜DIV-1 のループで描画していく
	for (int i = 0; i < div; i++)
	{
		// この三角形の左右の角度（線分の向き）を計算。
		// 扇形の左端 → 右端に向かって少しずつ角度をずらす。
		float a1 = baseRot - half + (angle / div) * i;
		float a2 = baseRot - half + (angle / div) * (i + 1);

		// 三角形の 2 点（扇形外周の点）を計算。
		// cos・sin を使って「角度 → x,y 座標」に変換。
		float x1 = center.x + cosf(a1) * radius;
		float y1 = center.y + sinf(a1) * radius;

		float x2 = center.x + cosf(a2) * radius;
		float y2 = center.y + sinf(a2) * radius;

		// 1つの三角形を描画する。
		// これを繰り返すことで扇形に見える。
		DrawTriangle(
			center.x, center.y,   // 三角形の頂点（プレイヤー中心）
			x1, y1,               // 左端の外周点
			x2, y2,               // 右端の外周点
			color,                // 色
			true                  // 塗りつぶす
		);
	}
}

void Check::Collision()
{
}
