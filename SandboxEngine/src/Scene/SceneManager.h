#pragma once

#include "Scene.h"
#include <stack>
#include <memory>

class SceneManager
{
public:
	void ClearData();

	void PushScene(Scene* scene);
	void PopScene();
	void ChangeScene(Scene* scene);

	Scene* GetCurrentScene();

private:
	std::stack<Scene*> m_Scenes;
};