#ifndef keyboard_cpp
#define keyboard_cpp

#include "keyboard.h"

Keyboard::Keyboard() {
    this->to_string = std::map<sf::Keyboard::Key, std::string>{
            { sf::Keyboard::Unknown, "unknown" },
            { sf::Keyboard::A, "a" },
            { sf::Keyboard::B, "b" },
            { sf::Keyboard::C, "c" },
            { sf::Keyboard::D, "d" },
            { sf::Keyboard::E, "e" },
            { sf::Keyboard::F, "f" },
            { sf::Keyboard::G, "g" },
            { sf::Keyboard::H, "h" },
            { sf::Keyboard::I, "i" },
            { sf::Keyboard::J, "j" },
            { sf::Keyboard::K, "k" },
            { sf::Keyboard::L, "l" },
            { sf::Keyboard::M, "m" },
            { sf::Keyboard::N, "n" },
            { sf::Keyboard::O, "o" },
            { sf::Keyboard::P, "p" },
            { sf::Keyboard::Q, "q" },
            { sf::Keyboard::R, "r" },
            { sf::Keyboard::S, "s" },
            { sf::Keyboard::T, "t" },
            { sf::Keyboard::U, "u" },
            { sf::Keyboard::V, "v" },
            { sf::Keyboard::W, "w" },
            { sf::Keyboard::X, "x" },
            { sf::Keyboard::Y, "y" },
            { sf::Keyboard::Z, "z" },
            { sf::Keyboard::Num0, "0" },
            { sf::Keyboard::Num1, "1" },
            { sf::Keyboard::Num2, "2" },
            { sf::Keyboard::Num3, "3" },
            { sf::Keyboard::Num4, "4" },
            { sf::Keyboard::Num5, "5" },
            { sf::Keyboard::Num6, "6" },
            { sf::Keyboard::Num7, "7" },
            { sf::Keyboard::Num8, "8" },
            { sf::Keyboard::Num9, "9" },
            { sf::Keyboard::Escape, "escape" },
            { sf::Keyboard::LControl, "left control" },
            { sf::Keyboard::LShift, "left shift" },
            { sf::Keyboard::LAlt, "left alt" },
            { sf::Keyboard::LSystem, "left system" },
            { sf::Keyboard::RControl, "right control" },
            { sf::Keyboard::RShift, "right shift" },
            { sf::Keyboard::RAlt, "right alt" },
            { sf::Keyboard::RSystem, "right system" },
            { sf::Keyboard::Menu, "menu" },
            { sf::Keyboard::LBracket, "left bracket" },
            { sf::Keyboard::RBracket, "right bracket" },
            { sf::Keyboard::SemiColon, "semicolon" },
            { sf::Keyboard::Comma, "comma" },
            { sf::Keyboard::Period, "period" },
            { sf::Keyboard::Quote, "quote" },
            { sf::Keyboard::Slash, "slash" },
            { sf::Keyboard::BackSlash, "backslash" },
            { sf::Keyboard::Tilde, "tilde" },
            { sf::Keyboard::Equal, "equal" },
            { sf::Keyboard::Dash, "dash" },
            { sf::Keyboard::Space, "space" },
            { sf::Keyboard::Return, "return" },
            { sf::Keyboard::BackSpace, "backspace" },
            { sf::Keyboard::Tab, "tab" },
            { sf::Keyboard::PageUp, "page up" },
            { sf::Keyboard::PageDown, "page down" },
            { sf::Keyboard::End, "end" },
            { sf::Keyboard::Home, "home" },
            { sf::Keyboard::Insert, "insert" },
            { sf::Keyboard::Delete, "delete" },
            { sf::Keyboard::Add, "add" },
            { sf::Keyboard::Subtract, "subtract" },
            { sf::Keyboard::Multiply, "multiply" },
            { sf::Keyboard::Divide, "divide" },
            { sf::Keyboard::Left, "left" },
            { sf::Keyboard::Right, "right" },
            { sf::Keyboard::Up, "up" },
            { sf::Keyboard::Down, "down" },
            { sf::Keyboard::Numpad0, "numpad 0" },
            { sf::Keyboard::Numpad1, "numpad 1" },
            { sf::Keyboard::Numpad2, "numpad 2" },
            { sf::Keyboard::Numpad3, "numpad 3" },
            { sf::Keyboard::Numpad4, "numpad 4" },
            { sf::Keyboard::Numpad5, "numpad 5" },
            { sf::Keyboard::Numpad6, "numpad 6" },
            { sf::Keyboard::Numpad7, "numpad 7" },
            { sf::Keyboard::Numpad8, "numpad 8" },
            { sf::Keyboard::Numpad9, "numpad 9" },
            { sf::Keyboard::F1, "f1" },
            { sf::Keyboard::F2, "f2" },
            { sf::Keyboard::F3, "f3" },
            { sf::Keyboard::F4, "f4" },
            { sf::Keyboard::F5, "f5" },
            { sf::Keyboard::F6, "f6" },
            { sf::Keyboard::F7, "f7" },
            { sf::Keyboard::F8, "f8" },
            { sf::Keyboard::F9, "f9" },
            { sf::Keyboard::F10, "f10" },
            { sf::Keyboard::F11, "f11" },
            { sf::Keyboard::F12, "f12" },
            { sf::Keyboard::F13, "f13" },
            { sf::Keyboard::F14, "f14" },
            { sf::Keyboard::F15, "f15" },
            { sf::Keyboard::Pause, "pause" }
    };

}

bool Keyboard::key_valid(const sf::Keyboard::Key& cod) {
    if (this->to_string.find(cod) == this->to_string.end())
        return false;
    
    return true;
}

std::string Keyboard::get_str(const sf::Keyboard::Key& cod) {
    if (!this->key_valid(cod))
        return "Key unvalid.";
    
    return this->to_string[cod];
}

#endif