
#include <iostream>

template<typename T>
class Interval
{
    private: 
        T start;
        T end;
    public:
        Interval(const T& inStart, const T& inEnd): 
            start(inStart), end(inEnd)
            {}
        T getStart() const
            {
                return start;
            }
        T getEnd() const
            {
                return end;
            }
        T getSize() const
            {
                return (end - start);
            }
        Interval<T> interSection (const Interval<T>& other) const
            {
                return Interval<T>(std::max(start, other.start), 
                            std::min(end, other.end));
            }
};


int main()
{
    const Interval<double> intervalA{1.1,3.5};
    const Interval<double> intervalB{2.7,4.9};
    Interval<double> intersectionAB{intervalA.interSection(intervalB)};
    std::cout<<intersectionAB.getStart()<<","
                <<intersectionAB.getEnd()<<std::endl;
    
    return 0;
}


