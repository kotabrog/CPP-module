#ifndef EASYFIND_H
#define EASYFIND_H

template <typename T>
typename T::iterator easyfind(T& container, const int v)
{
    typename T::iterator itEnd = container.end();
    for (typename T::iterator it = container.begin(); it != itEnd; ++it)
    {
        if (*it == v)
            return it;
    }
    return itEnd;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, const int v)
{
    typename T::const_iterator itEnd = container.end();
    for (typename T::const_iterator it = container.begin(); it != itEnd; ++it)
    {
        if (*it == v)
            return it;
    }
    return itEnd;
}

#endif
