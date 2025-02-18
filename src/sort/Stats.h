#pragma once

struct Stats {
  int rowComparisons = 0;
  int columnComparisons = 0;
};

inline Stats getNewStats() {
  return {
    0,
    0
  };
}