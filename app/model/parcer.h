#ifndef _3DVIEWER_V2_SRC_APP_MODEL_PARCER_H_
#define _3DVIEWER_V2_SRC_APP_MODEL_PARCER_H_

#include <array>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>
#include <vector>

#include "data.h"

namespace s21 {

class Parcer {
 public:
  Parcer() = default;
  ~Parcer() = default;

  void ReadData(const std::string& path, s21::Data& object);

 private:
  void CountVertixesFacets(unsigned int& count_vertexes,
                           unsigned int& count_facets, FILE* file);
  void ParseFile(unsigned int& count_vertexes, unsigned int& count_facets,
                 std::vector<double>& vertixes, std::vector<int>& polygons,
                 double& max, FILE* file);
  void ParseVertex(std::vector<double>& vertixes, const char* line,
                   double& max);
  void ParsePolygons(std::vector<int>& polygons, const char* line);
  static constexpr size_t kBufferSize = 512;
  void ValidateData(unsigned int count_vertexes, unsigned int count_facets,
                    std::vector<int>& polygons);
};

}  // namespace s21

#endif  // _3DVIEWER_V2_SRC_APP_MODEL_PARCER_H_
