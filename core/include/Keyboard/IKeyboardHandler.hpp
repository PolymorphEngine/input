/*
** EPITECH PROJECT, 2020
** IKeyboardHandler.hpp
** File description:
** header for IKeyboardHandler.c
*/

#ifndef INPUT_IKEYBOARDHANDLER_HPP
#define INPUT_IKEYBOARDHANDLER_HPP

#include "polymorph/engine/event-modules.hpp"

namespace polymorph::engine::event
{
    class KeyboardEvent;
    
    class IKeyboardHandler
    {
        public:
            virtual ~IKeyboardHandler() = default;
            virtual void onKeyEvent(KeyboardEvent &event) = 0;
    };
}



#endif //INPUT_IKEYBOARDHANDLER_HPP
