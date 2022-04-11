#include <Windows.h>

// �E�B���h�E�v���V�[�W��
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	// ���b�Z�[�W�ɉ����ăQ�[���ŗL�̏������s��
	switch (msg) {
	// �E�B���h�E���j�����ꂽ
	case WM_DESTROY:
		// OS�ɑ΂��āA�A�v���̏I����`����
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

// Windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// �R���\�[���ւ̕����o��
	OutputDebugStringA("Hello,DirectX!!\n");

	// �ݒ�
	// �E�B���h�E�T�C�Y
	const int window_width = 1280;
	const int windou_heigth = 720;

	// �E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;
	w.lpszClassName = L"DirectXGame";
	w.hInstance = GetModuleHandle(nullptr);
	w.hCursor = LoadCursor(NULL, IDC_ARROW);

	// �E�B���h�E�N���X��OS�ɓo�^����
	RegisterClassEx(&w);
	// �E�B���h�E�T�C�Y{ X���W Y���W ���� �c�� }
	RECT wrc = { 0,0,window_width,windou_heigth };
	// �����ŃT�C�Y��␳����
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);


	// �E�B���h�E�I�u�W�F�N�g�̐���
	HWND hwnd = CreateWindow(w.lpszClassName,//�N���X��
		L"DirectXGame",						 // �^�C�g���o�[
		WS_OVERLAPPEDWINDOW,				 // �W���I�ȃE�B���h�E�X�^�C��
		CW_USEDEFAULT,						 // �\��x���W
		CW_USEDEFAULT,						 // �\��Y���W
		wrc.right - wrc.left,				 // �E�B���h�E����
		wrc.bottom - wrc.top,				 // �E�B���h�E�c��
		nullptr,							 // �e�E�B���h�E�n���h��
		nullptr,							 // ���j���[�n���h��
		w.hInstance,						 // �Ăяo���A�v���P�[�V�����n���h��
		nullptr);							 // �I�v�V����

	// �E�B���h�E��\����Ԃɂ���
	ShowWindow(hwnd, SW_SHOW);

	MSG msg{}; // ���b�Z�[�W

	// DirectX���������� ��������

	// DirectX���������� �����܂�


	// �Q�[�����[�v
	while (true) {
		// �E�B���h�E�N���X��o�^����
		UnregisterClass(w.lpszClassName, w.hInstance);

		// ���b�Z�[�W������H
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}

		// X�{�^���ŏI�����b�Z�[�W��������Q�[�����[�v�𔲂���
		if (msg.message == WM_QUIT) {
			break;
		}
		// DirectX���t���[������ ��������

		// DirectX���t���[������ �����܂�


	}

	return 0;
}