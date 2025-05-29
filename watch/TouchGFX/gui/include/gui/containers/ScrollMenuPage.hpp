#ifndef SCROLLMENUPAGE_HPP
#define SCROLLMENUPAGE_HPP

#include <gui_generated/containers/ScrollMenuPageBase.hpp>

#include <images/SVGDatabase.hpp>

class ScrollMenuPage : public ScrollMenuPageBase
{
public:
    ScrollMenuPage();
    virtual ~ScrollMenuPage() {}

    virtual void initialize();

    void setNumber(int number)

    {
        // Unicode::itoa(no, TextArea, TextArea, 10);

        switch (number % 8)
        {
        case 0:
            svgImage1.setSVG(SVG_ICON_SETTINGS_ID);
            svgImage1.setPosition(12, 5, 45, 45);
            svgImage1.setScale(0.04f, 0.04f);
            svgImage1.setImagePosition(0, 0);
            svgImage1.setRotationCenter(0, 0);
            svgImage1.setRotation(0.0f);
            break;
        case 1:
            svgImage1.setSVG(SVG_ICON_ADDRESS_BOOK_ID);
            svgImage1.setPosition(12, 5, 45, 45);
            svgImage1.setScale(0.04f, 0.04f);
            svgImage1.setImagePosition(0, 0);
            svgImage1.setRotationCenter(0, 0);
            svgImage1.setRotation(0.0f);
            break;
        case 2:
            svgImage1.setSVG(SVG_ICON_BLOOD_OXYGEN_ID);
            svgImage1.setPosition(12, 5, 45, 45);
            svgImage1.setScale(0.04f, 0.04f);
            svgImage1.setImagePosition(0, 0);
            svgImage1.setRotationCenter(0, 0);
            svgImage1.setRotation(0.0f);
            break;
        case 3:
            svgImage1.setSVG(SVG_ICON_COMPASS_ID);
            svgImage1.setPosition(12, 5, 45, 45);
            svgImage1.setScale(0.04f, 0.04f);
            svgImage1.setImagePosition(0, 0);
            svgImage1.setRotationCenter(0, 0);
            svgImage1.setRotation(0.0f);
            break;
        case 4:
            svgImage1.setSVG(SVG_ICON_CONTACT_PERSON_ID);
            svgImage1.setPosition(12, 5, 45, 45);
            svgImage1.setScale(0.04f, 0.04f);
            svgImage1.setImagePosition(0, 0);
            svgImage1.setRotationCenter(0, 0);
            svgImage1.setRotation(0.0f);
            break;
        case 5:
            svgImage1.setSVG(SVG_ICON_HEART_RATE_ID);
            svgImage1.setPosition(12, 5, 45, 45);
            svgImage1.setScale(0.04f, 0.04f);
            svgImage1.setImagePosition(0, 0);
            svgImage1.setRotationCenter(0, 0);
            svgImage1.setRotation(0.0f);
            break;
        case 6:
            svgImage1.setSVG(SVG_ICON_LOCATION_ID);
            svgImage1.setPosition(12, 5, 45, 45);
            svgImage1.setScale(0.04f, 0.04f);
            svgImage1.setImagePosition(0, 0);
            svgImage1.setRotationCenter(0, 0);
            svgImage1.setRotation(0.0f);
            break;
        case 7:
            svgImage1.setSVG(SVG_ICON_SPORT_ID);
            svgImage1.setPosition(12, 5, 45, 45);
            svgImage1.setScale(0.04f, 0.04f);
            svgImage1.setImagePosition(0, 0);
            svgImage1.setRotationCenter(0, 0);
            svgImage1.setRotation(0.0f);
            break;
        }
    }

protected:
};

#endif // SCROLLMENUPAGE_HPP
