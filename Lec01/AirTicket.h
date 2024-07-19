#include <string>
class AirTicket {
    private:
        std::string name;
        int miles;
    public:
        AirTicket();
        ~AirTicket();
        std::string getName();
        void setName(std::string);
        void setMiles(int);
        int calculatePrice();
};