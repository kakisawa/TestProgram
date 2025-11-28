#include "MapModel.h"
#include <cassert>

namespace {
	const VECTOR kInitVec = VGet(0.0f, 0.0f, 0.0f);

	const VECTOR kModelPos = VGet(1280/2, 720/2, 0.0f);
	const VECTOR kModelScale = VGet(0.1f, 0.1f, 0.1f);
	const char* kModelPath = "Data/Model/castle.mv1";
}

MapModel::MapModel():
	m_model(-1),
	m_pos(kInitVec),
	m_scale(kInitVec)
{
}

MapModel::~MapModel()
{
}

void MapModel::Init()
{
	m_model= MV1LoadModel(kModelPath);
	assert(m_model != -1);
}

void MapModel::Update()
{
	MV1SetPosition(m_model, kModelPos);
	MV1SetScale(m_model, kModelScale);
}

void MapModel::Draw()
{
	MV1DrawModel(m_model);
}

void MapModel::End()
{
	MV1DeleteModel(m_model);
}
