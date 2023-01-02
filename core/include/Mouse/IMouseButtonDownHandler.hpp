/*
** EPITECH PROJECT, 2020
** IMouseButtonDownHandler.hpp
** File description:
** header for IMouseButtonDownHandler.c
*/

#ifndef INPUT_IMOUSEBUTTONDOWNHANDLER_HPP
#define INPUT_IMOUSEBUTTONDOWNHANDLER_HPP


#include "polymorph/engine/event-modules.hpp"


namespace polymorph::engine::event
{
    class MouseEvent;
    class IMouseButtonDownHandler
    {
        public:
            virtual ~IMouseButtonDownHandler() = default;
            virtual void onMouseButtonDown(MouseEvent &event) = 0;
    };
}



#endif //INPUT_IMOUSEBUTTONDOWNHANDLER_HPP
