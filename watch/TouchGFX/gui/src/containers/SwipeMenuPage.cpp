#include <gui/containers/SwipeMenuPage.hpp>

SwipeMenuPage::SwipeMenuPage()
{
    menuVisible = false;
}

void SwipeMenuPage::initialize()
{
    SwipeMenuPageBase::initialize();

    // 初始化时隐藏菜单，保持mainPage可见
    slideMenuPage.setPosition(0, -296, 240, 296);
    menuVisible = false;
}

void SwipeMenuPage::showSlideMenu()
{
    // 使用MoveAnimator将SlideMenuPage从屏幕外移动到可见位置
    slideMenuPage.startMoveAnimation(0, 0, 20, EasingEquations::cubicEaseInOut, EasingEquations::cubicEaseInOut);

    // 不要移除swipeContainerPage，而是将它移到slideMenuPage的下方
    // 确保slideMenuPage在最上层显示
    remove(slideMenuPage);
    add(slideMenuPage);

    menuVisible = true;
}

void SwipeMenuPage::hideSlideMenu()
{
    // 使用MoveAnimator将SlideMenuPage移动到屏幕外
    slideMenuPage.startMoveAnimation(0, -296, 20, EasingEquations::cubicEaseInOut, EasingEquations::cubicEaseInOut);

    menuVisible = false;
}
#include <stdio.h>
void SwipeMenuPage::handleGestureEvent(const touchgfx::GestureEvent &event)
{
    printf("handleGestureEvent\r\n");
    // 检测垂直滑动手势
    if (event.getType() == event.SWIPE_VERTICAL)
    {
        // 下滑显示菜单 (正值表示向下滑动)
        if (event.getVelocity() > 0 && !menuVisible)
        {
            showSlideMenu();
            printf("down\r\n");
        }
        // 上滑隐藏菜单 (负值表示向上滑动)
        else if (event.getVelocity() < 0 && menuVisible)
        {
            hideSlideMenu();
            printf("up\r\n");
        }
    }

    // 调用父类的手势处理方法
    SwipeMenuPageBase::handleGestureEvent(event);
}
