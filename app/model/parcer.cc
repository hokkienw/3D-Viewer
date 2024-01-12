#include "parcer.h"

namespace s21 {

auto Parcer::ReadData(const std::string& path, s21::Data& object) -> void {
  FILE* file = std::fopen(path.c_str(), "r");
  if (!file) {
    throw std::runtime_error("Failed to open the file: " + path + "\n");
  }
  unsigned int count_vertexes = 0;
  unsigned int count_facets = 0;
  double max = 0;
  std::rewind(file);
  std::vector<double> vertixes{};
  std::vector<int> polygons{};
  ParseFile(count_vertexes, count_facets, vertixes, polygons, max, file);
  ValidateData(count_vertexes, count_facets, polygons);
  std::fclose(file);
  object = Data(std::move(vertixes), std::move(polygons), count_facets,
                count_vertexes, max);
}

auto Parcer::ParseFile(unsigned int& count_vertexes, unsigned int& count_facets,
                       std::vector<double>& vertixes,
                       std::vector<int>& polygons, double& max, FILE* file)
    -> void {
  char line[kBufferSize];
  while (std::fgets(line, sizeof(line), file)) {
    if (line[0] == 'v' && line[1] == ' ') {
      ParseVertex(vertixes, line, max);
      count_vertexes++;
    }
    if (line[0] == 'f' && line[1] == ' ') {
      ParsePolygons(polygons, line);
      count_facets++;
    }
  }
}

void Parcer::ParseVertex(std::vector<double>& vertices, const char* line,
                         double& max) {
  double x{}, y{}, z{};
  char err{};
  int parsed = sscanf(line + 2, "%lf %lf %lf %c", &x, &y, &z, &err);
  if (parsed == 3) {
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);

    if (fabs(x) > max) max = fabs(x);
    if (fabs(y) > max) max = fabs(y);
    if (fabs(z) > max) max = fabs(z);
  } else {
    throw std::runtime_error("Incorrect vertex format\n");
  }
  if (err != '\0') {
    throw std::runtime_error("Incorrect vertex format\n");
  }
}

void Parcer::ParsePolygons(std::vector<int>& polygons, const char* line) {
  const char* current_char = line;
  char* next_char = nullptr;
  int first_index = -1;
  while (*current_char) {
    if (isdigit(*current_char) || *current_char == '-') {
      int num = (std::strtol(current_char, &next_char, 10)) - 1;
      current_char = next_char;
      if (first_index == -1) {
        first_index = num;
      }
      polygons.push_back(num);

      if (first_index != num) {
        polygons.push_back(num);
      }
      while (*current_char != ' ' && *current_char != '\0') {
        ++current_char;
      }
    } else {
      ++current_char;
    }
  }
  if (first_index != -1) {
    polygons.push_back(first_index);
  }
}

void Parcer::ValidateData(unsigned int count_vertexes,
                          unsigned int count_facets,
                          std::vector<int>& polygons) {
  if (count_facets > 0 && count_vertexes > 0) {
    for (auto i = 0; i < polygons.size() - 1; i++) {
      if (polygons[i] < 0) {
        polygons[i] = count_vertexes + polygons[i] + 1;
        if (polygons[i] < 0) {
          throw std::runtime_error("Incorrect vertex format\n");
        }
      }
    }
  }
}

}  // namespace s21
