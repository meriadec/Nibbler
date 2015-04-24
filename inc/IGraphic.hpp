#ifndef NIBBLER_IGRAPHIC_H
#define NIBBLER_IGRAPHIC_H

# include "nibbler.hpp"

class IGraphic {

    public:

        virtual ~IGraphic(void) {};

        virtual void start  (void) = 0;
        virtual void end    (void) = 0;

        virtual const int & getWidth (void) const = 0;
        virtual const int & getHeight (void) const = 0;

};

#endif //NIBBLER_IGRAPHIC_H