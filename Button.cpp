
#include "Button.hpp"

Button::Button(){}

Button::Button (float x, float y, float width, float height, Font& f,
                string text, Color idleColor, Color hoverColor, Color activeColor, int initialState, float screenScale)
{
    shape.setPosition(Vector2f(x, y));
    shape.setSize(Vector2f(width, height));
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(3.0f * screenScale);
    textButton.setString(text);
    textButton.setFont(f);
    textButton.setFillColor(Color::Blue);
    textButton.setCharacterSize(int(20.0f * screenScale));
    textButton.setPosition(
        shape.getPosition().x + (shape.getGlobalBounds().width / 2.f)  - textButton.getGlobalBounds().width / 2.f,
        shape.getPosition().y + (shape.getGlobalBounds().height / 2.f)  - textButton.getGlobalBounds().height / 2.f - 5
    );

    // Store the possible colors of the button
    idleColorButton = idleColor;
    hoverColorButton = hoverColor;
    activeColorButton = activeColor;

    // Check the initial state of the button
    switch (initialState){
        case 0:
            buttonState = BUTTON_IDLE;
            shape.setFillColor(idleColorButton);
        break;
        case 1:
            buttonState = BUTTON_HOVER;
            shape.setFillColor(hoverColorButton);
        break;
        case 2:
            buttonState = BUTTON_PRESSED;
            shape.setFillColor(activeColorButton);
    }
}



void Button::setButtonState(button_states stateButton){
    switch(stateButton){
        case BUTTON_IDLE:
            shape.setFillColor(idleColorButton);
        break;
        case BUTTON_HOVER:
            shape.setFillColor(hoverColorButton);
        break;
        case BUTTON_PRESSED:
            shape.setFillColor(activeColorButton);
    }
}


void Button::render (RenderTexture* app){
    app->draw(shape);
    app->draw(textButton);
}


void Button::setTextButton(string newString){
    textButton.setString(newString);
    textButton.setPosition(
        shape.getPosition().x + (shape.getGlobalBounds().width / 2.f)  - textButton.getGlobalBounds().width / 2.f,
        shape.getPosition().y + (shape.getGlobalBounds().height / 2.f)  - textButton.getGlobalBounds().height / 2.f - 5
    );
}


string Button::getTextButton(){
    return textButton.getString();
}
