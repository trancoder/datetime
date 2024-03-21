#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    // Get seconds since epoch from user input
    std::time_t seconds_since_epoch;
    std::cout << "Enter seconds since epoch: ";
    std::cin >> seconds_since_epoch;

    // Convert seconds since epoch to a time point
    std::chrono::system_clock::time_point time_point = std::chrono::system_clock::from_time_t(seconds_since_epoch);

    // Convert time point to a time_t object
    std::time_t time_t_value = std::chrono::system_clock::to_time_t(time_point);

    // Convert time_t object to a tm struct for local time
    std::tm* local_time = std::localtime(&time_t_value);

    // Extract hour, minute, and second from local time
    int hour = local_time->tm_hour;
    int minute = local_time->tm_min;
    int second = local_time->tm_sec;

    // Calculate seconds since midnight
    int seconds_since_midnight = hour * 3600 + minute * 60 + second;

    // Print the current date and time
    std::cout << "Current date and time: " << std::asctime(local_time);
    std::cout << "Seconds since midnight: " << seconds_since_midnight << std::endl;

    return 0;
}

