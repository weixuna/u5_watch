#ifndef MENUPAGEVIEW_HPP
#define MENUPAGEVIEW_HPP

#include <gui_generated/menupage_screen/menuPageViewBase.hpp>
#include <gui/menupage_screen/menuPagePresenter.hpp>

class menuPageView : public menuPageViewBase
{
public:
    menuPageView();
    virtual ~menuPageView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollWheelUpdateItem(ScrollMenuPage &item, int16_t itemIndex)
    {
        item.setNumber(itemIndex);
    }

protected:
};

#endif // MENUPAGEVIEW_HPP
