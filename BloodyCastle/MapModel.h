#pragma once
#include "DxLib.h"


class MapModel
{
public:
	MapModel();
	virtual ~MapModel();

	void Init();
	void Update();
	void Draw();
	void End();

private:
	int m_model;

	VECTOR m_pos;
	VECTOR m_scale;
};

