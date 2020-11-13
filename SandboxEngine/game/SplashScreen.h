#pragma once

#include "Scene/Scene.h"
#include "EntityComponents/BaseComponents.h"

#include <iostream>
#include <queue>

class SplashScreen : public Scene
{
public:
    SplashScreen(SDL_Renderer* renderer, SceneManager& sceneManager)
        : Scene(renderer, sceneManager)
    {
    }

    virtual void OnCreate() override
    {
        m_TextureManager->AddTexture("tile", "res/Sandbox.png");
        Entity& splash = m_EntityManager->CreateEntity("SplashScreen");
        splash.AddComponent<TransformComponent>(
            glm::vec2(1280/2, 720/2),
            glm::vec2(0, 0),
            glm::vec2(1.0f));
        splash.AddComponent<SpriteComponent>(m_TextureManager->GetTexture("tile"), glm::vec2(512,512));
        splash.SetActive(true);

        m_SplashScreen = &splash;
    }

    virtual void Update(float time) override
    {
        if (m_SplashScreen->IsActive())
        {
            if (m_TimeToLive <= 0.0f)
            {
                m_SplashScreen->SetActive(false);
            }
            else m_TimeToLive -= time;

            m_SplashScreen->GetComponent<TransformComponent>()->scale += 0.05f * time;
        }
        else
        {
            m_SceneManager->PopScene();
        }
    }

    virtual void PollEvents(SDL_Event& event) override
    {

    }

    virtual void OnDestroy() override
    {
    }

private:
    Entity* m_SplashScreen;
    float m_TimeToLive = 5.0f;
};
