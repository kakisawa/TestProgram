#pragma once
#include <map>

class Input
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Input();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 入力されているかを取得
	/// </summary>
	/// <param name="key">入力</param>
	/// <returns></returns>
	bool GetIsPress(const int pad);

	/// <summary>
	/// 入力された瞬間を取得
	/// </summary>
	/// <param name="key">入力</param>
	/// <returns></returns>
	bool GetIsTrigger(const int pad);

	/// <summary>
	/// 入力がなくなった瞬間を取得
	/// </summary>
	/// <param name="key">入力</param>
	/// <returns></returns>
	bool GetIsRelease(const int pad);

private:
	int m_lastInput;	// 前のフレームのキー押し下げ状態
	int m_nowInput;	// 現在のフレームのキー押し下げ状態
};