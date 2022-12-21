#include <iostream>
using namespace std;

class Fraction {
    private:
    int m_numerator;
    int m_denominator;
    public:
    Fraction() {
        m_numerator = 10;
        m_denominator = 15;
    }
    int getNumerator() {return m_numerator;}
    int getDenominator() {return m_denominator;}
    double getValue() { return static_cast<double>(m_numerator)/m_denominator;}
};

int main() {
    Fraction frac;
    cout << frac.getNumerator() << "/" << frac.getDenominator() << '\n';
}