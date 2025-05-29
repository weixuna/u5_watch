#ifndef SCROLLMENUPAGE_HPP
#define SCROLLMENUPAGE_HPP

#include <gui_generated/containers/ScrollMenuPageBase.hpp>

#include <images/BitmapDatabase.hpp>

class ScrollMenuPage : public ScrollMenuPageBase
{
public:
    ScrollMenuPage();
    virtual ~ScrollMenuPage() {}

    virtual void initialize();

    void setNumber(int number)

    {
        // Unicode::itoa(no, TextArea, TextArea, 10);

        switch (number % 9)
        {
        case 0:
            image1.setBitmap(Bitmap(BITMAP_ICON_ADDRESS_BOOK_ID));
            break;
        case 1:
            image1.setBitmap(Bitmap(BITMAP_ICON_BLOOD_OXYGEN_ID));
            break;
        case 2:
            image1.setBitmap(Bitmap(BITMAP_ICON_COMPASS_ID));
            break;
        case 3:
            image1.setBitmap(Bitmap(BITMAP_ICON_CONTACT_PERSON_ID));
            break;
        case 4:
            image1.setBitmap(Bitmap(BITMAP_ICON_HEART_RATE_ID));
            break;
        case 5:
            image1.setBitmap(Bitmap(BITMAP_ICON_LOCATION_ID));
            break;
        case 6:
            image1.setBitmap(Bitmap(BITMAP_ICON_REGULARLY_ID));
            break;
        case 7:
            image1.setBitmap(Bitmap(BITMAP_ICON_SETTINGS_ID));
            break;
        case 8:
            image1.setBitmap(Bitmap(BITMAP_ICON_SPORT_ID));
            break;
        }
    }

protected:
};

#endif // SCROLLMENUPAGE_HPP
