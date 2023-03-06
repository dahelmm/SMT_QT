#include "stylehelper.h"

QString StyleHelper::getCheckboxesStyle()
{
    return  "QCheckBox { "
                "spacing: 5px; "
                "border: 1px solid grey;"
                "border-radius: 5px;"
            "} "
            "QCheckBox::indicator { "
                "width: 20px;"
                "height: 20px;"
            "}"
            "QCheckBox::indicator:unchecked:disabled{ "
                "image: url(:/Icons/CheckBoxes/unchecked_disabled.png);"
            "}"
            "QCheckBox::indicator:checked{"
                "image: url(:/Icons/CheckBoxes/checked.png);"
            "}"
            "QCheckBox::indicator:unchecked {"
                "image: url(:/Icons/CheckBoxes/unchecked.png);"
            "}";
}

QString StyleHelper::getButtonsStyle()
{
    return "QPushButton {"
                "color: #fff;"
                "border: none;"
                "border-radius: 15px;"
                "background: none;"
                "background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(107, 122, 161, 255), stop:1 rgba(135, 154, 202, 255));"
                "font-family: 'Roboto Medium';"
                "font-size: 13px;"
           "}"
           "QPushButton::disabled {"
                "color: rgb(225, 225, 225);"
                "background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(92, 105, 138, 255), stop:1 rgba(112, 128, 167, 255));"
           "}"
           "QPushButton::hover {"
                "background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(124, 142, 186, 255), stop:0.994318 rgba(156, 179, 232, 255));"
           "}";
}

QString StyleHelper::getMainWidgetStyle()
{
    return "QWidget {"
                "color: #fff;"
                "background-image: url(:/icons/bg.png);"
           "}";
}

QString StyleHelper::getLabelsStyle()
{
    return "QLabel {"
                "background-color: white;"
                "color: black"
           "};";
}

