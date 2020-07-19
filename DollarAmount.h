// DollarAmount class stores dollar amounts as a whole numbers of pennies
#include <string>
#include <cmath>

using  namespace  std;

class DollarAmount {
public:
    explicit DollarAmount(int64_t value) : amount{value} { }

    void add(DollarAmount right) {
        amount += right.amount;
    }

    void subtract(DollarAmount right) {
        amount -= right.amount;
    }

    void addInterest(int rate, int divisor) {
        DollarAmount interest{
            (amount * rate + divisor / 2) / divisor
        };

        add(interest);
    }

    string toString() const {
        string dollars{to_string(amount / 100)};
        string cents{to_string(abs(amount % 100))};
        return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
    }
private:
    int64_t amount{0};
};
