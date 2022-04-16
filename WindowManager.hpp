#pragma once
#include "Pch.hpp"
#include "Animation.hpp"
#include "Helpers.hpp"
#include "BaseScreen.hpp"


enum class _Impl_Direction {
	X, Y
};

class WindowManager {
private:
	using ScreenLoader = std::function<BaseScreen*()>;
private:
	static constexpr float GUI_FACTOR = 1.12500f;
	sf::RenderWindow m_Window;
	tg::Gui m_Gui;

	std::unordered_map<ScreenKey, ScreenLoader> m_Loaders;
	ScreenKey m_CurrentlyRendered;
	bool m_ScreenUpdated = false;
		
	WindowManager() = default;
	WindowManager(const WindowManager&) = delete;

public:
	static WindowManager& Get();

public:
	void init();
	void center();
	void close();
	void add(const ScreenKey& key, ScreenLoader loader);
	void setScreen(const ScreenKey& key);
	void run();

	Vec2f relToWindow(const Vec2f& vec);
	Vec2f relToView(const Vec2f& vec);
	Lay2d relToGuiView(const Vec2f& vec);

	float relToGuiView(float ratio, _Impl_Direction dir);
	float relToView(float ratio, _Impl_Direction dir);

	static Vec2f guiToWin(const Vec2f& vec);
	static Lay2d winToGui(const Vec2f& vec);

	sf::RenderWindow* getWindow();
	tg::Gui* getGui();
	Vec2f getMousePosition();
};

#define REL_VIEW_X(x)  WindowManager::Get().relToView(x, _Impl_Direction::X)
#define REL_VIEW_Y(y)  WindowManager::Get().relToView(y, _Impl_Direction::Y)
#define REL_GUI_X(x)   WindowManager::Get().relToGuiView(x, _Impl_Direction::X)
#define REL_GUI_Y(y)   WindowManager::Get().relToGuiView(y, _Impl_Direction::Y)

#define REL_VIEW(x, y) WindowManager::Get().relToView({x, y})
#define REL_GUI(x, y)  WindowManager::Get().relToGuiView({x, y})