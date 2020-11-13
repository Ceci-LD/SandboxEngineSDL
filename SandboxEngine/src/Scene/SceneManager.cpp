#include "SceneManager.h"

void SceneManager::ClearData()
{
	for (size_t i = 0; i < m_Scenes.size(); i++)
	{
		PopScene();
	}
}

void SceneManager::PushScene(Scene* scene)
{
	m_Scenes.push(scene);
	scene->OnCreate();
}

void SceneManager::PopScene()
{
	Scene* scene = m_Scenes.top();
	m_Scenes.pop();
	scene->OnDestroy();
}

void SceneManager::ChangeScene(Scene* scene)
{
	PopScene();
	PushScene(scene);
}

Scene* SceneManager::GetCurrentScene()
{
	return m_Scenes.top();
}
