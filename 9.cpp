
#include <iostream>

class Stone
{
  private:
    enum {Lbs_per_stones = 14};
    int stone;
    double pounds;
    double pds_left;
  public:
    explicit Stone (const double lbs);
    Stone (const int stn, const double lbs);
    Stone();
    ~Stone();
    void show_lbs() const;
    void show_stn() const;
};

int main()
{
    double a = 1.2;
    Stone s1 = (Stone)375;
    //Stone s2 = a;
    //s1 = 278.1;
    //s2 = 500;

    return 0;
}

Stone::Stone (const double lbs)
{
    stone = int(lbs) / Lbs_per_stones;
    pds_left = int(lbs) % Lbs_per_stones + lbs - int(lbs);
    pounds = lbs;
}

Stone::Stone (const int stn, const double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stone * Lbs_per_stones + pds_left;
}

Stone::Stone()
{
   stone = pds_left = pounds = 0;  
}

Stone::~Stone()
{
    
}

void Stone::show_stn() const
{
    std::cout<<stone<< " stones, "<<pds_left<<" pounds_left"<<std::endl;
    
}

void Stone::show_lbs() const
{
    std::cout<<pounds<<" pounds"<<std::endl;
    
}
