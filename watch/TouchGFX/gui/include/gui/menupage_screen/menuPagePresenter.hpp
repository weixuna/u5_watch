#ifndef MENUPAGEPRESENTER_HPP
#define MENUPAGEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class menuPageView;

class menuPagePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    menuPagePresenter(menuPageView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~menuPagePresenter() {}

private:
    menuPagePresenter();

    menuPageView& view;
};

#endif // MENUPAGEPRESENTER_HPP
