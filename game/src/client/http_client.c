#include <time.h>

// getPhaseStartTime is a mock of what will be returned from the server
time_t getPhaseStartTime() {

  time_t time_now;

  time(&time_now);

  time_t start_time = time_now + 2;

  return start_time;

}
