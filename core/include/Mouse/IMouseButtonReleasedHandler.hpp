/*
** EPITECH PROJECT, 2020
** IMouseButtonReleasedHandler.hpp
** File description:
** header for IMouseButtonReleasedHandler.c
*/

#ifndef INPUT_IMOUSEBUTTONRELEASEDHANDLER_HPP
#define INPUT_IMOUSEBUTTONRELEASEDHANDLER_HPP

#include "polymorph/engine/event-modules.hpp"


namespace polymorph::engine::event
{
    class MouseEvent;
    
    class IMouseButtonReleasedHandler
    {
        public:
            virtual ~IMouseButtonReleasedHandler() = default;
            virtual void onMouseButtonReleased(MouseEvent &event) = 0;
    };
}


#endif //INPUT_IMOUSEBUTTONRELEASEDHANDLER_HPP
