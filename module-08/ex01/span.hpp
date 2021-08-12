#ifndef SPAN_H
#define SPAN_H

#include <stdexcept>
#include <climits>

class Span
{
private:
    int* array;
    unsigned int size;
    unsigned int maxSize;
    unsigned int shortSpan;
    unsigned int longSpan;

public:
    Span();
    explicit Span(unsigned int N);
    Span(const Span& span);
    ~Span();

    Span& operator=(const Span& span);

    int getArray(unsigned int index) const;
    unsigned int getSize() const;
    unsigned int getMaxSize() const;
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    void addNumber(int v);

    template <typename InputIterator>
    void addNumber(InputIterator begin, InputIterator end)
    {
        int count = maxSize - size;
        for (InputIterator it = begin; it != end; ++it)
        {
            --count;
            if (count < 0)
            {
                throw std::logic_error("Can't store any more");
            }
        }

        for (InputIterator it = begin; it != end; ++it)
        {
            addNumber(*it);
        }
    }
};

#endif
