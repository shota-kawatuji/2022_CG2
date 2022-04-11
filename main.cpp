#include <Windows.h>

// ウィンドウプロシージャ
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	// メッセージに応じてゲーム固有の処理を行う
	switch (msg) {
	// ウィンドウが破棄された
	case WM_DESTROY:
		// OSに対して、アプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// コンソールへの文字出力
	OutputDebugStringA("Hello,DirectX!!\n");

	// 設定
	// ウィンドウサイズ
	const int window_width = 1280;
	const int windou_heigth = 720;

	// ウィンドウクラスの設定
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;
	w.lpszClassName = L"DirectXGame";
	w.hInstance = GetModuleHandle(nullptr);
	w.hCursor = LoadCursor(NULL, IDC_ARROW);

	// ウィンドウクラスをOSに登録する
	RegisterClassEx(&w);
	// ウィンドウサイズ{ X座標 Y座標 横幅 縦幅 }
	RECT wrc = { 0,0,window_width,windou_heigth };
	// 自動でサイズを補正する
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);


	// ウィンドウオブジェクトの生成
	HWND hwnd = CreateWindow(w.lpszClassName,//クラス名
		L"DirectXGame",						 // タイトルバー
		WS_OVERLAPPEDWINDOW,				 // 標準的なウィンドウスタイル
		CW_USEDEFAULT,						 // 表示x座標
		CW_USEDEFAULT,						 // 表示Y座標
		wrc.right - wrc.left,				 // ウィンドウ横幅
		wrc.bottom - wrc.top,				 // ウィンドウ縦幅
		nullptr,							 // 親ウィンドウハンドル
		nullptr,							 // メニューハンドル
		w.hInstance,						 // 呼び出しアプリケーションハンドル
		nullptr);							 // オプション

	// ウィンドウを表示状態にする
	ShowWindow(hwnd, SW_SHOW);

	MSG msg{}; // メッセージ

	// DirectX初期化処理 ここから

	// DirectX初期化処理 ここまで


	// ゲームループ
	while (true) {
		// ウィンドウクラスを登録解除
		UnregisterClass(w.lpszClassName, w.hInstance);

		// メッセージがある？
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}

		// Xボタンで終了メッセージが来たらゲームループを抜ける
		if (msg.message == WM_QUIT) {
			break;
		}
		// DirectX毎フレーム処理 ここから

		// DirectX毎フレーム処理 ここまで


	}

	return 0;
}