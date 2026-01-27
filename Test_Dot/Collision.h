#pragma once
#include "DxLib.h"

class Collision
{
public:

	struct ColFan {	// 扇形当たり判定構造体
		VECTOR m_pos;	// 中心座標
		VECTOR m_dir;	// 向きベクトル
		float m_angle;	// 扇形の広がる角度(ラジアン)
		float m_radius;	// 扇形の長さ(半径)
	};

	struct ColCapsule {
		VECTOR m_pos = VGet(0.0f, 0.0f, 0.0f);		// 中心座標
		VECTOR m_vertexPos = VGet(0.0f, 0.0f, 0.0f);// 頂点座標
		float m_radius = 0.0f;						// 半径
	};

	struct PlayerCol {
		ColCapsule m_bodyCol;
	}m_playerCol;

	struct EnemyCol {
		ColCapsule m_bodyCol;
	}m_enemyCol;


	/// <summary>
	/// コンストラクタ
	/// </summary>
	Collision();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Collision() {}

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();

	/// <summary>
	/// カプセル型当たり判定の更新
	/// </summary>
	/// <param name="col">当たり判定の種類</param>
	/// <param name="pos">座標</param>
	/// <param name="upPos">頂点座標</param>
	/// <param name="rad">半径</param>
	void CuosuleUpdate(ColCapsule& col, const VECTOR& pos, const VECTOR& upPos, const float rad);

	/// <summary>
	/// 扇形当たり判定の更新
	/// </summary>
	/// <param name="col">当たり判定の種類</param>
	/// <param name="pos">扇形の中心座標</param>
	/// <param name="dir">向きベクトル</param>
	/// <param name="angle">扇形の広がる角度(ラジアン)</param>
	/// <param name="rad">扇形の長さ(半径)</param>
	/// <param name="color">描画色</param>
	void FanUpdate(ColFan& col, const VECTOR& pos, const VECTOR& dir, const float angle, const float rad);

	/// <summary>
	/// カプセル型当たり判定の描画
	/// </summary>
	/// <param name="col">当たり判定の種類</param>
	/// <param name="color">描画色</param>
	/// <param name="isFill">色を塗りつぶすか</param>
	void CapsuleColDraw(const ColCapsule& col, unsigned int color, bool isFill);

	/// <summary>
	/// 扇形当たり判定の描画
	/// </summary>
	/// <param name="col">扇形の情報</param>
	/// <param name="color">描画色</param>
	void FanColDraw(const ColFan& col, unsigned int color);

	/// <summary>
	/// カプセル型の当たり判定
	/// </summary>
	/// <param name="col">当たり判定の属性</param>
	/// <param name="col2">もう一つの当たり判定の属性</param>
	/// <returns>当たっていたらtrueを返す</returns>
	bool IsCapsuleColision(const ColCapsule& col, const Collision::ColCapsule& col2);

	/// <summary>
	/// 扇形とカプセルの当たり判定
	/// </summary>
	/// <param name="fan">扇形の当たり判定</param>
	/// <param name="col">カプセル型の当たり判定</param>
	/// <returns>当たっていたらtrueを返す</returns>
	bool IsFanToCapsuleCollision(const ColFan& fan, const Collision::ColCapsule& col);

	/// <summary>
	/// 終了
	/// </summary>
	void End();

private:

};

