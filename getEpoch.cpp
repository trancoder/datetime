#include <iostream>
#include <chrono>

int main() {
    // Get the current time point using the system clock
    auto currentTime = std::chrono::system_clock::now();

    // Convert the current time point to seconds since epoch
    auto currentTimeSecs = std::chrono::duration_cast<std::chrono::seconds>(currentTime.time_since_epoch()).count();

    // Extract the day of the year from the current time
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* currentTimeTM = std::localtime(&currentTimeT);
    int dayOfYear = currentTimeTM->tm_yday + 1;  // tm_yday is 0-based, so add 1

    // Display the result
    std::cout << "Current day of the year: " << dayOfYear << std::endl;
    std::cout << "Current time since epoch in seconds: " << currentTimeSecs << std::endl;

    return 0;
}

