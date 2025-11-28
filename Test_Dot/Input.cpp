#include "Input.h"
#include "Dxlib.h"

Input::Input():
	m_lastInput(0),
	m_nowInput(0)
{
}

void Input::Update()
{
	m_lastInput = m_nowInput;
	m_nowInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}

bool Input::GetIsPress(const int key)
{
	return (m_nowInput & key);
}

bool Input::GetIsTrigger(const int key)
{
	bool isNow = m_nowInput & key;
	bool isLast = m_lastInput & key;

	return isNow && !isLast;
}

bool Input::GetIsRelease(const int key)
{
	bool isNow = m_nowInput & key;
	bool isLast = m_lastInput & key;

	return !isNow && isLast;
}
