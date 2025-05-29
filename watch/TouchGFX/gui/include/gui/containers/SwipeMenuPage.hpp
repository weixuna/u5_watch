#ifndef SWIPEMENUPAGE_HPP
#define SWIPEMENUPAGE_HPP

#include <gui_generated/containers/SwipeMenuPageBase.hpp>

class SwipeMenuPage : public SwipeMenuPageBase
{
public:
    SwipeMenuPage();
    virtual ~SwipeMenuPage() {}

    virtual void initialize();

    // 下滑显示菜单
    void showSlideMenu();

    // 上滑隐藏菜单
    void hideSlideMenu();

    // 处理手势事件
    virtual void handleGestureEvent(const touchgfx::GestureEvent& event);

    // 获取菜单是否可见
    bool isMenuVisible() const { return menuVisible; }
protected:
    bool menuVisible; // 菜单是否可见
};

#endif // SWIPEMENUPAGE_HPP
