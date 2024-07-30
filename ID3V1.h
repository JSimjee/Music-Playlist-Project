#pragma once

#include <string>

struct ID3v1 {
  // char properties[128];
  char _tag[3];
  char _title_tag[4];
  char _title[30];
  char _artist[30];
  char _album[30];
  char _year[4];
  char _comment[30];
  char _genre[1];

  bool valid() const { return tag() == "TAG"; }
  std::string tag() const { return std::string(_tag,3); }
  std::string title_tag() const { return std::string(_title_tag,4); }
  std::string title() const { return std::string(_title,30); }
  /*
  1. Shouldn't the bool and two strings contribute to the size of an ID3V1 object?
  2. How do you construct all of these data members? You don't have a manually defined constructor, so where is it coming from and how does it work alongside the "int f" and "int n" in main?
  */
};