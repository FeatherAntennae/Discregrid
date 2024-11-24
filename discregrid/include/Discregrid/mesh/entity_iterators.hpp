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
        using iterator_category = std::random_access_iterator_tag;
        /// The type "pointed to" by the iterator.
        using value_type = std::array<unsigned int, 3>;
        /// Distance between iterators is represented as this type.
        using difference_type = ptrdiff_t;
        /// This type represents a pointer-to-value_type.
        using pointer = std::array<unsigned int, 3>*;
        /// This type represents a reference-to-value_type.
        using reference = std::array<unsigned int, 3>&;
        // -----------------------------------------------

        using T = FaceIterator;

        FaceIterator() = delete;

        reference operator*();

        bool operator==(T const& other) const { return m_index == other.m_index; }
        bool operator!=(T const& other) const { return !(*this == other); }
        auto operator<=>(const T& other) const { return m_index <=> other.m_index; }

        inline T& operator++() { ++m_index; return *this; }
        inline T& operator--()  { --m_index; return *this; }

        inline T operator+(T const& rhs) const { return T(m_index + rhs.m_index, m_mesh); }
        inline difference_type operator-(T const& rhs) const { return m_index - rhs.m_index;  }
        inline T operator-(int const& rhs) const { return T(m_index - rhs, m_mesh);  }

        unsigned int vertex(unsigned int i) const;
        unsigned int& vertex(unsigned int i);

    private:
        friend class FaceContainer;
        FaceIterator(unsigned int index, TriangleMesh* mesh):  m_index(index), m_mesh(mesh) {}

        unsigned int m_index;
        TriangleMesh* m_mesh;
    };

    class FaceConstIterator {
    public:
        // ITERATOR TRAITS -------------------------------
        /// One of the @link iterator_tags tag types@endlink.
        using iterator_category = std::random_access_iterator_tag;
        /// The type "pointed to" by the iterator.
        using value_type = std::array<unsigned int, 3> const;
        /// Distance between iterators is represented as this type.
        using difference_type = ptrdiff_t;
        /// This type represents a pointer-to-value_type.
        using pointer = std::array<unsigned int, 3> const*;
        /// This type represents a reference-to-value_type.
        using reference = std::array<unsigned int, 3> const&;
        // -----------------------------------------------

        using T = FaceConstIterator;

        FaceConstIterator() = delete;

        reference operator*();

        bool operator==(T const& other) const { return m_index == other.m_index; }
        bool operator!=(T const& other) const { return !(*this == other); }
        auto operator<=>(const T& other) const { return m_index <=> other.m_index; }

        inline T& operator++()  { ++m_index;  return *this; }
        inline T& operator--() { --m_index; return *this; }

        inline T operator+(T const& rhs) const { return T(m_index + rhs.m_index, m_mesh);  }
        inline difference_type operator-(T const& rhs) const  { return m_index - rhs.m_index; }
        inline T operator-(int const& rhs) const  { return T(m_index - rhs, m_mesh);   }

        unsigned int vertex(unsigned int i) const;
        unsigned int& vertex(unsigned int i);

    private:
        friend class FaceConstContainer;
        FaceConstIterator(unsigned int index, TriangleMesh const* mesh): m_index(index), m_mesh(mesh) {}

        unsigned int m_index;
        TriangleMesh const* m_mesh;
    };

    class IncidentFaceContainer;
    class IncidentFaceIterator {
    public:
        // ITERATOR TRAITS -------------------------------
        /// One of the @link iterator_tags tag types@endlink.
        using iterator_category = std::forward_iterator_tag;
        /// The type "pointed to" by the iterator.
        using value_type = Halfedge;
        /// Distance between iterators is represented as this type.
        using difference_type = ptrdiff_t;
        /// This type represents a pointer-to-value_type.
        using pointer = Halfedge*;
        /// This type represents a reference-to-value_type.
        using reference = Halfedge&;
        // -----------------------------------------------

        using T = IncidentFaceIterator;

        value_type operator*() { return m_h; }
        T& operator++();
        bool operator==(T const& other) const { return m_h == other.m_h; }
        bool operator!=(T const& other) const { return !(*this == other); }

    private:
        friend class IncidentFaceContainer;
        IncidentFaceIterator(unsigned int v, TriangleMesh const* mesh);
        IncidentFaceIterator(): m_h(), m_begin(),  m_mesh(nullptr) {}

        Halfedge m_h, m_begin;
        TriangleMesh const* m_mesh;
    };

    class VertexContainer;
    class VertexIterator {
    public:
        // ITERATOR TRAITS -------------------------------
        /// One of the @link iterator_tags tag types@endlink.
        using iterator_category = std::random_access_iterator_tag;
        /// The type "pointed to" by the iterator.
        using value_type = Eigen::Vector3d;
        /// Distance between iterators is represented as this type.
        using difference_type = ptrdiff_t;
        /// This type represents a pointer-to-value_type.
        using pointer = Eigen::Vector3d*;
        /// This type represents a reference-to-value_type.
        using reference = Eigen::Vector3d&;
        // -----------------------------------------------

        using T = VertexIterator;

        VertexIterator() = delete;

        reference operator*();

        bool operator==(T const& other) const { return m_index == other.m_index; }
        bool operator!=(T const& other) const { return !(*this == other); }
        auto operator<=>(const T& other) const { return m_index <=> other.m_index; }

        inline T& operator++() { ++m_index; return *this; }
        inline T& operator--() { --m_index; return *this;  }

        inline T operator+(T const& rhs) const { return T(m_index + rhs.m_index, m_mesh); }
        inline difference_type operator-(T const& rhs) const { return m_index - rhs.m_index; }
        inline T operator-(int const& rhs) const { return T(m_index - rhs, m_mesh); }

        unsigned int index() const;

    private:
        friend class VertexContainer;
        VertexIterator(unsigned int index, TriangleMesh* mesh): m_index(index), m_mesh(mesh) {}

        unsigned int m_index;
        TriangleMesh* m_mesh;
    };

    class VertexConstContainer;
    class VertexConstIterator {
    public:
        // ITERATOR TRAITS -------------------------------
        /// One of the @link iterator_tags tag types@endlink.
        using iterator_category = std::random_access_iterator_tag;
        /// The type "pointed to" by the iterator.
        using value_type = Eigen::Vector3d const;
        /// Distance between iterators is represented as this type.
        using difference_type = ptrdiff_t;
        /// This type represents a pointer-to-value_type.
        using pointer = Eigen::Vector3d const*;
        /// This type represents a reference-to-value_type.
        using reference = Eigen::Vector3d const&;
        // -----------------------------------------------

        using T = VertexConstIterator;

        VertexConstIterator() = delete;

        reference operator*();

        bool operator==(T const& other) const { return m_index == other.m_index; }
        bool operator!=(T const& other) const { return !(*this == other); }
        auto operator<=>(const T& other) const { return m_index <=> other.m_index; }

        inline T& operator++() { ++m_index; return *this; }
        inline T& operator--() { --m_index; return *this; }

        inline T operator+(T const& rhs) const { return T(m_index + rhs.m_index, m_mesh); }
        inline difference_type operator-(T const& rhs) const { return m_index - rhs.m_index; }
        inline T operator-(int const& rhs) const { return T(m_index - rhs, m_mesh); }

        unsigned int index() const;

    private:
        friend class VertexConstContainer;
        VertexConstIterator(unsigned int index, TriangleMesh const* mesh): m_index(index), m_mesh(mesh) {}

        unsigned int m_index;
        TriangleMesh const* m_mesh;
    };
} // namespace Discregrid
