#include "DxLib.h"
#include "MapModel.h"
#include <memory>
#include <cassert>

int Width = 1280;
int Height = 720;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	
	// Windowモード設定(フルスクリーン=false)
	ChangeWindowMode(true);
	// ウインドウ名設定
	SetMainWindowText("BloodyCastle");
	// 画面サイズの設定
	SetGraphMode(static_cast<int>(Width), static_cast<int>(Height), 32);

	SetWindowSizeExtendRate(1.0);
	SetWindowSizeChangeEnableFlag(true, true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// Zバッファの設定
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(true);

	SetDrawScreen(DX_SCREEN_BACK);


	std::shared_ptr<MapModel> m_pMapModel = std::make_shared<MapModel>();
	m_pMapModel->Init();


	// ゲームループ
	while (ProcessMessage() != -1)
	{
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();



		// ゲームの処理
		m_pMapModel->Update();
		m_pMapModel->Draw();
		DrawSphere3D(VGet(0.0f, 0.0f, 0.0f), 30.0f, 64, 0xffff00, 0xffff00, true);


		// 画面が切り替わるのを待つ
		ScreenFlip();

		// escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}
	}

	m_pMapModel->End();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}