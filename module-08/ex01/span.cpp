#include "span.hpp"

Span::Span()
    : size(0), maxSize(0), shortSpan(UINT_MAX), longSpan(0)
{
    array = new int[0];
    if (!array)
    {
        throw std::runtime_error("new failed");
    }
}

Span::Span(unsigned int N)
    : size(0), maxSize(N), shortSpan(UINT_MAX), longSpan(0)
{
    array = new int[N];
    if (!array)
    {
        throw std::runtime_error("new failed");
    }
}

Span::Span(const Span& span)
    : size(span.getSize()), maxSize(span.getMaxSize()),
      shortSpan(span.shortestSpan()), longSpan(span.longestSpan())
{
    array = new int[maxSize];
    if (!array)
    {
        throw std::runtime_error("new failed");
    }
    for (unsigned int i = 0; i < size; ++i)
    {
        array[i] = span.getArray(i);
    }
}

Span::~Span()
{
    delete[] array;
}

Span& Span::operator=(const Span& span)
{
    int* tmp = new int[span.getMaxSize()];
    if (!tmp)
    {
        throw std::runtime_error("new failed");
    }
    delete[] array;
    array = tmp;

    size = span.getSize();
    maxSize = span.getMaxSize();
    if (size < 2)
    {
        shortSpan = UINT_MAX;
        longSpan = 0;
    }
    else
    {
        shortSpan = span.shortestSpan();
        longSpan = span.longestSpan();
    }
    for (unsigned int i = 0; i < size; ++i)
    {
        array[i] = span.getArray(i);
    }
    return *this;
}

int Span::getArray(unsigned int index) const
{
    if (index >= size)
    {
        throw std::out_of_range("index is out of range");
    }
    return array[index];
}

unsigned int Span::getSize() const
{
    return size;
}

unsigned int Span::getMaxSize() const
{
    return maxSize;
}

unsigned int Span::shortestSpan() const
{
    if (size <= 1)
    {
        throw std::logic_error("Not enough numbers stored");
    }
    return shortSpan;
}

unsigned int Span::longestSpan() const
{
    if (size <= 1)
    {
        throw std::logic_error("Not enough numbers stored");
    }
    return longSpan;
}

void Span::addNumber(int v)
{
    if (size == maxSize)
    {
        throw std::logic_error("Can't store any more");
    }
    int minValue = v;
    int maxValue = v;
    for (unsigned int i = 0; i < size; ++i)
    {
        if (minValue > array[i])
            minValue = array[i];
        if (maxValue < array[i])
            maxValue = array[i];
        unsigned int span = array[i] >= v ? array[i] - v : v - array[i];
        if (span < shortSpan)
            shortSpan = span;
    }
    longSpan = maxValue - minValue;
    array[size] = v;
    ++size;
}
