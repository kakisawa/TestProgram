#pragma once
#include "DxLib.h"

class Input;
class Check
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Check(Input& input);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Check(){}

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 終了
	/// </summary>
	void End();

	/// <summary>
	/// 移動
	/// </summary>
	void Move();

	/// <summary>
	/// 扇形の描画
	/// </summary>
	/// <param name="center">扇形の中心</param>
	/// <param name="dir">向きベクトル</param>
	/// <param name="angle">扇形の広がる角度(ラジアン)</param>
	/// <param name="radius">扇形の長さ(半径)</param>
	/// <param name="color">描画色</param>
	void DrawFan(const VECTOR& center, const VECTOR& dir, float angle, float radius, unsigned int color);

	/// <summary>
	/// 当たり判定
	/// </summary>
	void Collision();

private:
	VECTOR m_pos;	// 座標
	VECTOR m_move;	// 移動量
	VECTOR m_dir;	// 向いてる方向

	VECTOR m_enemyPos;	// 敵の座標

	Input& m_input;
};

