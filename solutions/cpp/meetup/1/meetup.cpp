#include "meetup.h"
#include <unordered_map>

namespace meetup {
    using boost::gregorian::nth_day_of_the_week_in_month;
    
    const std::unordered_map<int, boost::date_time::nth_kday_of_month<boost::gregorian::date>::week_num> WEEK_NUM {
        {1, nth_day_of_the_week_in_month::first},
        {2, nth_day_of_the_week_in_month::second},
        {3, nth_day_of_the_week_in_month::third},
        {4, nth_day_of_the_week_in_month::fourth},
        {5, nth_day_of_the_week_in_month::fifth},
    };
    
    boost::gregorian::date scheduler::day(int nth, boost::gregorian::greg_weekday day_name) const {
        if (nth == 0) {
            boost::gregorian::date d(year, month, 13);
            return boost::gregorian::next_weekday(d, day_name);
        };
        nth_day_of_the_week_in_month date_algo(WEEK_NUM.at(nth), day_name, month);
        return date_algo.get_date(year);
}
    
}  // namespace meetup
