#include "SimpleStartScreen.h"

SimpleStartScreen::SimpleStartScreen(QWidget* parent):
    BaseScreen(parent)
{  
    // Add buttons to layout
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(single);
    layout->addWidget(hotseat);
    layout->addWidget(online);
    layout->addWidget(quit);

    setLayout(layout);

    // Get pointer to controller
    QObject* controller = parentWidget();
    if(controller == nullptr) return;

    while(controller->parent() != nullptr)
    {
        controller = controller->parent();
    }

    // Set up connections
    connect(quit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(hotseat, SIGNAL(clicked()), controller, SLOT(HotseatClicked()));
}

void SimpleStartScreen::Update(GameState *gs)
{
    // Nothing to do
}
