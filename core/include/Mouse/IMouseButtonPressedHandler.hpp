/*
** EPITECH PROJECT, 2020
** IMouseButtonPressed.hpp
** File description:
** header for IMouseButtonPressed.c
*/

#ifndef INPUT_IMOUSEBUTTONPRESSED_HPP
#define INPUT_IMOUSEBUTTONPRESSED_HPP


#include "polymorph/engine/event-modules.hpp"

namespace polymorph::engine::event
{
    class MouseEvent;

    class IMouseButtonPressedHandler
    {
        public:
            virtual ~IMouseButtonPressedHandler() = default;
            virtual void onMouseButtonPressed(MouseEvent &event) = 0;
    };
}


#endif //INPUT_IMOUSEBUTTONPRESSED_HPP
