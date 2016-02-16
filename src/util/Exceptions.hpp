#pragma once

#include <stdexcept>
#include <typeindex>
#include "Demangle.hpp"

namespace envire { namespace core
{
    template<class InheritedClass, class BaseClass>
    class DownCastException : public std::exception
    {
    public:
        explicit DownCastException(const std::string& inherited_class_name = "") :
            msg("Failed to downcast " + envire::core::demangleTypeName(std::type_index(typeid(BaseClass)))
                + " to type " + envire::core::demangleTypeName(std::type_index(typeid(InheritedClass))) +
                (inherited_class_name.empty() ? "" : ", the base class is not of type " + inherited_class_name) + "!") {}
        virtual char const * what() const throw() { return msg.c_str(); }
        const std::string msg;
    };



}}