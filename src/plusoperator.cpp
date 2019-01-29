#include "plusoperator.h"

PlusOperator::PlusOperator()
{
    //ctor
}

PlusOperator::PlusOperator(std::shared_ptr<Expansion> e)
{
    childExpansion = e;
}

PlusOperator::~PlusOperator()
{
    childExpansion.reset();
}

Expansion * PlusOperator::clone() {
    return new PlusOperator(std::shared_ptr<Expansion>(this->getChild()->clone()));
}

std::string PlusOperator::getText() {
    std::string s = childExpansion->getText();
    s.append("+");
    return s;
}

ExpansionType PlusOperator::getType() {
    return PLUS_OPERATOR;
}

bool PlusOperator::hasChild() {
    return childExpansion != nullptr;
}

std::shared_ptr<Expansion> PlusOperator::getChild() {
    return childExpansion;
}

void PlusOperator::setChild(std::shared_ptr<Expansion> e) {
    childExpansion = e;
}
