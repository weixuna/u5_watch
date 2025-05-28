#ifndef MAINPAGEVIEW_HPP
#define MAINPAGEVIEW_HPP

#include <gui_generated/mainpage_screen/mainPageViewBase.hpp>
#include <gui/mainpage_screen/mainPagePresenter.hpp>

class mainPageView : public mainPageViewBase
{
public:
    mainPageView();
    virtual ~mainPageView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleGestureEvent(const touchgfx::GestureEvent &evt);
protected:
};

#endif // MAINPAGEVIEW_HPP
