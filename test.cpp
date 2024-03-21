#include <iostream>
#include <chrono>

int main() {
    // Get user input: current year, day of the year, second, and nanosecond in the day
    int year, dayOfYear, seconds, nanoseconds;
    std::cout << "Enter current year: ";
    std::cin >> year;
    std::cout << "Enter day of the year: ";
    std::cin >> dayOfYear;
    std::cout << "Enter second in the day: ";
    std::cin >> seconds;
    std::cout << "Enter nanosecond in the day: ";
    std::cin >> nanoseconds;

    // Get the timestamp for the beginning of the year
    std::tm timeinfo = {};
    timeinfo.tm_year = year - 1900;  // Years since 1900
    timeinfo.tm_mday = 1;            // January 1st
    time_t beginningOfYear = std::mktime(&timeinfo);

    // Calculate the timestamp for the given day of the year
    timeinfo.tm_yday = dayOfYear - 1;  // Days since January 1st (0-indexed)
    time_t givenDayTimestamp = std::mktime(&timeinfo);

    // Add seconds and nanoseconds within the day to get total seconds since epoch
    time_t secondsSinceEpoch = beginningOfYear + givenDayTimestamp + seconds;
    std::chrono::seconds secs(secondsSinceEpoch);
    std::chrono::nanoseconds nsecs(nanoseconds);
    auto finalTimePoint = std::chrono::time_point<std::chrono::system_clock>(secs) + nsecs;

    // Convert the final time point to seconds since epoch
    auto finalSecondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(
        finalTimePoint.time_since_epoch()
    ).count();

    std::cout << "Seconds since epoch: " << finalSecondsSinceEpoch << std::endl;

    return 0;
}
