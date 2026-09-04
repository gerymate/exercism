#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

    using boost::gregorian::Monday;
    using boost::gregorian::Tuesday;
    using boost::gregorian::Wednesday;
    using boost::gregorian::Thursday;
    using boost::gregorian::Friday;
    using boost::gregorian::Saturday;
    using boost::gregorian::Sunday;

class scheduler {
public:
    scheduler(boost::gregorian::greg_month month, boost::gregorian::greg_year year) : month{month}, year{year} {};
    
    boost::gregorian::date monteenth() const { return day(0, Monday); };
    boost::gregorian::date tuesteenth() const { return day(0, Tuesday); };
    boost::gregorian::date wednesteenth() const { return day(0, Wednesday); };
    boost::gregorian::date thursteenth() const { return day(0, Thursday); };
    boost::gregorian::date friteenth() const { return day(0, Friday); };
    boost::gregorian::date saturteenth() const { return day(0, Saturday); };
    boost::gregorian::date sunteenth() const { return day(0, Sunday); };
    
    boost::gregorian::date first_monday() const { return day(1, Monday); };
    boost::gregorian::date first_tuesday() const { return day(1, Tuesday); };
    boost::gregorian::date first_wednesday() const { return day(1, Wednesday); };
    boost::gregorian::date first_thursday() const { return day(1, Thursday); };
    boost::gregorian::date first_friday() const { return day(1, Friday); };
    boost::gregorian::date first_saturday() const { return day(1, Saturday); };
    boost::gregorian::date first_sunday() const { return day(1, Sunday); };
    
    boost::gregorian::date second_monday() const { return day(2, Monday); };
    boost::gregorian::date second_tuesday() const { return day(2, Tuesday); };
    boost::gregorian::date second_wednesday() const { return day(2, Wednesday); };
    boost::gregorian::date second_thursday() const { return day(2, Thursday); };
    boost::gregorian::date second_friday() const { return day(2, Friday); };
    boost::gregorian::date second_saturday() const { return day(2, Saturday); };
    boost::gregorian::date second_sunday() const { return day(2, Sunday); };
    
    boost::gregorian::date third_monday() const { return day(3, Monday); };
    boost::gregorian::date third_tuesday() const { return day(3, Tuesday); };
    boost::gregorian::date third_wednesday() const { return day(3, Wednesday); };
    boost::gregorian::date third_thursday() const { return day(3, Thursday); };
    boost::gregorian::date third_friday() const { return day(3, Friday); };
    boost::gregorian::date third_saturday() const { return day(3, Saturday); };
    boost::gregorian::date third_sunday() const { return day(3, Sunday); };
    
    boost::gregorian::date fourth_monday() const { return day(4, Monday); };
    boost::gregorian::date fourth_tuesday() const { return day(4, Tuesday); };
    boost::gregorian::date fourth_wednesday() const { return day(4, Wednesday); };
    boost::gregorian::date fourth_thursday() const { return day(4, Thursday); };
    boost::gregorian::date fourth_friday() const { return day(4, Friday); };
    boost::gregorian::date fourth_saturday() const { return day(4, Saturday); };
    boost::gregorian::date fourth_sunday() const { return day(4, Sunday); };

    boost::gregorian::date last_monday() const { return day(5, Monday); };
    boost::gregorian::date last_tuesday() const { return day(5, Tuesday); };
    boost::gregorian::date last_wednesday() const { return day(5, Wednesday); };
    boost::gregorian::date last_thursday() const { return day(5, Thursday); };
    boost::gregorian::date last_friday() const { return day(5, Friday); };
    boost::gregorian::date last_saturday() const { return day(5, Saturday); };
    boost::gregorian::date last_sunday() const { return day(5, Sunday); };
    
private:
    boost::gregorian::date day(int nth, boost::gregorian::greg_weekday day_name) const;
    boost::gregorian::greg_month month;
    boost::gregorian::greg_year year;
};
    
}  // namespace meetup
