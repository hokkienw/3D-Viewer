#ifndef _3DVIEWER_V2_SRC_APP_MODEL_DATA_H_
#define _3DVIEWER_V2_SRC_APP_MODEL_DATA_H_

#include <vector>

namespace s21 {

class Data {
 public:
  Data() : vertixes_(std::vector<double>()), polygons_(std::vector<int>()) {}
  Data(std::vector<double>&& v, std::vector<int>&& i, unsigned int f,
       unsigned int ve, double m)
      : vertixes_(std::move(v)),
        polygons_(std::move(i)),
        count_polygons_(f),
        count_vertexes_(ve),
        max_(m) {}
  ~Data() {}
  auto set_vertixes(int pos, double value) -> void {
    if ((int)vertixes_.size() > pos) {
      vertixes_[pos] = value;
    } else {
      vertixes_.push_back(value);
    }
  }
  auto get_vertixes() const -> const std::vector<double>& { return vertixes_; }
  auto get_indices() const -> const std::vector<int>& { return polygons_; }
  auto get_facets_count() const -> unsigned int { return count_polygons_; }
  auto get_vertex_count() const -> unsigned int { return count_vertexes_; }
  auto get_data() const -> const double* { return vertixes_.data(); }
  auto get_max() const -> double { return max_; }

 private:
  std::vector<double> vertixes_{};
  std::vector<int> polygons_{};
  unsigned int count_vertexes_ = 0;
  unsigned int count_polygons_ = 0;
  double max_ = 0;
};

}  // namespace s21

#endif  //_3DVIEWER_V2_SRC_APP_MODEL_DATA_H_
