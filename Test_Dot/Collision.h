#pragma once
#include "DxLib.h"

struct CollisionFan {	// 扇形当たり判定構造体
	VECTOR m_pos;	// 中心座標
	VECTOR m_dir;	// 向きベクトル
	float m_angle;	// 扇形の広がる角度(ラジアン)
	float m_radius;	// 扇形の長さ(半径)
};	

struct ColCapsule {
	VECTOR m_pos;		// 中心座標
	VECTOR m_vertexPos;	// 頂点座標
};

class Collision
{
};

