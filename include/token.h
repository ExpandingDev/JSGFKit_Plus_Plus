#ifndef TOKEN_H
#define TOKEN_H
#include "expansion.h"
#include <iostream>

using namespace std;

class Token : public Expansion
{
    private:
        string text; //!< Member variable "text"

    public:
        /** Default constructor */
        Token();
        Token(string s);
        /** Default destructor */
        ~Token();

        Expansion * clone();

        /** Access text
         * \return The current value of text
         */
        const string getText();
        /** Set text
         * \param val New value to set
         */
        void setText(string val);

        const ExpansionType getType();
        void replaceChild(std::shared_ptr<Expansion> newChild, const unsigned long index = 0);

        const unsigned int childCount();
        const bool hasChild();
        const shared_ptr<Expansion> getChild(const unsigned int index = 0);
};

#endif // TOKEN_H
