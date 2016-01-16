#include "SimpleView.h"

SimpleView::SimpleView(QWidget *parent) :
    QWidget(parent),
    board_(new Board),
    game_info_(new QLabel),
    current_screen_(new SimpleStartScreen(this))
{
    setLayout(current_screen_->GetLayout());
}

void SimpleView::ModelUpdated(GameState gs)
{
    std::cout << "New game state\n";
    if(gs.current_screen_ != current_screen_->GetType())
    {
        std::cout << "Different screen\n";
        // Close previous screen
        CloseScreen();

        // Open new screen
        switch(gs.current_screen_)
        {
        case GameState::START:
            current_screen_ = new SimpleStartScreen(this);
            break;
        case GameState::SINGLE:
            break;
        case GameState::HOTSEAT:
            std::cout << "Hoatseat screen\n";
            current_screen_ = new SimpleHotseatScreen(this, board_);
            break;
        case GameState::ONLINE:
            break;
        case GameState::GAME_OVER:
            break;
        }

        // Set the layout
        setLayout(current_screen_->GetLayout());
    }

    if(current_screen_->Update(gs))
    {
        update();
    }

}

void SimpleView::CloseScreen()
{
    // Get current layout
    QLayout* layout = this->layout();

    if(layout == nullptr)
    {
        return;
    }

    // Grab shared resources
    layout->removeWidget(board_);
    board_->hide();

    delete layout;
    layout = nullptr;

    delete current_screen_;
    current_screen_ = nullptr;
}
