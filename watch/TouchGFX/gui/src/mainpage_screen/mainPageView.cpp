#include <gui/mainpage_screen/mainPageView.hpp>

mainPageView::mainPageView()
{
}

void mainPageView::setupScreen()
{
    mainPageViewBase::setupScreen();
}

void mainPageView::tearDownScreen()
{
    mainPageViewBase::tearDownScreen();
}
void mainPageView::handleGestureEvent(const touchgfx::GestureEvent &evt)
{
    // 检测下滑手势
    if (evt.getType() == touchgfx::GestureEvent::SWIPE_VERTICAL)
    {
        // 下滑时 (正值表示向下滑动)
        if (evt.getVelocity() > 0)
        {
            // 调用SwipeMenuPage的显示菜单方法
            swipeMenuPage1.showSlideMenu();
        }
        // 上滑时 (负值表示向上滑动)
        else if (evt.getVelocity() < 0)
        {
            // 检查是否显示
            if (swipeMenuPage1.isMenuVisible())
            {
                // 如果显示则隐藏
                swipeMenuPage1.hideSlideMenu();
            }
            else
            {
                application().gotomenuPageScreenSlideTransitionSouth();
            }
        }
    }

    // 正确调用父类方法
    mainPageViewBase::handleGestureEvent(evt);
}
