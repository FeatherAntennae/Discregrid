#pragma once

#include "halfedge.hpp"

#include <Eigen/Core>
#include <array>
#include <iterator>

namespace Discregrid {

class TriangleMesh;

class FaceContainer;
class FaceIterator {
public:
  // ITERATOR TRAITS -------------------------------
  /// One of the @link iterator_tags tag types@endlink.
  typedef std::random_access_iterator_tag iterator_category;
  /// The type "pointed to" by the iterator.
  typedef std::array<unsigned int, 3> value_type;
  /// Distance between iterators is represented as this type.
  typedef ptrdiff_t difference_type;
  /// This type represents a pointer-to-value_type.
  typedef std::array<unsigned int, 3> *pointer;
  /// This type represents a reference-to-value_type.
  typedef std::array<unsigned int, 3> &reference;
  // -----------------------------------------------

  typedef FaceIterator _Mytype;

  FaceIterator() = delete;

  reference operator*();

  auto operator<=>(const _Mytype &other) const { return m_index <=> other.m_index; }

  inline _Mytype &operator++() {
    ++m_index;
    return *this;
  }
  inline _Mytype &operator--() {
    --m_index;
    return *this;
  }

  inline _Mytype operator+(_Mytype const &rhs) {
    return _Mytype(m_index + rhs.m_index, m_mesh);
  }
  inline difference_type operator-(_Mytype const &rhs) {
    return m_index - rhs.m_index;
  }
  inline _Mytype operator-(int const &rhs) {
    return _Mytype(m_index - rhs, m_mesh);
  }

  unsigned int vertex(unsigned int i) const;
  unsigned int &vertex(unsigned int i);

private:
  friend class FaceContainer;
  FaceIterator(unsigned int index, TriangleMesh *mesh)
      : m_index(index), m_mesh(mesh) {}

  unsigned int m_index;
  TriangleMesh *m_mesh;
};

class FaceConstIterator {
public:
  // ITERATOR TRAITS -------------------------------
  /// One of the @link iterator_tags tag types@endlink.
  typedef std::random_access_iterator_tag iterator_category;
  /// The type "pointed to" by the iterator.
  typedef std::array<unsigned int, 3> const value_type;
  /// Distance between iterators is represented as this type.
  typedef ptrdiff_t difference_type;
  /// This type represents a pointer-to-value_type.
  typedef std::array<unsigned int, 3> const *pointer;
  /// This type represents a reference-to-value_type.
  typedef std::array<unsigned int, 3> const &reference;
  // -----------------------------------------------

  typedef FaceConstIterator _Mytype;

  FaceConstIterator() = delete;

  reference operator*();

  auto operator<=>(const _Mytype &other) const { return m_index <=> other.m_index; }

  inline _Mytype &operator++() {
    ++m_index;
    return *this;
  }
  inline _Mytype &operator--() {
    --m_index;
    return *this;
  }

  inline _Mytype operator+(_Mytype const &rhs) const {
    return _Mytype(m_index + rhs.m_index, m_mesh);
  }
  inline difference_type operator-(_Mytype const &rhs) const {
    return m_index - rhs.m_index;
  }
  inline _Mytype operator-(int const &rhs) const {
    return _Mytype(m_index - rhs, m_mesh);
  }

  unsigned int vertex(unsigned int i) const;
  unsigned int &vertex(unsigned int i);

private:
  friend class FaceConstContainer;
  FaceConstIterator(unsigned int index, TriangleMesh const *mesh)
      : m_index(index), m_mesh(mesh) {}

  unsigned int m_index;
  TriangleMesh const *m_mesh;
};

class IncidentFaceContainer;
class IncidentFaceIterator {

public:
  // ITERATOR TRAITS -------------------------------
  /// One of the @link iterator_tags tag types@endlink.
  typedef std::forward_iterator_tag iterator_category;
  /// The type "pointed to" by the iterator.
  typedef Halfedge value_type;
  /// Distance between iterators is represented as this type.
  typedef ptrdiff_t difference_type;
  /// This type represents a pointer-to-value_type.
  typedef Halfedge *pointer;
  /// This type represents a reference-to-value_type.
  typedef Halfedge &reference;
  // -----------------------------------------------

  typedef IncidentFaceIterator _Mytype;

  value_type operator*() { return m_h; }
  _Mytype &operator++();
  bool operator==(_Mytype const &other) const { return m_h == other.m_h; }

  bool operator!=(_Mytype const &other) const { return !(*this == other); }

private:
  friend class IncidentFaceContainer;
  IncidentFaceIterator(unsigned int v, TriangleMesh const *mesh);
  IncidentFaceIterator() : m_h(), m_begin(), m_mesh(nullptr) {}

  Halfedge m_h, m_begin;
  TriangleMesh const *m_mesh;
};

class VertexContainer;
class VertexIterator {

public:
  // ITERATOR TRAITS -------------------------------
  /// One of the @link iterator_tags tag types@endlink.
  typedef std::random_access_iterator_tag iterator_category;
  /// The type "pointed to" by the iterator.
  typedef Eigen::Vector3d value_type;
  /// Distance between iterators is represented as this type.
  typedef ptrdiff_t difference_type;
  /// This type represents a pointer-to-value_type.
  typedef Eigen::Vector3d *pointer;
  /// This type represents a reference-to-value_type.
  typedef Eigen::Vector3d &reference;
  // -----------------------------------------------

  typedef VertexIterator _Mytype;

  VertexIterator() = delete;

  reference operator*();

  auto operator<=>(const _Mytype &other) const { return m_index <=> other.m_index; }

  inline _Mytype &operator++() {
    ++m_index;
    return *this;
  }
  inline _Mytype &operator--() {
    --m_index;
    return *this;
  }

  inline _Mytype operator+(_Mytype const &rhs) const {
    return _Mytype(m_index + rhs.m_index, m_mesh);
  }
  inline difference_type operator-(_Mytype const &rhs) const {
    return m_index - rhs.m_index;
  }
  inline _Mytype operator-(int const &rhs) const {
    return _Mytype(m_index - rhs, m_mesh);
  }

  unsigned int index() const;

private:
  friend class VertexContainer;
  VertexIterator(unsigned int index, TriangleMesh *mesh)
      : m_index(index), m_mesh(mesh) {}

  unsigned int m_index;
  TriangleMesh *m_mesh;
};

class VertexConstContainer;
class VertexConstIterator {

public:
  // ITERATOR TRAITS -------------------------------
  /// One of the @link iterator_tags tag types@endlink.
  typedef std::random_access_iterator_tag iterator_category;
  /// The type "pointed to" by the iterator.
  typedef Eigen::Vector3d const value_type;
  /// Distance between iterators is represented as this type.
  typedef ptrdiff_t difference_type;
  /// This type represents a pointer-to-value_type.
  typedef Eigen::Vector3d const *pointer;
  /// This type represents a reference-to-value_type.
  typedef Eigen::Vector3d const &reference;
  // -----------------------------------------------

  typedef VertexConstIterator _Mytype;

  VertexConstIterator() = delete;

  reference operator*();

  auto operator<=>(const _Mytype &other) const { return m_index <=> other.m_index; }

  inline _Mytype &operator++() {
    ++m_index;
    return *this;
  }
  inline _Mytype &operator--() {
    --m_index;
    return *this;
  }

  inline _Mytype operator+(_Mytype const &rhs) const {
    return _Mytype(m_index + rhs.m_index, m_mesh);
  }
  inline difference_type operator-(_Mytype const &rhs) const {
    return m_index - rhs.m_index;
  }
  inline _Mytype operator-(int const &rhs) const {
    return _Mytype(m_index - rhs, m_mesh);
  }

  unsigned int index() const;

private:
  friend class VertexConstContainer;
  VertexConstIterator(unsigned int index, TriangleMesh const *mesh)
      : m_index(index), m_mesh(mesh) {}

  unsigned int m_index;
  TriangleMesh const *m_mesh;
};
} // namespace Discregrid
