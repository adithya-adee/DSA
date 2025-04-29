#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <ctime>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

template <typename T> class Graph {
private:
  // Use a random number generator with time-based seed
  std::mt19937 gen;

public:
  std::vector<std::vector<T>> adjacency_matrix;
  std::vector<std::pair<T, T>> adjacency_list;

  // Constructor initializes random generator with time-based seed
  Graph() : gen(std::time(0)) {}

  // Generate random adjacency matrix
  void generateAdjacencyMatrix(size_t rows, size_t cols) {
    // Resize the matrix to specified dimensions
    adjacency_matrix.resize(rows, std::vector<T>(cols, 0));

    // Create uniform distribution for random values
    std::uniform_int_distribution<> dist(0, 100);
    std::uniform_int_distribution<> chance(0, 3);

    for (auto &row : adjacency_matrix) {
      for (auto &cell : row) {
        // 25% chance of adding a random value
        if (chance(gen) == 0) {
          cell = dist(gen);
        }
      }
    }
  }

  // Convert adjacency matrix to adjacency list
  void adjacencyMatrixToAdjacencyList() {
    // Clear existing adjacency list
    adjacency_list.clear();

    for (size_t i = 0; i < adjacency_matrix.size(); ++i) {
      for (size_t j = 0; j < adjacency_matrix[i].size(); ++j) {
        if (adjacency_matrix[i][j] != 0) {
          adjacency_list.push_back({i, j});
        }
      }
    }
  }

  // Print adjacency matrix for debugging
  void printAdjacencyMatrix() {
    for (const auto &row : adjacency_matrix) {
      for (const auto &cell : row) {
        std::cout << cell << " ";
      }
      std::cout << std::endl;
    }
  }

  // Print adjacency list for debugging
  void printAdjacencyList() {
    for (const auto &edge : adjacency_list) {
      std::cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    std::cout << std::endl;
  }
};
#endif
