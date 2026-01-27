#include "Collision.h"
#include <math.h>

namespace {
	constexpr float kInitFloat = 0.0f;
	const VECTOR kInitVec = VGet(0.0f, 0.0f, 0.0f);
}

Collision::Collision()
{
	// 敵当たり判定初期化
	m_enemyCol.m_bodyCol.m_pos = kInitVec;
	m_enemyCol.m_bodyCol.m_vertexPos = kInitVec;
	m_enemyCol.m_bodyCol.m_radius = kInitFloat;

	// プレイヤー初期化
	m_playerCol.m_bodyCol.m_pos = kInitVec;
	m_playerCol.m_bodyCol.m_vertexPos = kInitVec;
	m_playerCol.m_bodyCol.m_radius = kInitFloat;
}

void Collision::Init()
{
}

void Collision::CuosuleUpdate(ColCapsule& col, const VECTOR& pos, const VECTOR& upPos, const float rad)
{
	col.m_pos = pos;
	col.m_vertexPos = upPos;
	col.m_radius = rad;
}

void Collision::FanUpdate(ColFan& col, const VECTOR& pos, const VECTOR& dir, const float angle, const float rad)
{
	col.m_pos = pos;
	col.m_dir = dir;
	col.m_angle = angle;
	col.m_radius = rad;
}

void Collision::CapsuleColDraw(const ColCapsule& col, unsigned int color, bool isFill)
{
	// カプセル型の当たり判定描画
	DrawSphere3D(col.m_pos, col.m_radius, 32, color, color, isFill);
}

void Collision::FanColDraw(const ColFan& col, unsigned int color)
{
	// 扇形を何分割するか(多いと処理が増える)
	const int div = 32;

	// 扇形の左右の端は「中心角 ± 半分の角度」になるため、
	// あらかじめ半分の角度を求めておく。
	float half = col.m_angle * 0.5f;

	// プレイヤーの向きベクトル（dir）を角度に変換する。
	// atan2(y, x) はベクトルの向きを 0〜2π の角度として求められる。
	// これが扇形の "中央の方向".
	float baseRot = atan2f(col.m_dir.y, col.m_dir.x);

	// 扇形を 0〜DIV-1 のループで描画していく
	for (int i = 0; i < div; i++)
	{
		// この三角形の左右の角度（線分の向き）を計算。
		// 扇形の左端 → 右端に向かって少しずつ角度をずらす。
		float a1 = baseRot - half + (col.m_angle / div) * i;
		float a2 = baseRot - half + (col.m_angle / div) * (i + 1);

		// 三角形の 2 点（扇形外周の点）を計算。
		// cos・sin を使って「角度 → x,y 座標」に変換。
		float x1 = col.m_pos.x + cosf(a1) * col.m_radius;
		float y1 = col.m_pos.y + sinf(a1) * col.m_radius;

		float x2 = col.m_pos.x + cosf(a2) * col.m_radius;
		float y2 = col.m_pos.y + sinf(a2) * col.m_radius;

		// 1つの三角形を描画する。
		// これを繰り返すことで扇形に見える。
		DrawTriangle(
			col.m_pos.x, col.m_pos.y,   // 三角形の頂点（プレイヤー中心）
			x1, y1,               // 左端の外周点
			x2, y2,               // 右端の外周点
			color,                // 色
			true                  // 塗りつぶす
		);
	}
}

bool Collision::IsCapsuleColision(const ColCapsule& col, const Collision::ColCapsule& col2)
{
	return HitCheck_Capsule_Capsule(col.m_pos, col.m_vertexPos,col.m_radius,
		col2.m_pos, col2.m_vertexPos, col2.m_radius);
}

bool Collision::IsFanToCapsuleCollision(const ColFan& fan, const Collision::ColCapsule& col)
{
	//if(fan.m_pos)

	return false;
}

void Collision::End()
{
}
