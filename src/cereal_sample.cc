

// STL
#include <fstream>
#include <string>
#include <vector>

// Cereal
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/vector.hpp>

// Eigen
#include <eigen3/Eigen/Core>

// Original
#include "eigen_serializable.h"

const std::string test_path = "./sample.bin";

void SaveAsBinary() {
  std::vector<Eigen::VectorXf> descriptors;
  for (int i = 0; i < 10; i++) {
    Eigen::VectorXf descriptor(4);
    descriptor << i, 2 * i, 3 * i, 4 * i;
    descriptors.push_back(descriptor);
    std::cout << descriptor << std::endl;
  }

  std::ofstream feature_writer(test_path, std::ios::out | std::ios::binary);
  cereal::PortableBinaryOutputArchive output_archive(feature_writer);
  output_archive(descriptors);
}

void LoadFromBinary() {
  std::ifstream feature_reader(test_path, std::ios::in | std::ios::binary);

  cereal::PortableBinaryInputArchive input_archive(feature_reader);

  std::vector<Eigen::VectorXf> descriptors;
  input_archive(descriptors);

  for (auto desc : descriptors) {
    std::cout << desc << std::endl;
  }
}

int main(int argc, char**) {
  SaveAsBinary();

  LoadFromBinary();

  return 0;
}
