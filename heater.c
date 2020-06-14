#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "heater.h"

static uint8_t temperature_cpy;

bool heatoff_guard(void) {
  return ((((float)(temperature_cpy)) * ((150.0) / (255.0))) - (50.0)) > (21.0);
}

float heatoff_arg0(void) {
  return (((float)(temperature_cpy)) * ((150.0) / (255.0))) - (50.0);
}

bool heaton_guard(void) {
  return ((((float)(temperature_cpy)) * ((150.0) / (255.0))) - (50.0)) < (18.0);
}

float heaton_arg0(void) {
  return (((float)(temperature_cpy)) * ((150.0) / (255.0))) - (50.0);
}

void step(void) {
  (temperature_cpy) = (temperature);
  if ((heatoff_guard)()) {
    (heatoff)(((heatoff_arg0)()));
  };
  if ((heaton_guard)()) {
    (heaton)(((heaton_arg0)()));
  };
}
