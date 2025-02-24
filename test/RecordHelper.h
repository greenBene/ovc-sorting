#pragma once

#include <Record.h>
#include <string>

static Record* generateRecords(std::string* keys, int lenght) {
  Record* records = new Record[lenght];
  for (int i = 0; i < lenght; i++) {
    records[i].key = keys[i];
  }
  return records;
}


