#include "SimpleStartScreen.h"

SimpleStartScreen::SimpleStartScreen(QWidget *view) :
    Screen(view)
{
}

QLayout* SimpleStartScreen::GetLayout()
{
    if(layout_)
    {
        return layout_;
    }

    // Make start buttons
    QPushButton* single = new QPushButton("Play the Computer");
    QPushButton* hotseat = new QPushButton("Play Hotseat");
    QPushButton* online = new QPushButton("Play Online");
    QPushButton* quit = new QPushButton("Quit");

    // Make layout
    layout_ = new QVBoxLayout;

    // Add buttons to layout
    layout_->addWidget(single);
    layout_->addWidget(hotseat);
    layout_->addWidget(online);
    layout_->addWidget(quit);

    // Set up connections
    QObject::connect(quit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    QObject::connect(hotseat, SIGNAL(clicked()), view_, SIGNAL(HotseatClicked()));

    return layout_;
}


GameState::screen_type SimpleStartScreen::GetType()
{
    return GameState::START;
}



bool SimpleStartScreen::Update(GameState& gs)
{
    return false;
}
