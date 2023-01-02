/*
** EPITECH PROJECT, 2020
** IMouseHandler.hpp
** File description:
** header for IMouseHandler.c
*/

#ifndef INPUT_IMOUSEHANDLER_HPP
#define INPUT_IMOUSEHANDLER_HPP

#include "polymorph/engine/event-modules.hpp"

namespace polymorph::engine::event
{
    class MouseEvent;
    class IMouseHandler
    {
        public:
            virtual ~IMouseHandler() = default;
            virtual void onMouseEvent(MouseEvent &event) = 0;
    };
}



#endif //INPUT_IMOUSEHANDLER_HPP
